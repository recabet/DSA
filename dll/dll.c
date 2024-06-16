#include "dll.h"
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>


void createDLL(dnode** head)
{
	if(!*head)
	{
		*head = (dnode*) malloc(sizeof(dnode));
	}
	dnode* temp = *head;
	temp->prev = nullptr;
	int n;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	if(n <= 0)
	{
		fprintf(stderr, "invalid number of nodes\n", errno);
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i <= n; i++)
	{
		printf("Enter the value of each node: ");
		scanf("%d", &(temp->val));
		if(i < n)
		{
			temp->next = (dnode*) malloc(sizeof(dnode));
			temp->next->prev = temp;
			temp = temp->next;
		}
		if(i == n)
		{
			temp->next = nullptr;
		}
	}
}

void displayForwardDLL(dnode* head)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = head;
	printf("NULL <-> ");
	while(temp)
	{
		printf("%d <-> ", temp->val);
		temp = temp->next;
	}
	printf(" NULL");
}

void displayBackwardDLL(dnode* head)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = head;
	while(temp->next)
	{
		temp = temp->next;
	}
	printf("NULL -> ");
	while(temp)
	{
		printf("%d -> ", temp->val);
		temp = temp->prev;
	}
	printf("NULL ");
}

int countNode(dnode* head)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = head;
	int count = 0;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
}

void insertElementBeginningDLL(dnode** head, int val)
{
	if(!*head)
	{
		*head = (dnode*) malloc(sizeof(dnode));
	}

	dnode* inserted = (dnode*) malloc(sizeof(dnode));
	dnode* temp = *head;
	temp->prev = inserted;
	inserted->next = temp;
	inserted->prev = nullptr;
	*head = inserted;
}

void insertElementMiddleDLL(dnode* head, int pos, int val)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	if(pos <= 1 || pos >= countNodeDLL(head))
	{
		fprintf(stderr, "Invalid pos\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = head;
	dnode* inserted = (dnode*) malloc(sizeof(dnode));
	inserted->val = val;
	for(int i = 1; i < pos - 1; i++)
	{
		temp = temp->next;
	}
	inserted->next = temp->next;
	temp->next->prev = inserted;
	temp->next = inserted;
	inserted->prev = temp;
}

void insertElementEndDLL(dnode* head, int val)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = head;
	dnode* inserted = (dnode*) malloc(sizeof(dnode));
	inserted->val = val;
	while(temp->next)
	{
		temp = temp->next;
	}
	inserted->next = nullptr;
	inserted->prev = temp;
	temp->next = inserted;
}

void deleteElementBeginningDLL(dnode** head)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = *head;
	*head = temp->next;
	temp->next->prev = nullptr;
	free(temp);
}

void deleteElementMiddleDLL(dnode* head, int pos)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = head;
	if(pos >= countNodeDLL(head) || pos < 1)
	{
		printf("Invalid pos");
	}
	for(int i = 1; i < pos - 1; i++)
	{
		temp = temp->next;
	}
	dnode* temp2 = temp->next;
	temp2->next->prev = temp;
	temp->next = temp2->next;
	free(temp2);
}

void deleteElementEndDLL(dnode* head)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = head;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->prev->next = nullptr;
	free(temp);
}

