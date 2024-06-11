#include "hash.h"

long int hash (const Entry *entry)
{
	long int hashcode = 0;
	for (size_t i = 0; i < strlen(entry->name); i++)
	{
		hashcode = hashcode * HASH_CONST_MULT + (entry->name)[i];
	}
	return hashcode % TABLE_SIZE;
}

Hashtable *createHashTable ()
{
	Hashtable *ht = (Hashtable *) malloc(sizeof(Hashtable));
	if (!ht)
	{
		fprintf(stderr, "HashTable could not be initialized! Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		(ht->table)[i] = NULL;
	}
	return ht;
}

void insert (Hashtable *ht, const char *name, int data)
{
	Entry *entry = (Entry *) malloc(sizeof(Entry));
	if (!entry)
	{
		fprintf(stderr, "Entry could not be allocated! Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}


	char *name_copy = strdup(name);
	if (!name_copy)
	{
		fprintf(stderr, "Name could not be duplicated! Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	entry->name = name_copy;
	entry->data = data;
	entry->next = NULL;

	long int index = hash(entry);
	if (ht->table[index] == NULL)
	{
		ht->table[index] = entry;
	}
	else
	{
		entry->next = ht->table[index];
		ht->table[index] = entry;
	}
}

Entry *lookup (Hashtable *ht, const char *name)
{
	Entry temp_entry = {name, 0, NULL};
	long int index = hash(&temp_entry);
	Entry *temp = (ht->table)[index];
	while (temp)
	{
		if (strcmp(temp->name, name) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void free_table (Hashtable *hashtable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		Entry *temp = (hashtable->table)[i];
		while (temp)
		{
			Entry *prev = temp;
			temp = temp->next;
			free((void *) prev->name);
			free(prev);
		}
	}
	free(hashtable);
}
