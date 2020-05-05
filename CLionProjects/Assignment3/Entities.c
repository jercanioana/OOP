//
// Created by Ioana Jercan on 2019-03-07.

#include <stdio.h>
#include "Entities.h"
#include <string.h>


int getCatalogueNumber(Item item){
    return item.catalogueNumber;

}

void setCatalogueNumber(Item *item, int value){
    item->catalogueNumber = value;
}

void setType(Item *item, char newState[]){
    strcpy(item->type, newState);
}

void setValue(Item *item, int value){
    item->value = value;
}

void setState(Item *item, char value[]){
    strcpy(item->state, value);
}
