//
// Created by Ioana Jercan on 2019-03-08.
//

#ifndef ASSIGNMENT3_UI_H
#define ASSIGNMENT3_UI_H

#endif //ASSIGNMENT3_UI_H

#include "Service.h"
typedef struct{
    Service service;
}UI;

void AddItemUI(UI* ui, char* command);
void DeleteItemUI(UI* ui, char* command);
void UpdateItemUI(UI* ui, char* command);
void ListItemsUI(UI* ui);
void run_menu();
void ListItemsByType(UI* ui, char* command);
