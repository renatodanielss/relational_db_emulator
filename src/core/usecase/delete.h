#ifndef DELETE_H
#define DELETE_H

#include "../domain/query.h"

typedef struct {
    void (*execute_delete)(const Query *query);
} Delete;

#endif // DELETE_H
