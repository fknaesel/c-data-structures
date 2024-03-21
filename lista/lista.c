#include <stdio.h>
#include <stdlib.h> //rand, srand
#include <time.h>   // time
#include <windows.h>   // Sleep

/**
 * @author Frank Juergen Knaesel
 * @brief This is an implementation of a linked list and it has the following functions:
 * - void printList(tList *list);
 * - void insertStart(tList *list, int value);
 * - void insertEnd(tList *list, int value);
 * - int insertAfter(tList *list, int iWhere, int iValueToInsert);
 * - int insertBefore(tList *list, int iWhere, int iValueToInsert);
 * - int deleteFirst(tList *list);
 * - int deleteLast(tList *list);
 * - int deleteByValue(tList *list, int valueToDelete);
 * - int bubbleSortValue(tList *list);
**/

typedef struct tNode {
   int info;
   struct tNode *next;
} tNode;

typedef struct tList {
   int count;
   struct tNode *head;
} tList;

void printList(tList *list) {
   tNode *node = list->head;
   printf("list dump: ");
   while (node != NULL)
   {
      printf("%d ", node->info);
      node = node->next;
   }
   printf("*end* count=%d\n",list->count);
}

void insertStart(tList *list, int value) {
   // allocate memory for new node
   tNode *new = (tNode*) malloc(sizeof(tNode)); 
   // store value on the node
   new->info = value; 
   // next of new node points to head
   new->next = list->head; 
   // list head points to new node
   list->head = new; 
   // increase node counter
   list->count++;
   printf("InsertStart: %d\n", value);

}

void insertEnd(tList *list, int value) {
   tNode *node = list->head;
   // if list is empty
   if (node==NULL) {
      tNode *new = (tNode*) malloc (sizeof(tNode)); // malloc new node
      if (new) {
         new->info = value; // store node value
         new->next = NULL; // new node is the last, do it doesnt have a next node
         list->head = new; // list head points to this new node
         list->count++;
         printf("InsertEnd: %d\n", value);
      }      
      else {
         printf("InsertEnd: Not enough memory\n");
      }
   }
   else {
      // get the last node
      while (node->next != NULL) {
         node = node->next;
      }
      tNode *new = (tNode*) malloc (sizeof(tNode)); // malloc new node
      if (new) {
         new->info = value; // store node value
         node->next = new; // next of last node points to new node
         new->next = NULL; // next of new node points to NULL
         list->count++;
         printf("Insert End: %d\n", value);
      }
      else {
         printf("Not enough memory\n");
      }
   }
}

int insertAfter(tList *list, int iWhere, int iValueToInsert) {
   tNode *node = list->head;
   while (node != NULL && node->info != iWhere) {
      node = node->next;
   }
   if (node==NULL) {
      printf("Value %d not found\n", iWhere);
      return 0;
   }
   else {
      tNode *new = (tNode*) malloc(sizeof(tNode));
      if (new==NULL) {
         printf("Not enough memory!");
         return 0;
      }
      else {
         printf("Insert After %d -> %d\n",iWhere,iValueToInsert);
         new->info = iValueToInsert;
         new->next = node->next;
         node->next = new;
         list->count++;
         return iValueToInsert;
      }
   }
}

int insertBefore(tList *list, int iWhere, int iValueToInsert) {
   tNode *node = list->head;
   tNode *prev = NULL;
   while (node != NULL && node->info != iWhere) {
      prev = node;
      node = node->next;
   }
   if (node==NULL) {
      printf("value %d not found\n", iWhere);
      return 0;
   }
   else {
      tNode *new = (tNode*) malloc(sizeof(tNode));
      if (new==NULL) {
         printf("Not enough memory!");
         return 0;
      }
      else {
         if (prev==NULL) {
            new->info = iValueToInsert;
            new->next = node;
            list->head = new;
            list->count++;
         }
         else {
            new->info = iValueToInsert;
            new->next = node;
            prev->next = new;
            list->count++;
         }
         printf("Insert Before %d <- %d\n", iValueToInsert, iWhere);
         return iValueToInsert;
      }
   }
}

int deleteFirst(tList *list) {
   tNode *del = list->head;
   if (del==NULL) {
      return 0;
   }
   int ret = del->info;
   list->head = list->head->next;
   list->count--;
   free(del);
   printf("DeleteFirst %d\n", ret);
   return ret;
}

