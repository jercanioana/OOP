//
// Created by Ioana Jercan on 2019-03-12.
//

//
// Created by Ioana Jercan on 2019-03-08.
//

#include "UI.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int IsItemFound(UI* ui, int CatalogueNumber){
    Item *ItemsList = ui->service.repository.itemList;
    int item, IsItemFound = 0;
    int LengthOfList = ui->service.repository.size;

    for(item = 1; item < LengthOfList; item++){
        if (getCatalogueNumber(ItemsList[item]) == CatalogueNumber) {
            IsItemFound = 1;
            printf("Item already exists.\n");
            break;
        }

    }
    return IsItemFound;

}

void AddItemUI(UI* ui, char* command){
    char arguments[10][10], Separator[10] = " ", *end;
    int numberOfArguments = 0, CatalogueNumber, value;
    char *pointer = strtok(command, Separator);
    while (pointer != NULL){
        strcpy(arguments[numberOfArguments++], pointer);
        pointer = strtok(NULL, Separator);
    }

    arguments[3][strlen(arguments[3])-1] = '\0';
    arguments[2][strlen(arguments[2])-1] = '\0';
    CatalogueNumber = (int)strtol(arguments[1], &end, 10);
    value = (int)strtol(arguments[4], &end, 10);
    if (IsItemFound(ui, CatalogueNumber) == 0) {

        AddItemService(&(ui->service), CatalogueNumber, arguments[2], arguments[3], value);

    }

}

void DeleteItemUI(UI* ui, char* command){
    char arguments[10][10], *end, Separator[10] = " ";
    int numberOfArguments = 0, CatalogueNumber;
    char *pointer = strtok(command, Separator);
    while (pointer != NULL){
        strcpy(arguments[numberOfArguments++], pointer);
        pointer = strtok(NULL, Separator);
        
    }
    CatalogueNumber =(int)strtol(arguments[1], &end, 10);
    if(IsItemFound(ui, CatalogueNumber) == 0) {
        DeleteItemService(&(ui->service), CatalogueNumber);
    }
    else
        printf("Item doesn't exist");
}

void UpdateItemUI(UI* ui, char* command){
    char arguments[10][10], *end, Separator[10] = " ";
    int numberOfArguments = 0, NewCatalogueNumber, NewValue;
    char *pointer = strtok(command, Separator);
    while (pointer != NULL){
        strcpy(arguments[numberOfArguments++], pointer);
        pointer = strtok(NULL, Separator);
    }
    arguments[3][strlen(arguments[3])-1] = '\0';
    arguments[2][strlen(arguments[2])-1] = '\0';
    NewCatalogueNumber = (int)strtol(arguments[1], &end, 10);
    NewValue = (int)strtol(arguments[4], &end, 10);
    UpdateItemService(&(ui->service), NewCatalogueNumber, arguments[2], arguments[3], NewValue);



}
void ListItemsUI(UI* ui){

    Item* Items = GetAllService(&(ui->service));
    int index;
    for (index = 1; index <= ui->service.repository.size; index++){
        if (strcmp(Items[index].state, "rotten") == 0)
            DeleteItemService(&(ui->service), Items[index].catalogueNumber);
        else
            printf("Catalogue number: %d State: %s Type: %s Value: %d\n", Items[index].catalogueNumber,
                   Items[index].state, Items[index].type, Items[index].value);
    }
}
void ListItemsByType(UI* ui, char* command){
    char arguments[10][10], Separator[10] = " ";
    int numberOfArguments = 0;
    char *pointer = strtok(command, Separator);
    while (pointer != NULL){
        strcpy(arguments[numberOfArguments++], pointer);
        pointer = strtok(NULL, Separator);
    }
    Item* Items = GetAllService(&(ui->service));
    int ListIndex;
    arguments[1][strlen(arguments[1])-1] = '\0';
    arguments[2][strlen(arguments[2])-1] = '\0';
    if(strcmp(arguments[2],"vegetables") == 0){
        for (ListIndex = 0; ListIndex <= ui->service.repository.size; ListIndex++) {
            if (strcmp(Items[ListIndex].type, "edible vegetables") == 0) {
                printf("Catalogue number: %d State: %s Type: %s Value: %d\n", Items[ListIndex].catalogueNumber,
                       Items[ListIndex].state, Items[ListIndex].type, Items[ListIndex].value);
            }
        }
    }
    else {
        for (ListIndex = 0; ListIndex <= ui->service.repository.size; ListIndex++) {
            if (strcmp(Items[ListIndex].type, arguments[1]) == 0) {
                printf("Catalogue number: %d State: %s Type: %s Value: %d\n", Items[ListIndex].catalogueNumber,
                       Items[ListIndex].state, Items[ListIndex].type, Items[ListIndex].value);
            }
        }
    }
}
void run_menu(){

    char command[20];
    Item i[1000];
    Repository repository = {
            0, *i};
    Service service = {
            repository };
    UI ui = {
            service };


    while(1){
        printf("Menu\n\n");
        printf("Add an item.\n");
        printf("Delete an item.\n");
        printf("Update an item.\n");
        printf("List all items.\n");
        printf("List all items with a certain type.\n");
        printf("Enter a command: ");
        fgets(command, 100, stdin);
        if (strcmp(command , "exit") == 0 || strcmp(command , "exit\n") == 0)
            break;

        if (command[0] == 'a')
            AddItemUI(&ui, command);
        if (command[0] == 'd')
            DeleteItemUI(&ui, command);
        if (command[0] == 'u')
            UpdateItemUI(&ui, command);
        if (command[0] == 'l') {
            if (strlen(command) == 5) {
                ListItemsUI(&ui);
            }
            else
                ListItemsByType(&ui, command);
        }

    }

}
