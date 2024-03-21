#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct elem {
   int value;
   struct elem *next;
} elem;

typedef struct pilha {
   int count;
   struct elem *topo;
} pilha;

void pp(char* msg, void* addr) {
   printf("%s %p\n", msg, addr);
}

elem *push(pilha *p, int valor) {
   elem *novo = (elem*) malloc(sizeof(elem));
   if (novo) {
      novo->value = valor;
      novo->next = p->topo;
      p->topo = novo;
      p->count++;
   }
   else {
      printf("erro ao alocar memoria\n");
   }
}

int pop(pilha *p) {
   if (p->topo==NULL) {
      printf("pilha vazia\n");
      return INT_MIN;
   } else {
      elem *ptr = p->topo;
      int valor = ptr->value;
      p->topo = ptr->next;
      free(ptr);
      return valor;
   }
}

void print_stack(pilha *p) {
   elem *ptr = p->topo;
   if (ptr != NULL) {
      while (ptr!=NULL) {
         printf("%d", ptr->value);
         ptr = ptr->next;
         if (ptr!=NULL) printf(",");
      }
      printf("\n");
   }
   else {
      printf("pilha vazia\n");
   }
}

int top(pilha *p) {
   if (p->topo == NULL) {
      printf("pilha vazia\n");
      return INT_MIN;
   }
   else {
      printf("topo = %d\n", p->topo->value);
      return p->topo->value;
   }
}

int isEmpty(pilha *p) {
   if (p->topo == NULL) {
      printf("pilha vazia\n");
      return 1;
   }
   else {
      printf("pilha nao vazia\n");
      return 0;
   }
}

int main() {
   pilha *pi = (pilha*) malloc(sizeof(pilha));
   pi->count = 0;
   pi->topo = NULL;

   // push
   push(pi, 1);
   top(pi);

   push(pi, 3);
   top(pi);

   
   push(pi, 4);
   top(pi);

   push(pi, 7);
   top(pi);


   print_stack(pi);

   
   // pop
   printf("pop %d\n", pop(pi));
   top(pi);

   printf("pop %d\n", pop(pi));
   printf("pop %d\n", pop(pi));
   printf("pop %d\n", pop(pi));

   if (isEmpty(pi)) {
      printf("pilha vazia\n");
   }
   else {
      printf("pilha nao vazia\n");
   }
   
   printf("pop %d\n", pop(pi));
   print_stack(pi);
   
}