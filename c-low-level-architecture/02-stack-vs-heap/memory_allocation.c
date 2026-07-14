#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Khai báo các biến nằm trên STACK
    int local_a = 10;
    int local_b = 20;

    // 2. Cấp phát bộ nhớ cho các biến nằm trên HEAP
    int *heap_ptr1 = (int*) malloc(sizeof(int));
    int *heap_ptr2 = (int*) malloc(sizeof(int));

    // Kiểm tra xem malloc có thành công không
    if (heap_ptr1 == NULL || heap_ptr2 == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }

    // Gán giá trị cho vùng nhớ trên Heap
    *heap_ptr1 = 100;
    *heap_ptr2 = 200;

    // 3. In địa chỉ để so sánh
    printf("=== BIEN TREN STACK ===\n");
    printf("Dia chi cua local_a: %p\n", (void*)&local_a);
    printf("Dia chi cua local_b: %p\n", (void*)&local_b);

    printf("\n=== BIEN TREN HEAP ===\n");
    // Lưu ý: heap_ptr1 bản chất đã lưu địa chỉ vùng Heap rồi, nên không dùng dấu & ở đây nữa
    printf("Dia chi vung nho heap_ptr1 tro toi: %p\n", (void*)heap_ptr1);
    printf("Dia chi vung nho heap_ptr2 tro toi: %p\n", (void*)heap_ptr2);

    // 4. Giải phóng bộ nhớ Heap
    free(heap_ptr1);
    free(heap_ptr2);

    return 0;
}