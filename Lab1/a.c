#include <stdio.h>
#include <stdlib.h> // Bắt buộc phải có để dùng malloc, realloc, free

int main() {
    int n;
    printf("Nhap so luong hoc sinh ban dau: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Nhap khong hop le!\n");
        return 1;
    }
    float *diem = (float*) malloc(n * sizeof(float));
    if (diem == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap diem hoc sinh %d: ", i + 1);
        if (scanf("%f", &diem[i]) != 1) {
            printf("Nhap khong hop le!\n");
            free(diem);
            return 1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("Hoc sinh %d: %.1f diem\n", i + 1, diem[i]);
        if (diem[i] < 0 || diem[i] > 10) {
            printf("Diem khong hop le! Diem phai nam trong khoang tu 0 den 10.\n");
            free(diem);
            return 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (diem[i] >= 9.0) {
            printf("Hoc sinh %d dat loai Xuat sac\n", i + 1);
        } else if (diem[i] >= 8.0) {
            printf("Hoc sinh %d dat loai Gioi\n", i + 1);
        } else if (diem[i] >= 6.5) {
            printf("Hoc sinh %d dat loai Kha\n", i + 1);
        } else if (diem[i] >= 5.0) {
            printf("Hoc sinh %d dat loai Trung binh\n", i + 1);
        } else {
            printf("Hoc sinh %d dat loai Yeu\n", i + 1);
        }
    }
    free(diem);
    diem = NULL; 
    return 0;
}

