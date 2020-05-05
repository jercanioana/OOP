//
// Created by Ioana Jercan on 2019-03-23.
//

#include "UI.h"
#include "FileManager.h"
#include <iostream>
#include <string>
#include <algorithm>

UI::UI(Service& OtherService): service{OtherService}{
}
void UI::Add(const std::string &command) {
    char lineOfArguments[100];
    std::string title, type, lastPerformed, vision;
    strcpy(lineOfArguments, command.c_str());
    char arguments[100][100];
    char *end;
    int numberOfArguments = 0, timesPerformed;
    char *pointerForSplitting = strtok(lineOfArguments, ",");
    while (pointerForSplitting != NULL) {
        strcpy(arguments[++numberOfArguments], pointerForSplitting);
        pointerForSplitting = strtok(NULL, ",");

        if (numberOfArguments == 1)
            strcpy(arguments[1], arguments[1] + 4);
        else if (numberOfArguments == 2 || numberOfArguments == 5)
            strcpy(arguments[numberOfArguments], arguments[numberOfArguments] + 1);
        else {
            strcpy(arguments[numberOfArguments], arguments[numberOfArguments] + 1);
        }
    }
    timesPerformed = (int)strtol(arguments[4], &end, 10);
    title.assign(arguments[1]);
    type.assign(arguments[2]);
    lastPerformed.assign(arguments[3]);
    vision.assign(arguments[5]);
    if(this->service.ExistingChore(title) == 0)
        this->service.Add(title, type, lastPerformed, timesPerformed, vision);
    else
        std::cout<<"Chore already exists."<<"\n";

}
void UI::Update(const std::string &command) {
    char lineOfArguments[100];
    std::string title, type, lastPerformed, vision;
    strcpy(lineOfArguments, command.c_str());
    char arguments[100][100];
    char *end;
    int numberOfArguments = 0, timesPerformed;
    char *pointerForSplitting = strtok(lineOfArguments, ",");
    while (pointerForSplitting != NULL) {
        strcpy(arguments[++numberOfArguments], pointerForSplitting);
        pointerForSplitting = strtok(NULL, ",");

        if (numberOfArguments == 1)
            strcpy(arguments[1], arguments[1] + 7);
        else if (numberOfArguments == 2 || numberOfArguments == 5)
            strcpy(arguments[numberOfArguments], arguments[numberOfArguments] + 1);
        else {
            strcpy(arguments[numberOfArguments], arguments[numberOfArguments] + 1);
        }
    }
    timesPerformed = (int)strtol(arguments[4], &end, 10);
    title.assign(arguments[1]);
    type.assign(arguments[2]);
    lastPerformed.assign(arguments[3]);
    vision.assign(arguments[5]);
    this->service.Update(title, type, lastPerformed, timesPerformed, vision);

}
void UI::Remove(const std::string &command){
    std::string title;
    char lineOfArguments[100];
    int numberOfArguments = 0;
    strcpy(lineOfArguments, command.c_str());
    char arguments[100][100], Separator[10] = " ";
    char *pointerForSplitting = strtok(lineOfArguments, Separator);
    while (pointerForSplitting != NULL) {
        strcpy(arguments[numberOfArguments++], pointerForSplitting);
        pointerForSplitting = strtok(NULL, Separator);

    }
    title.assign(arguments[1]);
    this->service.Remove(title);

}
void UI::Filter(const std::string &command) {
    std::string type;
    char lineOfArguments[100];
    strcpy(lineOfArguments, command.c_str());
    char arguments[100][100];
    char *end;
    int numberOfArguments = 0, timesPerformed;
    char *pointerForSplitting = strtok(lineOfArguments, ",");
    while (pointerForSplitting != NULL) {
        strcpy(arguments[++numberOfArguments], pointerForSplitting);
        pointerForSplitting = strtok(NULL, ",");
        if (numberOfArguments == 1)
            strcpy(arguments[1], arguments[1] + 5);
        else if (numberOfArguments == 2 || numberOfArguments == 3)
            strcpy(arguments[numberOfArguments], arguments[numberOfArguments] + 1);
        else {
            strcpy(arguments[numberOfArguments], arguments[numberOfArguments] + 1);
        }
    }
    if (numberOfArguments == 2) {
        type.assign(arguments[1]);
        timesPerformed = (int) strtol(arguments[2], &end, 10);
        std::vector<Chore> filteredChores = this->service.FilterByTypeAndTimesPerformed(type, timesPerformed);
        for(auto & chore : filteredChores){
            std::cout<< chore.GetTitle()<<" "<<chore.GetType()<<" "<<chore.GetLastDatePerformed()<<" "<<chore.GetTimesPerformed()<<" "<<chore.GetVision()<<'\n';
        }
    }
}

