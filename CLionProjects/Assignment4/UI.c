//
// Created by Ioana Jercan on 2019-03-14.
//


#include "UI.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int IsItemFound(UI* ui, int CatalogueNumber){
    Item **ItemsList = ui->service.repository->elements;
    int item, IsItemFound = 0;
    int LengthOfList = ui->service.repository->size;

    for(item = 0; item < LengthOfList; item++){

        if (getCatalogueNumber(ItemsList[item]) == CatalogueNumber) {
            IsItemFound = 1;
            break;
        }

    }
    return IsItemFound;

}
void ListMaximumPotency(UI* ui, char* command){
    Item **ItemsList = GetAllService(&ui->service);

    int index, numberOfArguments = 0;
    int LengthOfList = ui->service.repository->size;
    char arguments[10][10], *end, Separator[10] = " ";
    char *pointer = strtok(command, Separator);
    while (pointer != NULL){
        strcpy(arguments[numberOfArguments++], pointer);
        pointer = strtok(NULL, Separator);
    }
    int value = (int)strtol(arguments[1], &end, 10);
    for(index = 0; index < LengthOfList; index++){

        if(getValue(ItemsList[index]) <= value){
            printf("Catalogue number: %d State: %s Type: %s Value: %d\n", ItemsList[index]->catalogueNumber,
                   ItemsList[index]->state, ItemsList[index]->type, ItemsList[index]->value);
        }

    }
}
void undo(UI* ui){
    undoService(&ui->service);


}
void redo(UI* ui){
    redoService(&ui->service);


}
void AddItemUI(UI* ui, char* command){
    char arguments[10][10], Separator[10] = " ", *end;
    int numberOfArguments = 0, CatalogueNumber, value;
    Item* newItem;
    char *pointer = strtok(command, Separator);
    while (pointer != NULL){
        strcpy(arguments[numberOfArguments++], pointer);
        pointer = strtok(NULL, Separator);
    }
    arguments[3][strlen(arguments[3])-1] = '\0';
    arguments[2][strlen(arguments[2])-1] = '\0';
    CatalogueNumber = (int)strtol(arguments[1], &end, 10);
    value = (int)strtol(arguments[4], &end, 10);
    newItem = CreateItem(CatalogueNumber, arguments[2], arguments[3], value);
    if (IsItemFound(ui, CatalogueNumber) == 0) {
        AddItemService((&ui->service), CatalogueNumber, arguments[2], arguments[3], value);

    }
    else
        printf("Item already exists");
    destroyItem(newItem);

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
    if(IsItemFound(ui, CatalogueNumber) == 1) {
        {
            DeleteItemService((&ui->service), CatalogueNumber);
        }
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
    if(IsItemFound(ui, NewCatalogueNumber) == 1) {
        {
            UpdateItemService((&ui->service), NewCatalogueNumber, arguments[2], arguments[3], NewValue);

        }
    }
    else
        printf("Item doesn't exist");




}
void ListItemsUI(UI* ui){
    Item** Items = GetAllService((&ui->service));
    int index;

    int LengthOfList = ui->service.repository->size;
    for (index = 0; index < LengthOfList; index++){
            printf("Catalogue number: %d State: %s Type: %s Value: %d\n", Items[index]->catalogueNumber,
                   Items[index]->state, Items[index]->type, Items[index]->value);
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
    Item ** Items = ui->service.repository->elements;
    int LengthOfList = ui->service.repository->size;
    int ListIndex;
    arguments[1][strlen(arguments[1])-1] = '\0';
    arguments[2][strlen(arguments[2])-1] = '\0';
    if(strcmp(arguments[2],"vegetables") == 0){
        for (ListIndex = 0; ListIndex < LengthOfList; ListIndex++) {
            if (strcmp(getType(Items[ListIndex]), "edible vegetables") == 0) {
                printf("Catalogue number: %d State: %s Type: %s Value: %d\n", Items[ListIndex]->catalogueNumber,
                       Items[ListIndex]->state, Items[ListIndex]->type, Items[ListIndex]->value);
            }
        }
    }
    else {
        for (ListIndex = 0; ListIndex < LengthOfList; ListIndex++) {
            if (strcmp(getType(Items[ListIndex]), arguments[1]) == 0) {
                printf("Catalogue number: %d State: %s Type: %s Value: %d\n", Items[ListIndex]->catalogueNumber,
                       Items[ListIndex]->state, Items[ListIndex]->type, Items[ListIndex]->value);
            }
        }
    }
}


void run_menu(UI* ui) {

    char command[20];





    while (1) {
        printf("Menu\n\n");
        printf("Add an item.\n");
        printf("Delete an item.\n");
        printf("Update an item.\n");
        printf("List all items.\n");
        printf("List all items with a certain type.\n");
        printf("Enter a command: ");
        fgets(command, 100, stdin);
        if (strcmp(command, "exit") == 0 || strcmp(command, "exit\n") == 0) {
            DestroyRepository(ui->service.repository);
            break;

        }

        if (command[0] == 'a')
            AddItemUI(ui, command);
        if (command[0] == 'd')
            DeleteItemUI(ui, command);
        if (command[0] == 'u' && command[1] == 'p')
            UpdateItemUI(ui, command);
        if (command[0] == 'l') {
            if(strlen(command) == 5) {
                ListItemsUI(ui);
            }
            else
                ListMaximumPotency(ui, command);

        }
        if (command[0] == 'u' && command[1] == 'n')
            undo(ui);
        if(command[0] == 'r')
            redo(ui);






    }
}
