#ifndef LIST_H
#define LIST_H

struct Node {
  char key;
  Node *next;
  Node *previous;
};

void push(Node *&head, char data);
void pop(Node *&head);
void show(Node *&head);

#endif