void UI::FileLocation(const std::string& command) {
    std::string newPath;
    char lineOfArguments[1000];
    strcpy(lineOfArguments, command.c_str());
    char separator[10] = " ";
    char *pointerForSplitting = strtok(lineOfArguments, separator);
    pointerForSplitting = strtok(NULL, separator);
    std::size_t position = command.find(pointerForSplitting);
    newPath = command.substr(position);
    this->service.ChangePathForTextFile(newPath);

}
void UI::List(){
    std::vector<Chore> chores = this->service.GetAll();
    for(auto & chore : chores){
        std::cout<< chore.GetTitle()<<" "<<chore.GetType()<<" "<<chore.GetLastDatePerformed()<<" "<<chore.GetTimesPerformed()<<" "<<chore.GetVision()<<'\n';
    }
}
void UI::Next(int counter){
    std::vector<Chore> chores = this->service.GetAll();
    Chore chore = chores[counter];
    std::cout<<chore.GetTitle()<<" "<<chore.GetType()<<" "<<chore.GetLastDatePerformed()<<" "<<chore.GetTimesPerformed()<<" "<<chore.GetVision()<<'\n';
}
void UI::Save(const std::string &command){
    std::string title;
    char lineOfArguments[100];
    int numberOfArguments = 0;
    strcpy(lineOfArguments, command.c_str());
    char arguments[100][100], separator[10] = " ";
    char *pointerForSplitting = strtok(lineOfArguments, separator);
    while (pointerForSplitting != NULL) {
        strcpy(arguments[numberOfArguments++], pointerForSplitting);
        pointerForSplitting = strtok(NULL, separator);

    }
    title.assign(arguments[1]);
    this->service.SaveChore(title);

}

void UI::MyList() {
    std::vector<Chore> myList = this->service.GetMyList();
    std::string filePath;
    filePath = this->service.GetPathCSV();
    if(!filePath.empty()){
        std::string tempstring = "notepad.exe " + filePath;
        system(tempstring.c_str());
    }
    filePath = this->service.GetPathHTML();
    if(!filePath.empty()) {

        if (filePath.find("//") > filePath.size()) {
            std::string tempstring = "start iexplore " + filePath;
            system(tempstring.c_str());
        } else {
            std::string tempstring = "start iexplore " + filePath;
            system(tempstring.c_str());
        }
    }

    for(auto & iterator : myList){
        std::cout<< iterator.GetTitle()<<" "<<iterator.GetType()<<" "<<iterator.GetLastDatePerformed()<<" "<<iterator.GetTimesPerformed()<<" "<<iterator.GetVision()<<'\n';
    }

}

void UI::MyListFileLocation(const std::string &command) {
    std::string newPath;
    char lineOfArguments[1000];
    strcpy(lineOfArguments, command.c_str());
    char separator[10] = " ";
    char *pointerForSplitting = strtok(lineOfArguments, separator);
    pointerForSplitting = strtok(NULL, separator);
    std::size_t position = command.find(pointerForSplitting);
    newPath = command.substr(position);
    int positionForPoint;
    positionForPoint = newPath.find(".");
    if(newPath[positionForPoint+1] == 'c'){
        this->service.ChangePathForCSV(newPath);
    }
    if(newPath[positionForPoint+1] == 'h') {
        this->service.ChangePathForHTML(newPath);
    }
}
UI::~UI() {

}

void UI::RunMenu() {
    std::string command;
    int counter = 0;
    char mode = 'A';
    while (1) {

        std::cout<<"Enter a command: ";
        std::getline(std::cin, command);
        if (strcmp(command.c_str(), "exit") == 0 || strcmp(command.c_str(), "exit\n") == 0) {
            break;

        }
        if (command[0] == 'm' && command[1] == 'o')
        {
            char lineOfArguments[100];
            strcpy(lineOfArguments, command.c_str());
            char* pointer = strtok(lineOfArguments, " ");
            pointer = strtok(NULL, ",");
            char modeType[10];
            strcpy(modeType, pointer);
            if (strcmp(modeType, "A") == 0)
                mode = 'A';
            else
                mode = 'B';
        }
        if (command[0] == 'a' && mode == 'A')
            this->Add(command);
        if (command[0] == 'd' && mode == 'A')
            this->Remove(command);
        if (command[0] == 'u' && mode == 'A')
            this->Update(command);
        if(command[0] == 'l' && mode == 'A' && command.length() == 4)
            this->List();
            else{
                if (command.length() > 4 && mode == 'B')
                    this->Filter(command);
            }
        if(command[0] == 'n' && mode == 'B') {
            this->Next(counter);
            counter++;
            if(counter == this->service.Size())
                counter = 0;
        }
        if (command[0] == 's' && mode == 'B')
            this->Save(command);
        if (command[0] == 'm' && command[1] == 'y' && mode == 'B' && command.length() == 6)
            this->MyList();
        else
            if(command[0] == 'm' && command[1] == 'y' && command.length() > 6)
                this->MyListFileLocation(command);
        if(command[0] == 'f')
            this->FileLocation(command);


    }
}