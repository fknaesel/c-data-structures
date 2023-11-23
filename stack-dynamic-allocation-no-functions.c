#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct elem {
   int value;
   struct elem *next;
} elem;

int main() {
   srand(time(NULL));
   elem *top = NULL;
   elem *new;
   elem *ptr;
   
   // push
   new = (elem*)malloc(sizeof(elem));
   new->value = rand()%100;
   new->next = top;
   top = new;
   printf("push: %d\n", new->value);

   // push
   new = (elem*)malloc(sizeof(elem));
   new->value = rand()%100;
   new->next = top;
   top = new;
   printf("push: %d\n", new->value);

   // push
   new = (elem*)malloc(sizeof(elem));
   new->value = rand()%100;
   new->next = top;
   top = new;
   printf("push: %d\n", new->value);

   // list
   if (top==NULL) {
      printf("top: stack is empty\n");
   } else {
      ptr = top;
      while (ptr!=NULL) {
         printf("%d", ptr->value);
         if (ptr->next!=NULL) printf(",");
         ptr = ptr->next;
      }
      printf("\n");
   }

   // top
   if (top==NULL) {
      printf("top: stack is empty\n");
   } else {
      printf("top: %d\n", top->value);
   }

   // pop
   if (top==NULL) {
      printf("pop: stack is empty\n");
   } else {
      ptr = top;
      printf("pop: %d\n", top->value);
      top = top->next;
      free(ptr);
   }

   // list
   if (top==NULL) {
      printf("top: stack is empty\n");
   } else {
      ptr = top;
      while (ptr!=NULL) {
         printf("%d", ptr->value);
         if (ptr->next!=NULL) printf(",");
         ptr = ptr->next;
      }
      printf("\n");
   }

     
}