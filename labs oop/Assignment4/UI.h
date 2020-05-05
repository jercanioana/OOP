//
// Created by Ioana Jercan on 2019-03-14.
//

#ifndef ASSIGNMENT4_UI_H
#define ASSIGNMENT4_UI_H

#endif //ASSIGNMENT4_UI_H
#include "Service.h"
typedef struct{
    Service service;
}UI;

void AddItemUI(UI* ui, char* command);
void DeleteItemUI(UI* ui, char* command);
void UpdateItemUI(UI* ui, char* command);
void ListItemsUI(UI* ui);
void run_menu(UI* ui);
void ListItemsByType(UI* ui, char* command);
void ListMaximumPotency(UI* ui, char* command);
void undo(UI* ui);
void redo(UI* ui);
