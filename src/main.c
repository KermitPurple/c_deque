#include<stdio.h>
#include"deque.h"

#define printb(b) puts((b) ? "True" : "False")

int main(){
    deque_t *d = deque_new();
    printb(deque_empty(d));
    for(int i = 0; i < 10; i++){
        deque_push(d, i);
    }
    printb(deque_empty(d));
    while(!deque_empty(d)){
        printf("%d\n", deque_pop(d));
    }
    printb(deque_empty(d));
    deque_free(d);
    return 0;
}
