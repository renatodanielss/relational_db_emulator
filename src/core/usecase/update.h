#ifndef UPDATE_H
#define UPDATE_H

#include "../domain/query.h"

typedef struct {
    void (*execute_update)(const Query *query);
} Update;

#endif // UPDATE_H
