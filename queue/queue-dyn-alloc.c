#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // memset
#define MAX 100

/**
 * @author Frank Juergen Knaesel
 * @date 2024-03-21
 * @brief This is an implementation of a Queue (FIFO) Data Strucure using Memory Dynamic Allocation
 * @details It uses some functions to initialize/create a queue,
 * insert at the end, remove from the front,
 * and list the queue elements (front->back)
*/

typedef struct tNode {
   int info;
   struct tNode *next;
} tNode;

typedef struct tQueue {
   int count;
   tNode *front;
   tNode *back;
} tQueue;

/**
 * Create a new FIFO Queue
 * @returns The pointer to the created queue
*/
tQueue *createQueue() {
   tQueue *q = malloc(sizeof(tQueue));
   q->count = 0;
   q->front = NULL;
   q->back = NULL;
   return q;
}

/**
 * Insert an element at the back of the Queue
 * @param q The queue pointer
 * @param iValue The value you want to insert at the back of the Queue
 * @returns The inserted value, or zero if there isnt enough memory
*/
int enQueue(tQueue *q, int iValue) {
   tNode *new = malloc(sizeof(tNode));
   if (new != NULL) {
      new->info = iValue;
      new->next = NULL;
      if (q->back == NULL) {
         // Queue is empty
         q->front = new;
         q->back = new;
         q->count++;
      }
      else {
         q->back->next = new;
         q->back = new;
         q->count++;
      }
      printf("Enqueue: %d\n", iValue);
      return iValue;
   }
   else {
      printf("Not enough memory to enqueue %d\n", iValue);
      return 0;
   }
}

/**
 * Removes the element at the front of the Queue
 * @param q The queue pointer
 * @return The removed node value, or zero if the queue is empty
*/
int deQueue(tQueue *q) {
   tNode *del = q->front;
   if (del != NULL) {
      int ret = del->info;
      if (del->next == NULL) { // only one node
         q->front = NULL;
         q->back = NULL;
         q->count--;
         free(del);
      }
      else {
         q->front = q->front->next;
         q->count--;
         free(del);
      }
      printf("deQueue: %d\n", ret);
      return ret;
   }
   else {
      printf("Empty Queue: Nothing do deQueue\n");
      return 0;
   }
}

/**
 * Shows and returns thefront node value
 * @param q The queue pointer
 * @returns The front node value, or zero if the node is empty
*/
int Front(tQueue *q) {
   if (q->front != NULL) {
      printf("Front %d\n", q->front->info);
      return q->front->info;
   } else {
      printf("Front Empty\n");
      return 0;
   }
}

/**
 * Shows and returns the back node value
 * @param q The queue pointer
 * @returns The last node value, or zero if the queue is empty
*/
int Back(tQueue *q) {
   if (q->back != NULL) {
      printf("Back %d\n", q->back->info);
      return q->back->info;
   } else {
      printf("Back Empty\n");
      return 0;
   }
}

/**
 * Print Queue content
 * @param q The queue pointer
 * @returns none
*/
void PrintQueue(tQueue *q) {
   printf("Queue: ");
   tNode *node = q->front;
   while (node != NULL) {
      node->next != NULL ? printf("%d,", node->info) : printf("%d", node->info);
      node = node->next;
   }
   printf(" count=%d *end*\n", q->count);
}

int main() {
   tQueue *q = createQueue();
   PrintQueue(q);

   enQueue(q, 5);
   PrintQueue(q);
   
   enQueue(q, 3);
   PrintQueue(q);
   
   enQueue(q, 1);
   PrintQueue(q);
   
   deQueue(q);
   PrintQueue(q);

   deQueue(q);
   PrintQueue(q);

   deQueue(q);
   PrintQueue(q);

   deQueue(q);
   PrintQueue(q);
   
}