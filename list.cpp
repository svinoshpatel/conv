#include "list.h"
#include <stdio.h>

void push(Node *&head, datatype data, int i)
{
  Node* temp = new Node;
  temp->key[i] = data;
  temp->next = head;
  head = temp;
}

void pop(Node *&head)
{
  if (head == NULL)
    printf("\nStack is empty\n");
  else {
    Node *temp = head;
    head = temp->next;
    delete temp;
  }
}

// void show(Node *&head)
// {
//   Node* temp = head;
//   while (temp != NULL) {
//     printf("%c ", temp->key);
//     temp = temp->next;
//   }
// }

// void enqueue(Node *&front, Node *&rear, datatype data)
// {
//   Node *temp = new Node;
//   temp->key = data;
//   temp->next = NULL;
//   if (front == NULL)
//     front = temp;
//   else
//     rear->next = temp;
//   rear = temp;
// }

// void dequeue(Node *&front)
// {
//   if (front == NULL)
//     printf("\nQueue is empty\n");
//   else {
//     Node *temp = front;
//     front = temp->next;
//     delete temp;
//   }
// }

// void add_begin(Node *&first, Node *&last, datatype data)
// {
//   Node *temp = new Node;
//   temp->key = data;
//   temp->next = first;
//   temp->previous = NULL;
//   if (first != NULL) {
//     first->previous = temp;
//   } else {
//     last = temp;
//   }
//   first = temp;
// }

// void add_end(Node *&first, Node *&last, datatype data)
// {
//   Node *temp = new Node;
//   temp->key = data;
//   temp->next = NULL;
//   temp->previous = last;
//   if (temp->previous != NULL)
//     last->next = temp;
//   if (temp->previous == NULL)
//     first = temp;
//   last = temp;
// }

// void del_begin(Node *&first, Node *&last)
// {
//   if (first == NULL) {
//     printf("\nList is empty\n");
//     return;
//   }
//   Node *temp = first;
//   first = temp->next;
//   if (first != NULL)
//     first->previous = NULL;
//   if (first == NULL)
//     last = NULL;
//   delete temp;
// }

// void del_end(Node *&first, Node *&last)
// {
//   if (last == NULL) {
//     printf("\nList is empty\n");
//     return;
//   }
//   Node *temp = last;
//   last = temp->previous;
//   if (last != NULL)
//     last->next = NULL;
//   if (last == NULL)
//     first = NULL;
//   delete temp;
// }

// Node *search(Node *&first, datatype data)
// {
//   Node *temp = first;
//   while (temp != NULL) {
//     if (temp->key == data)
//       return temp;
//     else
//      temp = temp->next;
//   }
//   printf("The given value is absent in the list\n");
//   return NULL;
// }

// void add_mid(Node *&first, Node *&last, datatype data, datatype element)
// {
//   Node *pkey = search(first, element);
//   if (pkey->next == NULL)
//     add_end(first, last, data);
//   else {
//     Node *temp = new Node;
//     temp->key = data;
//     temp->next = pkey->next;
//     temp->previous = pkey;
//     pkey->next = temp;
//     (temp->next)->previous = temp;
//   }
// }

// void del_mid(Node *&first, Node *&last, datatype data)
// {
//   Node *pkey = search(first, data);
//   if (pkey->previous == NULL)
//     del_begin(first, last);
//   if (pkey->next == NULL)
//     del_end(first, last);
//   else
//     {
//       (pkey->previous)-> next = pkey->next;
//       (pkey->next)->previous = pkey->previous;
//       delete pkey;
//     }
// }
