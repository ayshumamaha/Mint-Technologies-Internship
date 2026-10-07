#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define FILE_NAME "store.bin"

typedef struct {
    int id;
    char name[50];
    char category[50];
    double value;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

/* Initialize database */
void initialize_database(Database *db) {
    db->count = 0;
}

/* Add a record */
void add_record(Database *db, int id, const char *name,
                const char *category, double value) {

    if (db->count >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    db->records[db->count].id = id;

    strncpy(db->records[db->count].name, name,
            sizeof(db->records[db->count].name) - 1);

    db->records[db->count].name[
        sizeof(db->records[db->count].name) - 1
    ] = '\0';

    strncpy(db->records[db->count].category, category,
            sizeof(db->records[db->count].category) - 1);

    db->records[db->count].category[
        sizeof(db->records[db->count].category) - 1
    ] = '\0';

    db->records[db->count].value = value;

    db->count++;

    printf("Record added successfully.\n");
}

/* Display database */
void display_database(const Database *db) {
    printf("\n--- DATABASE RECORDS ---\n");

    if (db->count == 0) {
        printf("No records available.\n");
        return;
    }

    for (int i = 0; i < db->count; i++) {
        printf("ID       : %d\n", db->records[i].id);
        printf("Name     : %s\n", db->records[i].name);
        printf("Category : %s\n", db->records[i].category);
        printf("Value    : %.2f\n", db->records[i].value);
        printf("------------------------\n");
    }
}

/* Save database to binary file */
int save_database(const Database *db) {
    FILE *file = fopen(FILE_NAME, "wb");

    if (file == NULL) {
        perror("Unable to open file for writing");
        return 0;
    }

    size_t written = fwrite(db, sizeof(Database), 1, file);

    fclose(file);

    if (written != 1) {
        printf("Error while writing database.\n");
        return 0;
    }

    printf("Database saved to %s successfully.\n", FILE_NAME);

    return 1;
}

/* Load database from binary file */
int load_database(Database *db) {
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("Storage file does not exist yet.\n");
        return 0;
    }

    size_t read = fread(db, sizeof(Database), 1, file);

    fclose(file);

    if (read != 1) {
        printf("Error while reading database.\n");
        return 0;
    }

    printf("Database loaded from %s successfully.\n", FILE_NAME);

    return 1;
}

int main(void) {
    Database db;

    printf("TASK 2: FILE I/O AND BINARY STORAGE\n\n");

    initialize_database(&db);

    add_record(&db, 101, "Laptop", "Electronics", 65000.00);
    add_record(&db, 102, "Keyboard", "Accessories", 2500.00);
    add_record(&db, 103, "Monitor", "Electronics", 18000.00);

    printf("\nCurrent database:\n");
    display_database(&db);

    printf("\nSaving database...\n");
    save_database(&db);

    Database loaded_db;

    initialize_database(&loaded_db);

    printf("\nLoading database from disk...\n");
    load_database(&loaded_db);

    printf("\nRestored database:\n");
    display_database(&loaded_db);

    return 0;
}