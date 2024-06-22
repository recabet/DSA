//
// Created by rajab on 11/06/24.
//

#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TABLE_SIZE 1024
#define HASH_CONST_MULT 31

typedef struct entry {
	const char* name;
	int data;
	struct entry* next;
} Entry;

typedef struct hashtable {
	Entry* table[TABLE_SIZE];
} Hashtable;

long int hash(const Entry* entry);

Hashtable* createHashTable();

void insert(Hashtable* ht, const char* name, int data);

Entry* lookup(Hashtable* ht, const char* name);

void free_table(Hashtable* hashtable);


#endif //HASH_H
