#include<stdlib.h>
#include"deque.h"
#include"assert.h"

#define NEW(name) name = calloc(1, sizeof(*name))
#define _GET_ARG4(a, b, c, d, ...) d
#define _node_new0() _node_new2(0);
#define _node_new1(value) _node_new2(value, NULL);
#define _node_new2(value, next) _node_new3(value, next, NULL)
#define node_new(...) _GET_ARG4(\
    __VA_ARGS__,\
    _node_new3,\
    _node_new2,\
    _node_new1,\
    _node_new0,\
    )(__VA_ARGS__)

typedef struct node {
    VAL_TYPE value;
    struct node *prev;
    struct node *next;
} node_t;

static node_t *_node_new3(VAL_TYPE value, node_t *next, node_t *prev){
    node_t *NEW(node);
    node->value = value;
    node->next = next;
    node->prev = prev;
    return node;
}

struct deque {
    node_t *head;
    node_t *tail;
    int size;
};

deque_t *deque_new(){
    // works cuz we want all to be 0
    return calloc(1, sizeof(deque_t));
}

void deque_free(deque_t* deque){
    deque_clear(deque);
    free(deque);
}

void deque_clear(deque_t *deque){
    while(!deque_empty(deque)){
        deque_pop_front(deque);
    }
}

void deque_push_front(deque_t *deque, VAL_TYPE value){
    if(deque->head == NULL){
        deque->head = deque->tail = node_new(value);
    }else{
        deque->head = deque->head->prev = node_new(value, deque->head);
    }
    deque->size++;
}

void deque_push_back(deque_t *deque, VAL_TYPE value){
    if(deque->head == NULL){
        deque->head = deque->tail = node_new(value);
    }else{
        deque->tail = deque->tail->next = node_new(value, NULL, deque->tail);
    }
    deque->size++;
}

VAL_TYPE deque_pop_front(deque_t *deque){
    VAL_TYPE result = deque_peek_front(deque);
    node_t *temp = deque->head;
    deque->head = deque->head->next;
    if(deque->head == NULL){
        deque->tail = NULL;
    }else{
        deque->head->prev = NULL;
    }
    free(temp);
    deque->size--;
    return result;
}

VAL_TYPE deque_pop_back(deque_t *deque){
    VAL_TYPE result = deque_peek_back(deque);
    node_t *temp = deque->tail;
    deque->tail = deque->tail->prev;
    if(deque->tail == NULL){
        deque->head = NULL;
    }else{
        deque->tail->next = NULL;
    }
    free(temp);
    deque->size--;
    return result;
}

VAL_TYPE deque_peek_front(deque_t *deque){
    return deque->head->value;
}

VAL_TYPE deque_peek_back(deque_t *deque){
    return deque->tail->value;
}

bool deque_empty(deque_t *deque){
    return deque->size == 0;
}

int deque_length(deque_t *deque){
    return deque->size;
}
