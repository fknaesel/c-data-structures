#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0

typedef struct tPilha {
    int *topo;
    int used;
    int size;
} tPilha;

int push(int value, int *stack, int *used, int size) {
    printf("push %d\n", value);
    if (*used < size) {
        *(stack+*used) = value;
        (*used)++;
        return true;
    } else {
        printf("push failed: stack has reached its capacity\n");
        return INT_MIN;
    }
}

int list(int *stack, int used) {
    if (used==0) {
        printf("list is empty\n");
        return INT_MIN;
    }
    else {
        printf("list: ");
        for (int i=0; i<used; i++) {
            printf("%d", *(stack+i));
            if (i+1<used) printf(",");
        }
        printf("\n");
        return true;
    }
}

int pop(int *stack, int *used) {
    if (*used==0) {
        printf("pop failed: empty stack\n");
        return INT_MIN;
    }
    else {
        int ret = *(stack+*used-1);
        printf("pop %d\n", ret);
        (*used)--;
        return ret;
    }
}

int top(int *stack, int used) {
    if (used==0) {
        printf("top failed: empty stack\n");
        return INT_MIN;
    }
    else {
        int ret = *(stack+used-1);
        printf("top = %d\n", ret);
        return ret;
    }
}

int* init(int size, int* used) {
    int *stack;
    stack = (int*) malloc(size*sizeof(int));
    *used = 0;
    return stack;
}

int pl() { printf("----------------\n"); }

int main() {
    srand(time(NULL));
    int size = 50;
    int i, used;
    int *stack = init(size, &used);

    // push
    for (i=0; i<size; i++) {   
        push(rand()%100, stack, &used, size);
    }
    list(stack, used);
    push(rand()%100, stack, &used, size);
}