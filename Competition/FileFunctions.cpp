#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Constans.h"
#include "Structure.h"
#include "Functions.h"


std::string getFileName(const char** argv) {
    if (argv[1])
        return argv[1];
    else
        return DEF_FILE_NAME;
}

void loadFromFile(ListElement*& head, std::string fileName)
{
    std::fstream file(fileName);
    if (file)
    {
        Contest* pContest = NULL;
        Skier* pSkier = NULL;
        std::cout << "Loading";

        while (not file.eof())
        {
            std::string space;
            std::cout << ".";

            for (int licznik = 1; licznik < 9; licznik++) {

                if (licznik < 2)
                    std::getline(file, space, ',');
                else if (licznik < 4)
                    std::getline(file, space, '.');
                else if (licznik < 8)
                    std::getline(file, space, ',');
                else
                    std::getline(file, space);

                switch (licznik)
                {
                    case 1:
                    {
                        pContest = findByPlace(head, space);
                        if (pContest == NULL)
                        {
                            pContest = new Contest;
                            pContest->place = space;
                            pContest->skierList.head = NULL;
                            pContest->skierList.tail = NULL;                          
                            addToList(head, pContest);
                        }
                        break;
                    }
                    case 2:
                    {
                        pContest->date.day = atoi(space.c_str());
                        break;
                    }
                    case 3:
                    {
                        pContest->date.month = atoi(space.c_str());
                        break;
                    }
                    case 4:
                    {
                        pContest->date.year = atoi(space.c_str());
                        break;
                    }
                    case 5:
                    {
                        pSkier = new Skier;
                        pSkier->name = space;
                        addToSkierList(&pContest->skierList, pSkier);
                        break;
                    }
                    case 6:
                    {
                        pSkier->country = space;
                        break;
                    }
                    case 7:
                    {
                        pSkier->result = atoi(space.c_str());
                        break;
                    }
                    case 8:
                    {
                        pSkier->points = atoi(space.c_str());
                        break;
                    }
                }
            }
        }
        file.close();
    }
    else
    {
        std::cout << "\nBrak pliku lub niewlasciwy plik.\n";
    }
}

void saveToFile(ListElement* head, std::string fileName)
{
    std::fstream file(fileName);
    Skier* skier = NULL;

    if (file)
    {
        while (head && head->contest)
        {
            skier = head->contest->skierList.head;

            while (skier) {
                file << head->contest->place << COMA_SEP;
                file << head->contest->date.day << DATE_SEP;
                file << head->contest->date.month << DATE_SEP;
                file << head->contest->date.year << COMA_SEP;
                file << skier->name << COMA_SEP;
                file << skier->country << COMA_SEP;
                file << skier->result << COMA_SEP;

                if (head->next || skier->next)
                    file << skier->points << COMA_SEP << std::endl;
                else
                    file << skier->points << COMA_SEP;

                skier = skier->next;
            }
            head = head->next;
        }
    }
    file.close();
}
