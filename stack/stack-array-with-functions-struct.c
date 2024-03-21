#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0

typedef struct tStack {
    int used;
    int capacity;
    int *values;
} tStack;

int dump(tStack *s) {
    printf("used %d\n", s->used);
}

int push(int value, tStack *stack) {
    printf("push %d\n", value);
    if (stack->used < stack->capacity) {
        stack->values[stack->used] = value;
        stack->used++;
        return true;
    } else {
        printf("push failed: stack has reached its capacity\n");
        return INT_MIN;
    }
}

int list(tStack *stack) {
    if (stack->used==0) {
        printf("list is empty\n");
        return INT_MIN;
    }
    else {
        printf("list: ");
        for (int i=0; i<stack->used; i++) {
            printf("%d", stack->values[i]);
            if (i+1<stack->used) printf(",");
        }
        printf("\n");
        return true;
    }
}

int pop(tStack *stack) {
    if (stack->used==0) {
        printf("pop failed: empty stack\n");
        return INT_MIN;
    }
    else {
        int ret = stack->values[stack->used-1];
        printf("pop %d\n", ret);
        stack->used--;
        return ret;
    }
}

int top(tStack *stack) {
    if (stack->used==0) {
        printf("top failed: empty stack\n");
        return INT_MIN;
    }
    else {
        int ret = stack->values[stack->used-1];
        printf("top = %d\n", ret);
        return ret;
    }
}

tStack* init(int capacity) {
    printf("init\n");
    int *values = malloc(capacity*sizeof(int));
    tStack *stack = malloc(sizeof(tStack));
    stack->capacity = capacity;
    stack->values = values;
    stack->used = 0;
    return stack;
}

int pl() { printf("----------------\n"); }

int main() {
    srand(time(NULL));

    tStack *stack = init(50);

    dump(stack);   
    push(rand()%100, stack);
    dump(stack);
    push(rand()%100, stack);
    push(rand()%100, stack);
    dump(stack);
    list(stack);
    top(stack);
    push(rand()%100, stack);
    dump(stack);
    list(stack);
    top(stack);

    pop(stack);
    dump(stack);
    list(stack);
    top(stack);
}