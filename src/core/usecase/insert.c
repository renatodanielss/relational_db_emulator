#include "insert.h"
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 100

int extract_parameters() {
    char str[] = "valor1,valor2,valor3,valor4";
    char delimiter[] = ",";
    char **tokens;
    int token_count = 0;

    char *token = strtok(str, delimiter);

    // Continue obtendo tokens até não haver mais
    while (token != NULL) {
        // Verifique se o número máximo de tokens foi alcançado
        tokens[token_count] = token; // Armazene o token
        token_count++;
        // Obtenha o próximo token
        token = strtok(NULL, delimiter);
    }

    // Exiba os tokens
    printf("Tokens:\n");
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}

void execute_insert(const Query *query) {
    printf("%s", query->script);
}

Insert *new_insert() {
    Insert *insert = (Insert *)malloc(sizeof(Insert));
    insert->execute_insert = execute_insert;
    return insert;
}