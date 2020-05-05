//
// Created by Ioana Jercan on 2019-03-06.
//

#ifndef ASSIGNMENT3_A_H
#define ASSIGNMENT3_A_H

#endif //ASSIGNMENT3_A_H
typedef struct{

    int catalogueNumber;
    char state[100];
    char type[100];
    int value;

}Item;

int getCatalogueNumber(Item item);
void setCatalogueNumber(Item *item, int value);

void setState(Item* item, char value[]);
char getType(Item* item);
void setType(Item* item, char value[]);
int getValue(Item item);
void setValue(Item* item, int value);



