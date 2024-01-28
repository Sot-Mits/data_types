#include <stdlib.h>
#include <stddef.h>

typedef struct node {
    void *data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    size_t size; // Number of elements in the list
} LinkedList;

LinkedList* CreateLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

void DestroyLinkedList(LinkedList *list) {
    Node *current = list->head;
    Node *next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
    return;
}

void Append(LinkedList *list, void *data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;

        if (list->head == NULL) {
            list->head = newNode;
        } else {
            Node *current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        list->size++;
    }
    return;
}

void InsertAt(LinkedList *list, void *data, size_t index) {
    if (index > list->size) {
        // Invalid index
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;

        if (index == 0) {
            newNode->next = list->head;
            list->head = newNode;
        } else {
            Node *current = list->head;
            for (size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        list->size++;
    }
    return;
}

void RemoveAt(LinkedList *list, size_t index) {
    if (index >= list->size) {
        // Invalid index
        return;
    }

    Node *temp;
    if (index == 0) {
        temp = list->head;
        list->head = list->head->next;
    } else {
        Node *current = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }

    free(temp);
    list->size--;
    return;
}

void* GetAt(const LinkedList *list, size_t index) {
    if (index >= list->size) {
        // Invalid index
        return NULL;
    }

    Node *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

size_t GetSize(const LinkedList *list) {
    return list->size;
}

