//
// Created by Ioana Jercan on 2019-04-01.
//



#include "UI.h"
#include "Tests.h"
#include <iostream>

using namespace std;
int main()
{

    {
        vector<Chore> chores;
        vector<Chore> myList;
//        FileManager fileManager{"",chores, myList};
//        HTMLFileManager htmlFileManager{"", chores, myList};
//        CSVFileManager csvFileManager{"", chores, myList};
        Repository* repository = new Repository{};
        Service service{repository};
        UI ui{service};
        //Tests::testAll();
        ui.RunMenu();

    }


    return 0;
}