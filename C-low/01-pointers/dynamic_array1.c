#include <stdio.h>
#include <stdlib.h> // Bắt buộc phải có để dùng malloc, realloc, free

int main() {
    int x;
    printf("Nhap so nguyen x: ");
    if (scanf("%d", &x) != 1 || x <= 0) {
        printf("Nhap khong hop le!\n");
        return 1;
    }

    int *arr = (int*) malloc(x * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }
    for (int i = 0; i < x; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int y;
    printf("Nhap so nguyen y: ");
    if (scanf("%d", &y) != 1 || y <= 0) {
        printf("Nhap khong hop le!\n");
        free(arr);
        return 1;
    }

    int *arr2 = (int*) malloc(y * sizeof(int));
    if (arr2 == NULL) {
        printf("Cap phat bo nho that bai!\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < y; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += arr[i];
    }
    int sum2 = 0;
    for (int i = 0; i < y; i++) {
        sum2 += arr2[i];
    }
    int sum3 = sum + sum2;
    printf("Tong cua hai mang la: %d\n", sum3);
    free(arr);
    free(arr2);
    arr = NULL;
    arr2 = NULL;
    return 0;
}

