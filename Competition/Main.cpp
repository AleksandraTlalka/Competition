#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vld.h>


#include "Constans.h"
#include "Structure.h"
#include "Functions.h"


int main(int argc, const char** argv) {

    ListElement* head = NULL;
    std::string file = getFileName(argv);
    loadFromFile(head, file);

    std::cout << std::endl << std::endl;
    bool shouldContinue = true;

    while (shouldContinue)
    {
        printMenu();

        switch (getIntFromUser())
        {
            case 1: {
                printList(head);
                break;
            }
            case 2: {
                userInput(head);
                break;
            }
            case 3: {
                editList(head);
                break;
            }
            case 4: {
                showRanking(head);
                break;
            }
            case 5: {
                showScoresByPlace(head);
                break;
            }
            case 6: {
                showScoresByName(head);
                break;
            }
            case 7: {
                saveToFile(head, file);
                shouldContinue = false;
                break;
            }
            default: {
                std::cout << "Niepoprawne dzialanie uzytkownika" << std::endl;
            }
        }
    }
    deleteListWithSublist(head);

    _CrtDumpMemoryLeaks();
    return 0;
}