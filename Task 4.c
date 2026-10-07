#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_KEY 50
#define MAX_VALUE 200
#define MAX_INPUT 300

typedef struct {
    char key[MAX_KEY];
    char value[MAX_VALUE];
} Entry;

Entry database[MAX_ENTRIES];
int entry_count = 0;

/* Find entry by key */
int find_entry(const char *key) {
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(database[i].key, key) == 0) {
            return i;
        }
    }

    return -1;
}

/* SET command */
void set_command(const char *key, const char *value) {
    int index = find_entry(key);

    if (index >= 0) {
        strncpy(database[index].value, value, MAX_VALUE - 1);
        database[index].value[MAX_VALUE - 1] = '\0';

        printf("Updated: %s = %s\n", key, database[index].value);
        return;
    }

    if (entry_count >= MAX_ENTRIES) {
        printf("Database is full.\n");
        return;
    }

    strncpy(database[entry_count].key, key, MAX_KEY - 1);
    database[entry_count].key[MAX_KEY - 1] = '\0';

    strncpy(database[entry_count].value, value, MAX_VALUE - 1);
    database[entry_count].value[MAX_VALUE - 1] = '\0';

    entry_count++;

    printf("Stored: %s = %s\n", key, value);
}

/* GET command */
void get_command(const char *key) {
    int index = find_entry(key);

    if (index >= 0) {
        printf("%s = %s\n",
               database[index].key,
               database[index].value);
    } else {
        printf("Key not found: %s\n", key);
    }
}

/* DELETE command */
void delete_command(const char *key) {
    int index = find_entry(key);

    if (index < 0) {
        printf("Key not found: %s\n", key);
        return;
    }

    for (int i = index; i < entry_count - 1; i++) {
        database[i] = database[i + 1];
    }

    entry_count--;

    printf("Deleted: %s\n", key);
}

/* LIST command */
void list_command(void) {
    if (entry_count == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("\n--- STORED ENTRIES ---\n");

    for (int i = 0; i < entry_count; i++) {
        printf("%d. %s = %s\n",
               i + 1,
               database[i].key,
               database[i].value);
    }
}

/* HELP command */
void help_command(void) {
    printf("\nAvailable commands:\n");
    printf("SET <key> <value>       Store or update a value\n");
    printf("GET <key>               Retrieve a value\n");
    printf("DELETE <key>            Delete a value\n");
    printf("LIST                    Display all values\n");
    printf("HELP                    Display this help message\n");
    printf("EXIT                    Exit the program\n\n");
}

/* Process user command */
void process_command(char *input) {
    char command[20];
    char key[MAX_KEY];
    char value[MAX_VALUE];

    /* SET requires command + key + value */
    if (sscanf(input, "%19s %49s %199[^\n]",
               command, key, value) == 3) {

        if (strcmp(command, "SET") == 0) {
            set_command(key, value);
            return;
        }
    }

    /* Commands with one argument */
    if (sscanf(input, "%19s %49s",
               command, key) == 2) {

        if (strcmp(command, "GET") == 0) {
            get_command(key);
            return;
        }

        if (strcmp(command, "DELETE") == 0) {
            delete_command(key);
            return;
        }
    }

    /* Commands without arguments */
    if (sscanf(input, "%19s", command) == 1) {

        if (strcmp(command, "LIST") == 0) {
            list_command();
            return;
        }

        if (strcmp(command, "HELP") == 0) {
            help_command();
            return;
        }

        if (strcmp(command, "EXIT") == 0) {
            return;
        }
    }

    printf("Invalid command or incorrect syntax.\n");
    printf("Type HELP for available commands.\n");
}

int main(void) {
    char input[MAX_INPUT];

    printf("====================================\n");
    printf("      ADVANCED CLI ENGINE\n");
    printf("====================================\n");

    help_command();

    while (1) {
        printf("CLI> ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nInput error.\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            continue;
        }

        if (strncmp(input, "EXIT", 4) == 0 &&
            (input[4] == '\0' || input[4] == ' ')) {
            printf("Exiting CLI...\n");
            break;
        }

        process_command(input);
    }

    return 0;
}