//
// Created by Ioana Jercan on 2019-03-07.
//
#include "Repository.h"
#include <stdio.h>
#include <string.h>

void AddItemRepository(Repository *repository, Item item){
    repository->size++;
    repository->itemList[repository->size] = item;
}

void DeleteItemRepository(Repository *repository, int catalogueNumber) {
    int positionForItem = 0;
    int index;
    int lengthOfList = repository->size;
    for (index = 1; index <= lengthOfList; index++)
        if (getCatalogueNumber(repository->itemList[index]) == catalogueNumber) {

            for (positionForItem = index; positionForItem < lengthOfList; positionForItem++)
                repository->itemList[positionForItem] = repository->itemList[positionForItem + 1];
            lengthOfList--;
            index--;

        }

}

void UpdateItemRepository(Repository *repository, Item item){

    int lengthOfList = repository->size;
    int index;
    for (index = 0; index <= lengthOfList; index++){
        if (getCatalogueNumber(repository->itemList[index]) == getCatalogueNumber(item))
            repository->itemList[index] = item;
    }
}

Item* GetAllRepository(Repository* repository)
{
    Item *ListOfItems = repository->itemList;
    return ListOfItems;
}

