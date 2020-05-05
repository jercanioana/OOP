//
// Created by Ioana Jercan on 2019-03-08.
//

#ifndef ASSIGNMENT3_SERVICE_H
#define ASSIGNMENT3_SERVICE_H

#endif //ASSIGNMENT3_SERVICE_H
#include "Repository.h"
typedef struct{
    Repository repository;
}Service;

void AddItemService(Service *service, int CatalogueNumber, char state[], char type[], int value);
void DeleteItemService(Service *service, int CatalogueNumber);
void UpdateItemService(Service *service, int CatalogueNumber, char newState[], char newType[], int newValue);
Item* GetAllService(Service *service);
