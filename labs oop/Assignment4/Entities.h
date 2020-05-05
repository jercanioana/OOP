//
// Created by Ioana Jercan on 2019-03-13.
//

#ifndef ASSIGNMENT4_ENTITIES_H
#define ASSIGNMENT4_ENTITIES_H

#endif //ASSIGNMENT4_ENTITIES_H
typedef struct{

    int catalogueNumber;
    char* state;
    char* type;
    int value;

}Item;

typedef struct{
    char* operation_name;
    Item* item;
}Operation;

Item* CreateItem(int catalogueNumber, char* state, char* type, int value);
void destroyItem(Item* item);
Item* copyItem(Item* item);
int getCatalogueNumber(Item* item);
char* getType(Item* item);
int getValue(Item* item);
Operation* createoperation(Item* item, char* name);
void destroyoperation(Operation* operation);

