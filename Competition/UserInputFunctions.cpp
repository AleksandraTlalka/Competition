#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Constans.h"
#include "Structure.h"
#include "Functions.h"

int getIntFromUser()
{
    int option;
    std::cin >> option;
    if (std::cin.good())
    {
        return option;
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(5000, '\n');
        std::cout << "Podaj wlasciwa liczbe: ";
        return getIntFromUser();
    }
};

std::string getStringFromUser()
{
    std::string option;
    std::cin >> option;
    return option;
}

void userInput(ListElement*& head)
{
    std::cout << "Podaj miejsce zawaodow: " << std::endl;
    std::string place = getStringFromUser();
    Contest* contest = NULL;
    contest = findByPlace(head, place);
    if (contest == NULL)
    {
        contest = new Contest;
        contest->skierList.head = NULL;
        contest->skierList.tail = NULL;
        addToList(head, contest);

        std::cout << "Podaj date zawaodow: " << std::endl;
        std::cout << "Dzien: ";
        contest->date.day = getIntFromUser();
        std::cout << "Miesiac: ";
        contest->date.month = getIntFromUser();
        std::cout << "Rok: ";
        contest->date.year = getIntFromUser();
        contest->place = place;
    }

    Skier* skier = new Skier;
    std::cout << "Nazwisko: ";
    skier->name = getStringFromUser();
    std::cout << "Reprezentowany kraj: ";
    skier->country = getStringFromUser();
    std::cout << "Lokata: ";
    skier->result = getIntFromUser();
    skier->points = calculatePoints(skier->result);
    addToSkierList(&contest->skierList, skier);
}

void findAndUpdateSkier(Skier* head, int number)
{
    bool complited = false;
    for (int i = 1; head; i++, head = head->next) 
    {
        if (number == i)
        {
            std::cout << "Nazwisko: ";
            head->name = getStringFromUser();
            std::cout << "Reprezentowany kraj: ";
            head->country = getStringFromUser();
            std::cout << "Lokata: ";
            head->result = getIntFromUser();
            head->points = calculatePoints(head->result);
            std::cout << std::endl;

            std::cout << "Wpisales dane: " << std::endl;
            printSkier(head);
            complited = true;
            return;
        }
    }
    if (!complited)
    {
        std::cout << "Nie ma takiej lokaty";
    }
}

void UpdateContest(Contest* contest) {
            std::cout << "Podaj nowa date zawaodow: " << std::endl;
            std::cout << "Dzien: ";
            contest->date.day = getIntFromUser();
            std::cout << "Miesiac: ";
            contest->date.month = getIntFromUser();
            std::cout << "Rok: ";
            contest->date.year = getIntFromUser();
            std::cout << "Miejsce zawodow: ";
            contest->place = getStringFromUser();
}

