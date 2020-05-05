//
// Created by Ioana Jercan on 2019-03-13.
//


#include "Entities.h"
#ifndef ASSIGNMENT4_REPOSITORY_H
#define ASSIGNMENT4_REPOSITORY_H

#endif //ASSIGNMENT4_REPOSITORY_H
//typedef void* TElem;


typedef struct{
    Item** elements;
    int size, capacity;
    Operation** undolist;
    Operation** redolist;
    int sizeofredo;
    int sizeofundo;
    int capacityofundo;
    int capacityofredo;



}Repository;

Repository* CreateRepository(int capacity);
void resize(Repository* repository);
void DestroyRepository(Repository* repository);
void AddElement(Repository* repository, Item *elem);
void DeleteItemRepository(Repository *repository, int catalogueNumber);
void UpdateItemRepository(Repository *repository, Item *item);
Item** GetAllRepository(Repository* repository);
Item* FindByCatalogueNumber(Repository* repository, int CatalogueNumber);
void DestroyUndo(Repository* repository);
void DestroyRedo(Repository* repository);
void DeleteRedo(Repository* repository);
void ResizeRedo(Repository* repository);
void AddUndo(Repository *repository, char *operationName, Item* item);
void AddRedo(Repository *repository, char *operationName, Item* item);
void DeleteUndo(Repository* repository);
void ResizeUndo(Repository* repository);