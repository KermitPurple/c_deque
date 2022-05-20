#ifndef DEQUE_H
#define DEQUE_H

#include<stdbool.h>

#ifndef VAL_TYPE
#define VAL_TYPE int
#endif // VAL_TYPE

#define deque_push deque_push_front
#define deque_pop deque_pop_front
#define deque_peek deque_peek_front

typedef struct deque deque_t;

deque_t *deque_new();
void deque_free(deque_t* deque);
void deque_clear(deque_t *deque);
void deque_push_front(deque_t *deque, VAL_TYPE value);
void deque_push_back(deque_t *deque, VAL_TYPE value);
VAL_TYPE deque_pop_front(deque_t *deque);
VAL_TYPE deque_pop_back(deque_t *deque);
VAL_TYPE deque_peek_front(deque_t *deque);
VAL_TYPE deque_peek_back(deque_t *deque);
bool deque_empty(deque_t *deque);
int deque_length(deque_t *deque);

#endif // DEQUE_H
