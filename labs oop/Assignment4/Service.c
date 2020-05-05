//
// Created by Ioana Jercan on 2019-03-13.
//

#include "Service.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int undoService(Service* service){
    if(service->repository->sizeofundo == 0)
        return 0;
    Operation* LastPerformedOperation = service->repository->undolist[service->repository->sizeofundo - 1];
    if(strcmp(LastPerformedOperation->operation_name, "add") == 0){
        AddRedo(service->repository, "add", copyItem(LastPerformedOperation->item));
        DeleteItemRepository(service->repository, LastPerformedOperation->item->catalogueNumber);
    }
    if(strcmp(LastPerformedOperation->operation_name, "delete") == 0){
        AddRedo(service->repository, "delete", copyItem(LastPerformedOperation->item));
        AddElement(service->repository, copyItem(LastPerformedOperation->item));
    }
    if(strcmp(LastPerformedOperation->operation_name, "update") == 0){
        AddRedo(service->repository, "update", copyItem(FindByCatalogueNumber(service->repository, LastPerformedOperation->item->catalogueNumber)));
        UpdateItemRepository(service->repository, copyItem(LastPerformedOperation->item));
    }
    DeleteUndo(service->repository);
    return 1;
}
int redoService(Service* service) {
    if (service->repository->sizeofredo == 0)
        return 0;
    Operation *LastPerformedOperation = service->repository->redolist[service->repository->sizeofredo - 1];
    if (strcmp(LastPerformedOperation->operation_name, "add") == 0) {
        AddUndo(service->repository, "add", copyItem(LastPerformedOperation->item));
        AddElement(service->repository, copyItem(LastPerformedOperation->item));

    }
    if (strcmp(LastPerformedOperation->operation_name, "delete") == 0) {
        AddUndo(service->repository, "delete", copyItem(LastPerformedOperation->item));
        DeleteItemRepository(service->repository, LastPerformedOperation->item->catalogueNumber);

    }
    if (strcmp(LastPerformedOperation->operation_name, "update") == 0) {
        AddUndo(service->repository, "update",
                copyItem(FindByCatalogueNumber(service->repository, LastPerformedOperation->item->catalogueNumber)));
        UpdateItemRepository(service->repository, copyItem(LastPerformedOperation->item));
    }
    DeleteRedo(service->repository);
    return 1;
}
void AddItemService(Service *service, int CatalogueNumber, char* state, char* type, int value){

    Item* NewItem;
    NewItem = CreateItem(CatalogueNumber, state, type, value);
    AddElement((service->repository), NewItem);
    AddUndo(service->repository, "add", copyItem(NewItem));

}
void DeleteItemService(Service* service, int CatalogueNumber){

    AddUndo(service->repository, "delete", copyItem(FindByCatalogueNumber(service->repository, CatalogueNumber)));
    DeleteItemRepository((service->repository), CatalogueNumber);

}

void UpdateItemService(Service *service, int CatalogueNumber, char newState[], char newType[], int newValue) {
    Item* NewItem;
    AddUndo(service->repository, "update", copyItem(FindByCatalogueNumber(service->repository, CatalogueNumber)));
    NewItem = CreateItem(CatalogueNumber, newState, newType, newValue);
    UpdateItemRepository((service->repository), NewItem);

}
Item** GetAllService(Service *service){
    return GetAllRepository(service->repository);
}