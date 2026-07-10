#include <stdio.h>

int main() {
    int age = 18;      // Biến thường lưu giá trị số nguyên
    int *ptr = &age;   // Con trỏ ptr lưu ĐỊA CHỈ của biến age

    printf("Gia tri cua bien age: %d\n", age);
    printf("Dia chi cua bien age trong bo nho: %p\n", &age);
    printf("Con tro ptr dang tro den dia chi: %p\n", ptr);
    printf("Gia tri tai vung nho ma ptr tro den: %d\n", *ptr);

    return 0;
}