#include <stdio.h>
#include <string.h>

int main() {
    char mssv[20];
    char hoTen[50];
    int namSinh;
    int tuoi;
    float diemTB;

    printf("Nhap ma so sinh vien (MSSV): ");
    scanf("%s", mssv);
    
    while (getchar() != '\n'); 

    printf("Nhap Ho va Ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0'; 

    printf("Nhap Nam Sinh: ");
    scanf("%d", &namSinh);

    printf("Nhap Diem Trung Binh: ");
    scanf("%f", &diemTB);

    tuoi = 2026 - namSinh;

    printf("\nNHAP MON LAP TRINH\n");
    printf("-----------------------------------\n");
    printf("Ma so sinh vien: [%s]\n", mssv);
    printf("Ho Va Ten: [%s]\n", hoTen);
    printf("Nam sinh: [%d nhap]\n", namSinh);
    printf("Tuoi: [%d]\n", tuoi);
    printf("Diem Trung Binh: [%.1f]\n", diemTB);
    printf("-----------------------------------\n");

    return 0;
}