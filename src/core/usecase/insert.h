#ifndef INSERT_H
#define INSERT_H

#include "../domain/query.h"

typedef struct {
    void (*execute_insert)(const Query *query);
} Insert;

#endif // INSERT_H
