#ifndef LIST_H
#define LIST_H

typedef char datatype;

struct Node {
  datatype key[50];
  Node *next;
  Node *previous;
};

void push(Node *&head, datatype key, int i);
void pop(Node *&head);
void show(Node *&head);
void enqueue(Node *&front, Node *&rear, datatype data);
void dequeue(Node *&front);
void add_begin(Node *&first, Node *&last, datatype data);
void add_end(Node *&first, Node*&last, datatype data);
void del_begin(Node *&first, Node *&last);
void del_end(Node *&first, Node *&last);
Node *search(Node *&first, datatype data);
void add_mid(Node *&first, Node *&last, datatype data, datatype element);
void del_mid(Node *&first, Node*&last, datatype data);

#endif
