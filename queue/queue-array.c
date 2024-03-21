#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // memset
#define MAX 100

/**
 * @author Frank Juergen Knaesel
 * @date 2024-03-21
 * @brief This is an implementation of a Queue (FIFO) Data Strucure using arrays
 * @details It uses some functions to initialize/create a queue,
 * insert at the end, remove from the front,
 * and list the queue elements, starting from the front to the back
*/

typedef struct tQueue {
   int capacity;
   int front;
   int rear;
   int size;
   int *array;
} tQueue;

/**
 * @param capacity The number of elements the queue may contain
 * @returns A pointer to the recently created queue(array)
*/
struct tQueue* createQueue(int capacity) {
   struct tQueue* queue = (tQueue*) malloc(sizeof(tQueue));
   queue->capacity = capacity;
   queue->size = 0;
   queue->front = 0;
   queue->rear = 0;
   queue->array = (int*) malloc(sizeof(int) * capacity);
   memset(queue->array, 0, sizeof(int) * queue->capacity);
   return queue;   
}
/**
 * Insert an element at the end of the queue
 * @param A pointer to the queue
 * @param The Value you want to Insert
*/
int enQueue(tQueue *queue, int iValueToInsert) {
   if (queue->size == queue->capacity) {
      printf("Not enough room to Enqueue\n");
   }
   else {
      queue->array[queue->rear] = iValueToInsert;
      queue->size++;
      queue->rear++;
      printf("Enqueue: %d\n", iValueToInsert);
   }
}

/**
 * Prints the contect of the queue, starting from the start to end
 * @param queue A pointer to the queue you want to print
*/
void PrintList(tQueue *q) {
   printf("Queue Dump: ");
   int i;
   for (i=q->front; i<q->rear; i++) {
      i==q->front ? printf("%d",q->array[i]) : printf(",%d",q->array[i]);
   }
   printf(" | size=%d | front=%d | rear=%d | *End*\n", q->size, q->front, q->rear);
}

int deQueue(tQueue *q) {
   if (q->size == 0) {
      printf("The queue is empty, nothing do dequeue\n");
   }
   else {
      int ret = q->array[q->front];
      q->array[q->front] = 0;
      q->front++;
      q->size--;
      printf("Dequeue: %d\n", ret);
      return ret;
   }

}

int main() {
   tQueue *q = createQueue(100);
   PrintList(q);
   enQueue(q,5);
   PrintList(q);
   enQueue(q,7);
   PrintList(q);
   enQueue(q,3);
   PrintList(q);
   deQueue(q);
   PrintList(q);
   enQueue(q,6);
   PrintList(q);
   enQueue(q,4);
   PrintList(q);
   deQueue(q);
   PrintList(q);
   enQueue(q,8);
   PrintList(q);
   enQueue(q,9);
   PrintList(q);

   printf("--- end ---\n");
}