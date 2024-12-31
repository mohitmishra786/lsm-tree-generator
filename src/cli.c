#include "cli.h"
#include "lsm_tree.h"
#include "memtable.h"
#include "sstable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_lsm_tree(LSMTree* lsm) {
    printf("\n--- LSM Tree Visualization ---\n");
    printf("MemTable:\n");
    if (lsm->memtable->size == 0) {
        printf("  (Empty)\n");
    } else {
        for (size_t i = 0; i < lsm->memtable->size; i++) {
            printf("  %s: %s\n", lsm->memtable->keys[i], lsm->memtable->values[i]);
        }
    }
    printf("SSTables:\n");
    if (lsm->sstable_count == 0) {
        printf("  (No SSTables)\n");
    } else {
        for (int i = 0; i < lsm->sstable_count; i++) {
            printf("  Level %d:\n", i);
            FILE* file = fopen(lsm->sstables[i]->fname, "r");
            if (file) {
                char line[256];
                while (fgets(line, sizeof(line), file)) {
                    char* value = strchr(line, '\t');
                    if (value) {
                        *value = '\0';
                        value++;
                        if (value[strlen(value) - 1] == '\n') value[strlen(value) - 1] = '\0'; // Remove newline
                        printf("    %s: %s\n", line, value);
                    }
                }
                fclose(file);
            } else {
                printf("    Failed to open %s\n", lsm->sstables[i]->fname);
            }
        }
    }
}

void run_cli(LSMTree* lsm) {
    char command[100], key[100], value[100];
    while (1) {
        printf("\nEnter command (insert/get/delete/compact/display/exit): ");
        if (scanf("%99s", command) != 1) {
            printf("Error reading command.\n");
            continue;
        }

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "insert") == 0) {
            if (scanf("%99s %99s", key, value) != 2) {
                printf("Error reading key and value.\n");
            } else {
                if (!lsm_insert(lsm, key, value)) {
                    printf("Failed to insert.\n");
                }
            }
        } else if (strcmp(command, "get") == 0) {
            if (scanf("%99s", key) != 1) {
                printf("Error reading key.\n");
            } else {
                const char* result = lsm_get(lsm, key);
                printf("Value for key '%s': %s\n", key, result ? result : "Not found");
            }
        } else if (strcmp(command, "delete") == 0) {
            if (scanf("%99s", key) != 1) {
                printf("Error reading key to delete.\n");
            } else {
                if (!lsm_delete(lsm, key)) {
                    printf("Key '%s' not found for deletion.\n", key);
                } else {
                    printf("Deleted key '%s'.\n", key);
                }
            }
        } else if (strcmp(command, "compact") == 0) {
            lsm_compact(lsm);
            printf("LSM Tree compacted.\n");
        } else if (strcmp(command, "display") == 0) {
            display_lsm_tree(lsm);
        } else {
            printf("Unknown command: %s\n", command);
        }
        // Clear input buffer
        while (getchar() != '\n');
    }
}
