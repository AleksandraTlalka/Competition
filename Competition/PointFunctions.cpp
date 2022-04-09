#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Constans.h"
#include "Structure.h"
#include "Functions.h"


int dateToNumber(Date* date)
{
    return (date->year * 10000 + date->month * 100 + date->day);
}

int calculatePoints(int result)
{
    if (result == 1) return  100;
    if (result == 2) return  80;
    if (result == 3) return  60;
    if (result == 4) return  50;
    if (result == 5) return  45;
    if (result == 6) return  40;
    if (result == 7) return  36;
    if (result == 8) return  32;
    if (result == 9) return  29;
    if (result == 10) return  26;
    if (result == 11) return  24;
    if (result == 12) return  22;
    if (result == 13) return  20;
    if (result == 14) return  18;
    if (result == 15) return  16;
    if (result == 16) return  15;
    if (result == 17) return  14;
    if (result == 18) return  13;
    if (result == 19) return  12;
    if (result == 20) return  11;
    if (result == 21) return  10;
    if (result == 22) return  9;
    if (result == 23) return  8;
    if (result == 24) return  7;
    if (result == 25) return  6;
    if (result == 26) return  5;
    if (result == 27) return  4;
    if (result == 28) return  3;
    if (result == 29) return  2;
    if (result == 30) return  1;
    return  0;
}

SkierList* buildRankingList(ListElement* head)
{
    SkierList* ranking = new SkierList;
    ranking->head = NULL;
    ranking->tail = NULL;

    Contest* contest = NULL;
    Skier* skier = NULL;
    Skier* rSkier = NULL;

    while (head)
    {
        contest = head->contest;
        if (contest)
        {
            skier = contest->skierList.head;

            while (skier) {
                rSkier = findByName(ranking, skier->name);

                if (rSkier)
                {
                    rSkier->points += skier->points;
                }
                else
                {
                    rSkier = new Skier;
                    rSkier->name = skier->name;
                    rSkier->country = skier->country;
                    rSkier->result = skier->result;
                    rSkier->points = skier->points;
                    addToSkierList(ranking, rSkier);
                }
                skier = skier->next;
            }
        }
        head = head->next;
    }
    return ranking;
}


