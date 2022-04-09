#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Constans.h"
#include "Structure.h"
#include "Functions.h"


void addToList(ListElement*& head, Contest* contest)
{
    ListElement* newEmelent = new ListElement;
    newEmelent->contest = contest;
    newEmelent->next = head;
    head = newEmelent;
}

void addToSkierList(SkierList* list, Skier* skier)
{
    if (list->head == NULL || list->tail == NULL)
    {
        skier->next = NULL;
        skier->prev = NULL;

        list->head = skier;
        list->tail = skier;
    }
    else
    {
        skier->next = NULL;
        skier->prev = list->tail;

        list->tail->next = skier;
        list->tail = skier;
    }
}

Contest* findByPlace(ListElement* head, std::string place)
{
    while (head && head->contest)
    {
        if (head->contest->place == place)
        {
            return head->contest;
        }
        head = head->next;
    }
    return NULL;
}

Skier* findByName(SkierList* list, std::string name)
{
    if (list)
    {
        Skier* skier = list->head;

        while (skier)
        {
            if (skier->name == name)
            {
                return skier;
            }
            skier = skier->next;
        }
    }
    return NULL;
}


ListElement* buildNameList(ListElement* head, std::string name)
{
    ListElement* sezon = new ListElement;
    sezon = NULL;

    SkierList skierL = head->contest->skierList;

    Contest* rContest = NULL;
    Contest* contest = NULL;
    Skier* skier = NULL;
    Skier* rSkier = NULL;

    while (head)
    {
        contest = head->contest;
        if (contest)
        {
            skierL = contest->skierList;
            rSkier = findByName(&skierL, name);

                if (rSkier != NULL)
                {
                    rContest = new Contest;
                    rContest->skierList.head = NULL;
                    rContest->skierList.tail = NULL;
                    skier = new Skier;
                    skier->name = rSkier->name;
                    skier->country = rSkier->country;
                    skier->result = rSkier->result;
                    skier->points =rSkier->points;
                    rContest->date = head->contest->date;
                    rContest->place = head->contest->place;
                    addToSkierList(&rContest->skierList, skier);
                    
                    addToList(sezon, rContest);
                }

        }
        head = head->next;
    }
    return sezon;
}


void sortByDate(ListElement*& head)
{
    bool isNotSorted = true;

    while (isNotSorted)
    {
        isNotSorted = false;
        ListElement* current = head;
        ListElement* prev = NULL;

        while (current)
        {
            if (current->next) {
                ListElement* first = current;
                ListElement* second = current->next;
                ListElement* third = second->next;

                if (dateToNumber(&first->contest->date) > dateToNumber(&second->contest->date))
                {
                    if (prev)
                    {
                        prev->next = second;
                    }
                    else
                    {
                        head = second;
                    }
                    second->next = first;
                    first->next = third;
                    isNotSorted = true;
                }
            }
            prev = current;
            current = current->next;
        }
    }
}



void sortByResult(SkierList* skierList)
{
    Skier* current = NULL;
    Skier* head = skierList->head;
    Skier* tail = skierList->tail;
    bool isNotSorted = true;

    while (isNotSorted)
    {
        current = head;
        isNotSorted = false;

        while (current)
        {
            if (current->next) {
                Skier* first = current;
                Skier* second = current->next;

                if (first->result > second->result)
                {
                    switchSkier(first, second);

                    current = second;
                    isNotSorted = true;
                }
            }
            if (current->prev == NULL) {
                head = current;
            }
            if (current->next == NULL) {
                tail = current;
            }
            current = current->next;
        }
    }
    skierList->head = head;
    skierList->tail = tail;
}

void sortByPoints(SkierList* skierList)
{
    Skier* current = NULL;
    Skier* head = skierList->head;
    Skier* tail = skierList->tail;
    bool isNotSorted = true;

    while (isNotSorted)
    {
        current = head;
        isNotSorted = false;

        while (current)
        {
            if (current->next) {
                Skier* first = current;
                Skier* second = current->next;

                if (first->points < second->points)
                {
                    switchSkier(first, second);

                    current = second;
                    isNotSorted = true;
                }
            }
            if (current->prev == NULL) {
                head = current;
            }
            if (current->next == NULL) {
                tail = current;
            }
            current = current->next;
        }
    }
    skierList->head = head;
    skierList->tail = tail;
}

void switchSkier(Skier* first, Skier* second)
{
    Skier* third = second->next;

    if (first->prev) {
        first->prev->next = second;
    }

    second->prev = first->prev;
    second->next = first;

    first->prev = second;
    first->next = third;

    if (third) {
        third->prev = first;
    }
}

void deleteList(ListElement*& head)
{
    if (head)
    {
        ListElement* p = head->next;
        delete head;
        head = nullptr;
        deleteList(p);
    }
}

void deleteSkierList(Skier*& head)
{
    if (head)
    {
        Skier* p = head->next;
        delete head;
        head = nullptr;
        deleteSkierList(p);
    }
}

void deleteListWithSublist(ListElement*& head)
{
    if (head)
    {
        ListElement* p = head->next;
        deleteSkierList(head->contest->skierList.head);
        
        delete head->contest;
        head->contest = nullptr;

        delete head;
        head = nullptr;

        deleteListWithSublist(p);
    }
}
