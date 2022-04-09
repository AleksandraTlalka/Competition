#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#include "Constans.h"
#include "Structure.h"
#include "Functions.h"

void printMenu()
{
    std::cout << std::endl << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Jaka akcje wykonac?" << std::endl;
    std::cout << "1.wypisac dane" << std::endl;
    std::cout << "2.dodac dane" << std::endl;
    std::cout << "3.edytowac istniejace dane" << std::endl;
    std::cout << "4.wyswietlic aktualny ranking zawodnikow" << std::endl;
    std::cout << "5.wyswietlic wyniki wybranego konkursu" << std::endl;
    std::cout << "6.wyswietlic wyniki narciarza w sezonie" << std::endl;
    std::cout << "7.zakonczyc dzialanie programu" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
};

void printList(ListElement* head)
{
    std::cout << " Lp              Data\t\tMiejsce\t\tNazwisko\t\tKraj\t\tLokata\t\tPunkty\n";
    while (head)
    {
        if (head->contest)
        {
            printContest(head->contest);
            std::cout << std::endl;
        }
        head = head->next;
    }
}

void printContest(Contest* contest)
{
    Skier* skier = contest->skierList.head;

    for (int number = 1; skier; skier = skier->next, number++)
    {
        std::cout << std::setw(3) << number;
        std::cout << std::setw(10) << contest->date.day << DATE_SEP;
        std::cout << std::setw(2) << contest->date.month << DATE_SEP;
        std::cout << std::setw(4) << contest->date.year;
        std::cout << std::setw(15) << contest->place;
        printSkier(skier);
    }
}

void printSkier(Skier* skier)
{
        std::cout << std::setw(15) << skier->name;
        std::cout << std::setw(15) << skier->country;
        std::cout << std::setw(15) << skier->result;
        std::cout << std::setw(15) << skier->points << std::endl;
}

void chooseToEdit(Contest* contest) {
    std::cout << std::endl;
    std::cout << "Wybierz dane, ktore chcesz zmienic:" << std::endl; 
    std::cout << "1.Miejsce lub date konkursu" << std::endl;
    std::cout << "2.Dane zawodnika" << std::endl;
    int choose = getIntFromUser();
    switch(choose) {
    case 1:{
        UpdateContest(contest);
        break;
    }
    case 2:{
        std::cout << "Podaj numer wiersza zawodnika do edycji: " << std::endl;
        int number = getIntFromUser();
        findAndUpdateSkier(contest->skierList.head, number);
        break;
    }
    default: {
        chooseToEdit(contest);
    }}
}
void editList(ListElement* head)
{
    std::cout << "Reczna edycja danych: ";
    printList(head);

    std::cout << "Podaj miejsce konkursu: ";
    std::string place = getStringFromUser();
    Contest* contest = findByPlace(head, place);
    printContest(contest);
    chooseToEdit(contest);
}

void showScoresByName(ListElement* head) {
    std::cout << "Wyswietlanie wynikow narciarza w sezonie: " << std::endl;
    std::cout << "Podaj nazwisko narciarza: ";
    std::string name = getStringFromUser();
    ListElement* filtered = buildNameList(head, name);
    sortByDate(filtered);
    printList(filtered);
    deleteListWithSublist(filtered);
}

void showScoresByPlace(ListElement* head) {
    std::cout << "Wyswietlanie wynikow wybranego konkursu: " << std::endl;
    std::cout << "Podaj miejsce konkursu: ";
    std::string place = getStringFromUser();
    Contest* contest = findByPlace(head, place);
    sortByResult(&contest->skierList);
    printContest(contest);
}

void showRanking(ListElement* head) {
    std::cout << "Wyswietlanie rankingu: " << std::endl;
    SkierList* ranked = buildRankingList(head);
    sortByPoints(ranked);
    printRanking(ranked);
    deleteSkierList(ranked->head);

    delete ranked;
    ranked = nullptr;
}

void printRanking(SkierList* list)
{
    std::cout << "Lp\t\tNazwisko\t\tKraj\t\tPunkty\n";
    Skier* head = list->head;
    int number = 1;
    while (head)
    {
        printRecord(head, number++);
        head = head->next;
    }
}

void printRecord(Skier* skier, int number)
{
    std::cout << number << ITEM_SEP;
    std::cout << skier->name << ITEM_SEP;
    std::cout << skier->country << ITEM_SEP;
    std::cout << skier->points << std::endl;
}

