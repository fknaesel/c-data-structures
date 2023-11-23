#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, size=0;
    int stack[50];
    memset(stack,0,sizeof(stack));

    // push
    stack[size] = rand()%100;
    size++;
    // push
    stack[size] = rand()%100;
    size++;
    // push
    stack[size] = rand()%100;
    size++;

    // top
    printf("topo = %d\n", stack[size-1]);

    // list
    for (i=size-1; i>=0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    // pop
    stack[size-1] = 0;
    size--;
    
    // top
    printf("top = %d\n", stack[size-1]);
}