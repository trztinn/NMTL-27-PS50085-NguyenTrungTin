#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 1. Tạo một nút mới (nút tự trỏ vào chính nó)
Node* createNode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Khong đủ bo nho!\n");
        exit(1);
    }
    p->data = x;
    p->next = p; // Khoi tao vong: tro lai chinh no
    return p;
}

// 2. Them phan tu vao cuoi danh sach
void insertEnd(Node **head, int x) {
    Node *newNode = createNode(x);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    // Tim nut cuoi cung (nut dang tro ve head)
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head; // Noi nut moi ve lai head
}

// 3. Them phan tu vao dau danh sach
void insertHead(Node **head, int x) {
    Node *newNode = createNode(x);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    // Tim nut cuoi cung de cap nhat lai con tro next cua no
    while (temp->next != *head) {
        temp = temp->next;
    }

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode; // Cap nhat head moi
}

// 4. In danh sach
void printList(Node *head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    Node *temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

// 5. Giai phong bo nho danh sach
void freeList(Node **head) {
    if (*head == NULL) return;

    Node *current = *head;
    Node *nextNode;

    // Cat đut vòng tròn truoc khi free
    Node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = NULL; // Chuyen ve danh sach đon thuong đe de free

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main() {
    Node *head = NULL;

    // Them phan tu vao cuoi
    insertEnd(&head, 5);
    insertEnd(&head, 10);
    insertEnd(&head, 15);

    // Them phan tu vao dau
    insertHead(&head, 1);

    // In danh sach (Ket qua mong đoi: 1 -> 5 -> 10 -> 15 -> (head: 1))
    printList(head);

    // Dọn dẹp bộ nhớ
    freeList(&head);

    return 0;
}