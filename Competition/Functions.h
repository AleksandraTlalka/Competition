#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Structure.h"

// File functions
std::string getFileName(const char** argv);
void loadFromFile(ListElement*& head, std::string fileName);
void saveToFile(ListElement* head, std::string fileName);


// List functions
void addToList(ListElement*& head, Contest* contest);
void addToSkierList(SkierList* list, Skier* skier);
Contest* findByPlace(ListElement* head, std::string place);
Skier* findByName(SkierList* list, std::string name);
void sortByResult(SkierList* skierList);
void sortByPoints(SkierList* skierList);
void sortByDate(ListElement*& head);
void switchSkier(Skier* first, Skier* second);
ListElement* buildNameList(ListElement* head, std::string name);

void deleteList(ListElement*& head);
void deleteSkierList(Skier*& head);
void deleteListWithSublist(ListElement*& head);


// User Input functions
int getIntFromUser();
std::string getStringFromUser();
void userInput(ListElement*& head);
void findAndUpdateSkier(Skier* head, int result);
void UpdateContest(Contest* contest);


// Point functions
int calculatePoints(int result);
int dateToNumber(Date* date);
SkierList* buildRankingList(ListElement* head);


// Console UI
void printMenu();
void printList(ListElement* head);
void printContest(Contest* item);
void printSkier(Skier* skier);
void chooseToEdit(Contest* contest);
void editList(ListElement* head);
void showRanking(ListElement* head);
void showScoresByPlace(ListElement* head);
void showScoresByName(ListElement* head);
void printRanking(SkierList* list);
void printRecord(Skier* skier, int number);

#endif FUNCTIONS_H