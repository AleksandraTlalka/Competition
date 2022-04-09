#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>

/**
 * Stuktura danych reprezentujaca date zapisan¹ w formacie dzien / miesiac / rok.
 */
struct Date
{
    int day;   ///< Dzien reprezentowany w postaci liczby calkowitej.
    int month; ///< Miesiac reprezentowany w postaci liczby calkowitej.
    int year;  ///< Rok reprezentowany w postaci liczby calkowitej.
};

struct Skier
{
    std::string name;    ///< nazwisko narciarza.
    std::string country; ///< kraj pochodzenia narciarza.
    int result;          ///< lokata zajeta przez narciarza w postaci liczby calkowitej.
    int points;          ///< punkty przypisane zajmowanej lokacjie wg zasad Pucharu Swiata w postaci liczby calkowitej.
    Skier* next;
    Skier* prev;
};

struct SkierList
{
    Skier* head;
    Skier* tail;
};

/**
 * Stuktura danych reprezentujaca pojedynczy rekord narciarza.
 */
struct Contest
{
    Date date;           ///< data zawodow reprezentowana za pomoc¹ struktury Date.
    std::string place;   ///< miejsce odbywania siê zawodow.
    SkierList skierList;
};

/**
 * Stuktura danych reprezentujaca element listy dwukierunkowej.
 */
struct ListElement
{
    Contest* contest; ///< adres Itemu w liœcie
    ListElement* next; ///< adres elementu nastêpnego
};


#endif STRUCTURE_H