bool searchDLL(dnode* head, int val)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = head;
	while(temp)
	{
		if(temp->val == val)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void sortDLL(dnode* head)
{
	if(!head)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	int n = countNodeDLL(head);
	for(int i = 1; i <= n - 1; i++)
	{
		dnode* temp = head;
		for(int j = 1; j <= n - i; j++)
		{
			if(temp->val > temp->next->val)
			{
				int tempVal = temp->val;
				temp->val = temp->next->val;
				temp->next->val = tempVal;
			}
			temp = temp->next;
		}
	}
}

void createCircularDLL(dnode** start)
{
	if(!*start)
	{
		*start = (dnode*) malloc(sizeof(dnode));
	}
	dnode* temp = *start;
	temp->prev = nullptr;
	int n;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	if(n <= 0)
	{
		fprintf(stderr, "invalid number of nodes\n", errno);
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i <= n; i++)
	{
		printf("Enter the value of each node: ");
		scanf("%d", &(temp->val));
		if(i < n)
		{
			temp->next = (dnode*) malloc(sizeof(dnode));
			temp->next->prev = temp;
			temp = temp->next;
		}
		if(i == n)
		{
			temp->next = *start;
			(*start)->prev = temp;
		}
	}
}

void displayCircularDLL(dnode* start)
{
	dnode* temp = start;
	if(!start)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	else
	{
		do
		{
			printf("%d ->", temp->val);
			temp = temp->next;
		} while(temp != start);
	}
}

int countNodeCircularDLL(dnode* start)
{
	if(!start)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	int count = 0;
	dnode* temp = start;
	if(!temp->next)
	{
		return count;
	}
	else
	{
		do
		{
			count++;
			temp = temp->next;
		} while(temp != start);
		return count;
	}
}

bool searchCircularDLL(dnode* start, int val)
{
	if(!start)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = start;
	do
	{
		if(temp->val == val)
		{
			return true;
		}
		temp = temp->next;
	} while(temp != start);
	return false;
}

void insertElementBeginningCircularDLL(dnode** start, int val)
{
	if(!*start)
	{
		*start = (dnode*) malloc(sizeof(dnode));
	}
	dnode* inserted = (dnode*) malloc(sizeof(dnode));
	dnode* temp = *start;
	inserted->val = val;
	inserted->next = *start;
	while(temp->next != *start)
	{
		temp = temp->next;
	}
	inserted->prev = temp;
	temp->next = inserted;
	*start = inserted;
}

void insertElementMiddleCircularDLL(dnode* start, int pos, int val)
{
	if(!start)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = start;
	if(pos <= 1)
	{
		printf("Invalid pos");
		return;
	}
	else
	{
		dnode* inserted = (dnode*) malloc(sizeof(dnode));
		inserted->val = val;
		for(int i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		inserted->next = temp->next;
		inserted->prev = temp;
		temp->next->prev = inserted;
		temp->next = inserted;
	}
}

void insertElementEndCircularDLL(dnode* start, int val)
{
	if(!start)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = start;
	dnode* inserted = (dnode*) malloc(sizeof(dnode));
	inserted->val = val;
	while(temp->next != start)
	{
		temp = temp->next;
	}
	inserted->next = start;
	inserted->prev = temp;
	temp->next = inserted;
}

//broken needs fixing
/*void deleteElementBeginningCircularDLL(dnode **start)
{
    if (!*start)
    {
        fprintf(stderr, "Linked list does not exist\n", errno);
        exit(EXIT_FAILURE);
    }
    dnode *deleted = *start;
    dnode *temp = *start;
    while (temp->next != *start)
    {
        temp = temp->next;
    }
    *start = deleted->next;
    deleted->next->prev = temp;
    temp->next = *start;
    (*start)->prev = temp;
    free(deleted);
}*/

void deleteElementMiddleCircularDLL(dnode* start, int pos)
{
	if(!start)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	dnode* temp = start;
	if(pos <= 1)
	{
		fprintf(stderr, "Invalid pos", errno);
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i < pos - 1; i++)
	{
		temp = temp->next;
	}
	dnode* deleted = temp->next;
	deleted->next->prev = temp;
	temp->next = deleted->next;
	free(deleted);
}
//broken needs fixing
/*void deleteElementEndCircularDLL(dnode *start)
{
    dnode *temp = start;
    do
    {
        temp = temp->next;
    } while (temp->next != start);
    temp->next->prev=temp->prev;
    temp->prev->next=start;
    free(temp->next);
}*/

void sortCircularDLL(dnode* start)
{
	if(!start)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	int n = countNodeCircularDLL(start);
	for(int i = 1; i <= n - 1; i++)
	{
		dnode* temp = start;
		for(int j = 1; j <= n - i; j++)
		{
			if(temp->val > temp->next->val)
			{
				int tempVal = temp->val;
				temp->val = temp->next->val;
				temp->next->val = tempVal;
			}
			temp = temp->next;
		}
	}
}