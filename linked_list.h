#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct node {
    void *data;
    struct node *next;
} Node;

typedef struct linkedList {
    Node *head;
    size_t size; //Number of elements in the list
} LinkedList;

//Function prototypes
extern LinkedList* CreateLinkedList();
extern void DestroyLinkedList(LinkedList *list);

//I don't usually use setters and getters but since this is my own implementation not everyone will know how to use them
extern void Append(LinkedList *list, void *data);
extern void InsertAt(LinkedList *list, void *data, size_t index);
extern void RemoveAt(LinkedList *list, size_t index);

extern void* GetAt(const LinkedList *list, size_t index);
extern size_t GetSize(const LinkedList *list);

#endif
