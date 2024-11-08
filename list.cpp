#include "list.h"
#include <stdio.h>

void push(Node *&head, char data)
{
  Node* temp = new Node;
  temp->key = data;
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

void show(Node *&head)
{
  Node* temp = head;
  while (temp != NULL) {
    printf("%c ", temp->key);
    temp = temp->next;
  }
}
