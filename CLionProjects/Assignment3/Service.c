//
// Created by Ioana Jercan on 2019-03-08.
//

#include "Service.h"
#include <stdio.h>
#include <string.h>

void AddItemService(Service *service, int CatalogueNumber, char state[], char type[], int value){
    Item NewItem;

    setCatalogueNumber(&NewItem, CatalogueNumber);
    setValue(&NewItem, value);
    setState(&NewItem, state);
    setType(&NewItem, type);
    AddItemRepository(&(service->repository), NewItem);


}
void DeleteItemService(Service* service, int CatalogueNumber){

    DeleteItemRepository(&(service->repository), CatalogueNumber);
}

void UpdateItemService(Service *service, int CatalogueNumber, char newState[], char newType[], int newValue){
    Item NewItem;
    setCatalogueNumber(&NewItem, CatalogueNumber);
    setValue(&NewItem, newValue);
    setState(&NewItem, newState);
    setType(&NewItem, newType);
    UpdateItemRepository(&(service->repository), NewItem);
}
Item* GetAllService(Service *service){
    return GetAllRepository(&(service->repository));
}
