//
// Created by Ioana Jercan on 2019-03-07.
//

#ifndef ASSIGNMENT3_REPOSITORY_H
#define ASSIGNMENT3_REPOSITORY_H

#endif //ASSIGNMENT3_REPOSITORY_H
#include "Entities.h"

typedef struct{
    int size;
    Item itemList[100];

}Repository;

void AddItemRepository(Repository* repository, Item item);
void DeleteItemRepository(Repository* repository, int catalogueNumber);
void UpdateItemRepository(Repository* repository, Item item);
Item* GetAllRepository(Repository* repository);

