#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void insertEnd(Node **head, int x) {
    Node *newNode = createNode(x);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    Node *head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    
    printf("List:");
    while (head != NULL) {
        printf(" %d ", head->data);
        head = head->next;
    }

    return 0;
}