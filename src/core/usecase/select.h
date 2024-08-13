#ifndef SELECT_H
#define SELECT_H

#include "../domain/query.h"

typedef struct {
    void (*execute_select)(const Query *query);
} Select;

#endif // SELECT_H
