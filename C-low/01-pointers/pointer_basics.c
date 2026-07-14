#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main() {
    // int age = 18;      // Biến thường lưu giá trị số nguyên
    // int *ptr = &age;   // Con trỏ ptr lưu ĐỊA CHỈ của biến age

    // printf("Gia tri cua bien age: %d\n", age);
    // printf("Dia chi cua bien age trong bo nho: %p\n", &age);
    // printf("Con tro ptr dang tro den dia chi: %p\n", ptr);
    // printf("Gia tri tai vung nho ma ptr tro den: %d\n", *ptr);

    int a = 5, b = 10;
    swap(&a, &b);
    printf("Sau khi hoan doi: a = %d, b = %d\n", a, b);
    printf("-----------------------------------\n");

    int score = 90;
    int *p = &score; 
    printf("Gia tri cua bien score: %d\n", score);  
    printf("Dia chi cua bien score trong bo nho: %p\n", &score);
    *p = 95;
    printf("Gia tri cua bien score: %d\n", score);  
    printf("Dia chi cua bien score trong bo nho: %p\n", (void*)p);
    return 0;
}