int deleteByValue(tList *list, int valueToDelete) {
   // IF the list is empty, there is nothing to delete
   if (list->head == NULL) {
      printf("Empty list, nothing to delete\n");
      return 0;
   }
   // get first node
   tNode *node = list->head;
   tNode *prev = NULL;
   // find the node you want to delete
   while(node->info != valueToDelete && node->next != NULL) {
      prev = node;
      node = node->next;
   }
   if (node->info == valueToDelete) {
      // found
      printf("Deleted %d\n", valueToDelete);
      if (prev==NULL) {
         // Will delete the first node
         list->head = node->next;
         free(node);
         list->count--;
         return valueToDelete;
      }
      else {
         // update the node before the last to point to the end
         prev->next = node->next;
         free(node);
         list->count--;
         return valueToDelete;
      }
   }
   else {
      printf("Value %d not found\n", valueToDelete);
      return 0;
   }

}

int deleteLast(tList *list) {
   int ret;
   if (list->head == NULL) {
      // List is empty, there is nothing to delete
      printf("Empty list, nothing to delete\n");
      return 0;
   }
   // get the last and second last node
   tNode *last = list->head; // get head
   tNode *prev = list->head; // previous node
   // get to the last and previous node
   while (last->next != NULL) {
      prev = last;
      last = last->next;
   }
   if (prev==last) {
      // there is only one node, update the head
      ret = last->info;
      free(last);
      list->head = NULL;
      list->count--;
      printf("DeleteLast: %d\n", ret);
   }
   else {
      // update the node before the last to point to the end
      ret = last->info;
      prev->next = NULL;
      list->count--;
      free(last);
      printf("DeleteLast: %d\n", ret);
   }
   return ret;
}

int bubbleSortSwapValue(tList *list) {
   printf("Sorting...\n");
   printList(list);
   int temp;
   int fChanged = 1;
   if (list->head == NULL) {
      printf("List is Empty: Nothing to Sort\n");
   }
   else if (list->head->next == NULL) {
      printf("List has only one element: Nothing to Sort\n");
   }
   else {
      while (fChanged) {
         fChanged = 0;
         tNode *node = list->head;
         tNode *next = node->next;
         while (next!= NULL) {
            if (node->info > next->info) {
               temp = node->info;
               node->info = next->info;
               next->info = temp;
               fChanged = 1;
               printList(list);
            }
            node = next;
            next = next->next;
         }
      }
   }
   printf("Sorting Finished!\n");   
}

int bubbleSortSwapPointers(tList *list) {
   printf("Sorting...\n");
   printList(list);
   int temp;
   int fChanged = 1;
   if (list->head == NULL) {
      printf("List is Empty: Nothing to Sort\n");
   }
   else if (list->head->next == NULL) {
      printf("List has only one element: Nothing to Sort\n");
   }
   else {
      while (fChanged) {
         fChanged = 0;
         tNode *prev = NULL;
         tNode *ptr1 = list->head;
         tNode *ptr2 = ptr1->next;
         while (ptr2 != NULL) {
            if (ptr1->info > ptr2->info) {
               if (prev==NULL) {
                  // if there is no previous node, the head pointer should be changed
                  tNode *temp = ptr2->next;
                  ptr2->next = ptr1;
                  ptr1->next = temp;                  
                  list->head = ptr2;
                  // prepare pointers for next pass
                  prev = ptr2;
                  ptr2 = temp;
               }
               else {
                  tNode *temp = ptr2->next;
                  ptr2->next = ptr1;
                  ptr1->next = temp;                  
                  prev->next = ptr2;
                  // prepare pointers for next pass
                  prev = ptr2;
                  ptr2 = temp;
                  
               }
               fChanged = 1;
               printList(list);
               Sleep(1000);
            }
            else {
               // no swap needed, moving to next
               prev = ptr1;
               ptr1 = ptr1->next;
               ptr2 = ptr2->next;
            }
            
         }
      }
   }
   printf("Sorting Finished!\n");   
}

void printListDetails(tList *list) {
   printf("ListDetails Start\n");
   tNode *node = list->head;
   while (node != NULL) {
      printf("addr=%p value=%d next=%p\n",node, node->info, node->next);
      node = node->next;
   }
   printf("ListDetails End\n");
}


int main() {
   srand(time(NULL));

   // initialize list
   tList *list = (tList *)malloc(sizeof(tList));
   list->count = 0;
   list->head = NULL;

   int arr[] = {1,6,4,7,2,5,3};
   for (int i=0; i<sizeof(arr)/sizeof(int); i++) {
      insertEnd(list, arr[i]);   
   }
   printList(list);

   bubbleSortSwapValue(list);
   bubbleSortSwapPointers(list);

   printf("--- end ---\n");

}