#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);

    char name[n][50];
    float diemTB[n];

    for (int i = 0; i < n; i++) {
        float toan, ly, hoa;

        printf("\nNhap ten hoc sinh thu %d: ", i + 1);
        scanf("%s", name[i]);

        printf("Nhap diem toan: ");
        scanf("%f", &toan);

        printf("Nhap diem ly: ");
        scanf("%f", &ly);

        printf("Nhap diem hoa: ");
        scanf("%f", &hoa);

        diemTB[i] = (toan * 3 + ly * 2 + hoa) / 6;
    }

    printf("\n===== DANH SACH DIEM TRUNG BINH =====\n");
    for (int i = 0; i < n; i++) {
        printf("Hoc sinh %s co diem trung binh: %.1f\n", name[i], diemTB[i]);
    }

    return 0;
}