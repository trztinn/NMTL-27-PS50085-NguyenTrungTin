#include <stdio.h>
#include <stdlib.h> // Bắt buộc phải có để dùng malloc, realloc, free

int main() {
    int n;   
    printf("Nhap so luong hoc sinh: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Nhap khong hop le!\n");
        return 1;
    }
    char **mshs = (char**) malloc(n * sizeof(char*));
    if (mshs == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }
    float *diemthi = (float*) malloc(n * sizeof(float));
    if (diemthi == NULL) {
        printf("Cap phat bo nho that bai!\n");
        free(mshs);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap mshs %d: ", i + 1);
        mshs[i] = (char*) malloc(20 * sizeof(char));
        if (mshs[i] == NULL) {
            printf("Cap phat bo nho that bai!\n");
            for (int j = 0; j < i; j++) {
                free(mshs[j]);
            }
            free(mshs);
            free(diemthi);
            return 1;
        }
        scanf("%s", mshs[i]);  
        printf("Diem thi cua %s: ", mshs[i]);    
        if (scanf("%f", &diemthi[i]) != 1 || diemthi[i] < 0.0 || diemthi[i] > 10.0) {
            printf("Nhap khong hop le!\n");
            free(diemthi);
            for (int j = 0; j <= i; j++) {
                free(mshs[j]);
            }
            free(mshs);
            return 1;     
        }
    }

    printf("\n--- Danh sach diem so hien tai cua lop ---\n");

    for (int i = 0; i < n; i++) {
        if (diemthi[i] >= 9.0) {
            printf("%s \t: %0.1f diem \t- Xuat sac\n", mshs[i], diemthi[i]);
        } else if (diemthi[i] >= 8.0) {
            printf("%s \t: %0.1f diem \t- Gioi\n", mshs[i], diemthi[i]);
        } else if (diemthi[i] >= 6.5) {
            printf("%s \t: %0.1f diem \t- Kha\n", mshs[i], diemthi[i]);
        } else if (diemthi[i] >= 5.0) {
            printf("%s \t: %0.1f diem \t- Trung binh\n", mshs[i], diemthi[i]);
        } else {
            printf("%s \t: %0.1f diem \t- Yeu\n", mshs[i], diemthi[i]);
        }
    }
    free(diemthi);
    diemthi = NULL; 
    for (int i = 0; i < n; i++) {
        free(mshs[i]);
    }
    free(mshs);
    mshs = NULL;
    return 0;
}

