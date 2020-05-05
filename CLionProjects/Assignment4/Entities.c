//
// Created by Ioana Jercan on 2019-03-13.
//

#include "Entities.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Item* CreateItem(int CatalogueNumber, char* state, char* type, int value){
    Item* item = (Item*)malloc(sizeof(Item));
    item->catalogueNumber = CatalogueNumber;
    item->state = (char*)malloc(sizeof(char) * (strlen(state) + 1));
    strcpy(item->state, state);
    item->type = (char*)malloc(sizeof(char)* (strlen(type) + 1));
    strcpy (item->type, type);
    item->value = value;

    return item;


}

void destroyItem(Item* item){
    if(item == NULL){
        return;
    }
    free(item->state);
    free(item->type);
    free(item);

}

Operation* createoperation(Item* item, char* name)
{
    Operation* operation = (Operation*)malloc(sizeof(Operation));
    operation->operation_name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(operation->operation_name, name);
    operation->item = item;
    return operation;
}

void destroyoperation(Operation* operation)
{
    destroyItem(operation->item);
    free(operation->operation_name);
    free(operation);
}

Item* copyItem(Item* item){
    Item* copy = (Item*)malloc(sizeof(Item));
    copy->catalogueNumber = item->catalogueNumber;
    copy->state = (char*)malloc(sizeof(char) * (strlen(item->state)+1));
    strcpy(copy-> state, item->state);
    copy->type = (char*)malloc(sizeof(char) * (strlen(item->type)+1));
    strcpy (copy->type, item->type);
    copy->value = item->value;
    return copy;
}

int getCatalogueNumber(Item* item){
    return item->catalogueNumber;

}
int getValue(Item* item){
    return item->value;
}
char* getType(Item *item){
    return item->type;
}



