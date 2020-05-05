//
// Created by Ioana Jercan on 2019-03-13.
//
#include "Repository.h"
#include <stdio.h>
#include <stdlib.h>
Repository* CreateRepository(int capacity){
    Repository* repository = (Repository*)malloc(sizeof(Repository));
    repository->capacity = capacity;
    repository->size = 0;
    repository->elements = (Item **)malloc(sizeof(Item*) * capacity);
    repository->capacityofredo = 1;
    repository->capacityofundo = 1;
    repository->sizeofredo = 0;
    repository->sizeofundo = 0;
    repository->undolist = (Operation**)malloc(sizeof(Operation*) * repository->capacityofundo);
    repository->redolist = (Operation**)malloc(sizeof(Operation*) * repository->capacityofredo);



    return repository;
}
void DestroyRepository(Repository* repository){
    if (repository != NULL)
    {
        for (int index = 0; index < repository->size; index++)
            destroyItem(repository->elements[index]);
        free(repository->elements);
        DestroyUndo(repository);
        DestroyRedo(repository);
    }
    free(repository);

}


void ResizeUndo(Repository *repository) {
    repository->capacityofundo *= 2;
    repository->undolist = (Operation**)realloc(repository->undolist, repository->capacityofundo * sizeof(Operation*));
}

void DeleteUndo(Repository *repository) {
    destroyoperation(repository->undolist[repository->sizeofundo - 1]);
    repository->sizeofundo--;
}

void ResizeRedo(Repository *repository) {
    repository->capacityofredo *= 2;
    repository->redolist = (Operation**)realloc(repository->redolist, repository->capacityofredo * sizeof(Operation*));
}

void AddUndo(Repository *repository, char* operationName, Item* item) {
    if (repository->sizeofundo >= repository->capacityofundo)
        ResizeUndo(repository);
    repository->undolist[repository->sizeofundo++] = createoperation(item, operationName);
}

void AddRedo(Repository *repository, char *operationName, Item* item) {
    if (repository->sizeofredo >= repository->capacityofredo)
        ResizeRedo(repository);
    repository->redolist[repository->sizeofredo++] = createoperation(item, operationName);
}

void DeleteRedo(Repository *repository) {
    destroyoperation(repository->redolist[repository->sizeofredo - 1]);
    repository->sizeofredo--;
}



void DestroyUndo(Repository* repository)
{
    for(int index = 0; index < repository->sizeofundo; index++)
        destroyoperation(repository->undolist[index]);
    free(repository->undolist);
}
void DestroyRedo(Repository* repository){

    for (int index = 0; index < repository->sizeofredo; index++)
        destroyoperation(repository->redolist[index]);
    free(repository->redolist);
}


void resize(Repository *repository) {
    repository->capacity *= 2;
    repository->elements = (Item**)realloc(repository->elements, repository->capacity*sizeof(Item*));
}


void AddElement(Repository* repository, Item* element){
    if (repository->size >= repository->capacity)
        resize(repository);

    repository->elements[repository->size++] = element;

}

void DeleteItemRepository(Repository *repository, int catalogueNumber) {
    int positionForItem = 0;
    int index;
    int lengthOfList = repository->size;
    Item** ItemList = repository->elements;
    for (index = 0; index < lengthOfList; index++){
        if (getCatalogueNumber(ItemList[index]) == catalogueNumber) {
            destroyItem(ItemList[index]);
            for (positionForItem = index; positionForItem <= lengthOfList - 1; positionForItem++) {
                repository->elements[positionForItem] = repository->elements[positionForItem + 1];
            }
            lengthOfList--;
            index--;
        }

    }
    repository->size = lengthOfList;

}

void UpdateItemRepository(Repository *repository, Item* item){

    int lengthOfList = repository->size;
    int index;
    for (index = 0; index < lengthOfList; index++){
        if (getCatalogueNumber(repository->elements[index]) == getCatalogueNumber(item))
            repository->elements[index] = item;
    }
}

Item** GetAllRepository(Repository* repository)
{
    return repository->elements;
}

Item* FindByCatalogueNumber(Repository* repository, int CatalogueNumber){
    Item** ListOfItems = GetAllRepository(repository);
    int index;
    for(index = 0; index <= repository->size; index++)
    {
        if (getCatalogueNumber(ListOfItems[index]) == CatalogueNumber)
            return ListOfItems[index];


    }
    return 0;
}

