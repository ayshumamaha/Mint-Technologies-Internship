#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Entry {
    char *key;
    char *value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} HashTable;

/* Hash function */
unsigned int hash_function(const char *key) {
    unsigned int hash = 0;

    while (*key) {
        hash = (hash * 31) + (unsigned char)*key;
        key++;
    }

    return hash % TABLE_SIZE;
}

/* Duplicate a string using dynamic memory */
char *duplicate_string(const char *source) {
    char *copy = malloc(strlen(source) + 1);

    if (copy == NULL) {
        return NULL;
    }

    strcpy(copy, source);
    return copy;
}

/* Initialize hash table */
void initialize_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
}

/* Insert or update a key-value pair */
void set_value(HashTable *table, const char *key, const char *value) {
    unsigned int index = hash_function(key);
    Entry *current = table->buckets[index];

    /* Check whether key already exists */
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            char *new_value = duplicate_string(value);

            if (new_value == NULL) {
                printf("Memory allocation failed.\n");
                return;
            }

            free(current->value);
            current->value = new_value;

            printf("Updated: %s = %s\n", key, value);
            return;
        }

        current = current->next;
    }

    /* Create new entry */
    Entry *new_entry = malloc(sizeof(Entry));

    if (new_entry == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_entry->key = duplicate_string(key);
    new_entry->value = duplicate_string(value);

    if (new_entry->key == NULL || new_entry->value == NULL) {
        free(new_entry->key);
        free(new_entry->value);
        free(new_entry);
        printf("Memory allocation failed.\n");
        return;
    }

    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;

    printf("Inserted: %s = %s\n", key, value);
}

/* Search for a value */
const char *get_value(HashTable *table, const char *key) {
    unsigned int index = hash_function(key);
    Entry *current = table->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }

        current = current->next;
    }

    return NULL;
}

/* Delete a key-value pair */
void delete_value(HashTable *table, const char *key) {
    unsigned int index = hash_function(key);
    Entry *current = table->buckets[index];
    Entry *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {

            if (previous == NULL) {
                table->buckets[index] = current->next;
            } else {
                previous->next = current->next;
            }

            free(current->key);
            free(current->value);
            free(current);

            printf("Deleted: %s\n", key);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Key not found: %s\n", key);
}

/* Display all entries */
void display_table(HashTable *table) {
    printf("\n--- Hash Table ---\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *current = table->buckets[i];

        if (current != NULL) {
            printf("Bucket %d: ", i);

            while (current != NULL) {
                printf("[%s = %s] ", current->key, current->value);
                current = current->next;
            }

            printf("\n");
        }
    }
}

/* Free all dynamically allocated memory */
void cleanup_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *current = table->buckets[i];

        while (current != NULL) {
            Entry *next = current->next;

            free(current->key);
            free(current->value);
            free(current);

            current = next;
        }

        table->buckets[i] = NULL;
    }
}

int main(void) {
    HashTable table;

    initialize_table(&table);

    printf("TASK 1: HASH TABLE AND DYNAMIC MEMORY\n\n");

    set_value(&table, "name", "Aishwarya");
    set_value(&table, "course", "C Programming");
    set_value(&table, "project", "Data Structures");

    printf("\nSearching for 'name': ");

    const char *value = get_value(&table, "name");

    if (value != NULL) {
        printf("%s\n", value);
    } else {
        printf("Key not found.\n");
    }

    printf("\nUpdating 'course'...\n");
    set_value(&table, "course", "Advanced C Programming");

    printf("\nDeleting 'project'...\n");
    delete_value(&table, "project");

    display_table(&table);

    cleanup_table(&table);

    printf("\nMemory cleanup completed successfully.\n");

    return 0;
}