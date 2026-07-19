#include <stdio.h>
#include <stdlib.h>

// 1. ĐỊNH NGHĨA MỘT NODE
struct Node {
    int data;           // Dữ liệu lưu trữ (ví dụ ở đây là số nguyên)
    struct Node* next;  // Con trỏ lưu địa chỉ của Node tiếp theo
};

// 2. HÀM TẠO MỘT NODE MỚI (Cấp phát động trên Heap)
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = value; // Gán dữ liệu
    newNode->next = NULL;  // Mặc định Node mới tạo chưa trỏ đi đâu cả
    return newNode;
}

// 3. HÀM CHÈN VÀO ĐẦU DANH SÁCH (Insert at Head)
void insertAtHead(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    
    // Cho Node mới trỏ tới Node đầu tiên hiện tại
    newNode->next = *head_ref;
    
    // Cập nhật lại Head chính là Node mới
    *head_ref = newNode;
}
void xoa(struct Node** head)    
{
    if (*head == NULL)
    {
        printf("Rong! \n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
};

// 4. HÀM IN DANH SÁCH (Duyệt qua từng Node)
void printList(struct Node* node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next; // Nhìn vào mảnh giấy để đi tới Node tiếp theo
    }
    printf("NULL\n"); // Kết thúc danh sách
}

// 5. HÀM GIẢI PHÓNG BỘ NHỚ (Rất quan trọng!)
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next; // Giữ lại địa chỉ node tiếp theo trước khi xoá node hiện tại
        free(temp);
    }
    printf("Da xoa toan bo danh sach khoi Heap!\n");
}

int main() {
    // Khởi tạo danh sách rỗng (Quản lý bằng con trỏ Head)
    struct Node* head = NULL;

    // Thêm các phần tử vào danh sách
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    insertAtHead(&head, 5);
    xoa(&head);
    // In kết quả ra màn hình (Sẽ in ngược lại vì chèn vào đầu: 30 -> 20 -> 10)
    printList(head);

    // Dùng xong nhớ dọn dẹp bộ nhớ trên Heap
    freeList(head);

    return 0;
}