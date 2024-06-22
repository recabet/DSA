#ifndef DLL_H
#define DLL_H

#include<stdbool.h>


typedef struct Dnode {
	int val;
	struct Dnode* next;
	struct Dnode* prev;
} dnode;

void createDLL(dnode** head);

void displayForwardDLL(dnode* head);

void displayBackwardDLL(dnode* head);

int countNodeDLL(dnode* head);

void insertElementBeginningDLL(dnode** head, int val);

void insertElementMiddleDLL(dnode* head, int pos, int val);

void insertElementEndDLL(dnode* head, int val);

void deleteElementBeginningDLL(dnode** head);

void deleteElementMiddleDLL(dnode* head, int pos);

void deleteElementEndDLL(dnode* head);

void sortDLL(dnode* head);

bool searchDLL(dnode* head, int val);

void createCircularDLL(dnode** start);

void displayCircularDLL(dnode* start);

int countNodeCircularDLL(dnode* start);

bool searchCircularDLL(dnode* start, int val);

void insertElementBeginningCircularDLL(dnode** start, int val);

void insertElementMiddleCircularDLL(dnode* start, int pos, int val);

void insertElementEndCircularDLL(dnode* start, int val);

//doesnt work
//void deleteElementBeginningCircularDLL(dnode** start);

void deleteElementMiddleCircularDLL(dnode* start, int pos);

//doesnt work
//void deleteElementEndCircularDLL(dnode* start);

void sortCircularDLL(dnode* start);


#endif //DLL_H
