#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "core/usecase/insert.h"
#include "core/usecase/insert.c"

void add_record(Record *records, int *count) {
    printf("Enter ID: ");
    scanf("%d", &records[*count].id);
    printf("Enter Name: ");
    scanf("%s", records[*count].name);
    printf("Enter Age: ");
    scanf("%d", &records[*count].age);
    (*count)++;
}

void list_records(const Record *records, int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", records[i].id, records[i].name, records[i].age);
    }
}

//int main() {
//    Record records[100];
//    int count = 0;
//    int option;
//
//    while (1) {
//        printf("1. Add Record\n");
//        printf("2. Delete Record\n");
//        printf("3. List Records\n");
//        printf("4. Exit\n");
//        printf("Choose an option: ");
//        scanf("%d", &option);
//
//        switch (option) {
//            case 1:
//                add_record(records, &count);
//                break;
//            case 2:
//                printf("To be implemented\n");
//                break;
//            case 3:
//                list_records(records, count);
//                break;
//            case 4:
//                return 0;
//            default:
//                printf("Invalid option.\n");
//        }
//    }
//}

int main() {
    Query *query = (Query *)malloc(sizeof(Query));
    if (query == NULL) {
        perror("Failed to allocate memory for Query");
        exit(EXIT_FAILURE);
    }

    const char *input_script = "INSERT INTO users (id, name, age) VALUES (1, 'John Doe', 30);";
    query->script = (char *)malloc(strlen(input_script) + 1);
    strcpy(query->script, input_script);
    if (query->script == NULL) {
        perror("Failed to allocate memory for script");
        free(query);
        exit(EXIT_FAILURE);
    }

    Insert *insert = new_insert();
    insert->execute_insert(query);

    free(query->script); // Libera a memória do script
    free(query); // Libera a memória do query
    free(insert);

    return 0;
}