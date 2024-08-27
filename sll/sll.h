#ifndef SLL_H
#define SLL_H


#include <stdbool.h>


typedef struct Node {
    int val;
    struct Node* next;
} node;

void createSLL(node** head);

void displaySLL(node* head);

int countNodeSLL(node* head);

bool searchSLL(node* head, int val);

void insertElementBeginningSLL(node** head, int val);

void insertElementMiddleSLL(node* head, int pos, int val);

void insertElementEndSLL(node* head, int val);

void deleteElementBeginningSLL(node** head);

void deleteElementMiddleSLL(node* head, int pos);

void deleteElementEndSLL(node* head);

void sortSLL(node* head);

void reverseSLL(node* head);

//new needs testing line 325
void insertSLL(node* head1, node* head2, int pos);

//new needs testing line 355
void insertSLLBeginning(node** head1, node* head2);

//new needs testing line 426
node* sliceSLL(node* head, int index1, int index2, int numberOfNodes);

//new needs testing line 407
void insertSLLEnd(node* head1, node* head2);

//new needs testing line 375
void deleteSLL(node** head, int index1, int index2, int numberOfNodes);

void createCircularSLL(node** start);

void displayCircularSLL(node* start);

int countNodeCircularSLL(node* start);

void insertElementBeginningCircularSLL(node** start, int val);

void insertElementMiddleCircularSLL(node* start, int pos, int val);

void insertElementEndCircularSLL(node* start, int val);

bool searchCircularSLL(node* start, int val);

void deleteElementBeginningCircularSLL(node** start);

void deleteElementMiddleCircularSLL(node* start, int pos);

void deleteElementEndCircularSLL(node* start);

void reverseCircularSLL(node* start);

void sortCircularSLL(node* start);


#endif //SLL_H
