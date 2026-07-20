#include <stdio.h>

int main() {
    int n;
    
    // 1. Nhập số lượng học sinh (Bắt lỗi nhập chữ hoặc n <= 0)
    printf("Nhap so luong hoc sinh: ");
    while (scanf("%d", &n) != 1 || n <= 0) {   
        while (getchar() != '\n'); // Xóa bộ nhớ đệm
        printf("Khong hop le! Vui long nhap so nguyen duong: ");
    }
    while (getchar() != '\n'); // Xóa phím Enter thừa sau khi nhập n thành công

    char name[n][50];
    float diemTB[n];

    for (int i = 0; i < n; i++) {
        float toan, ly, hoa;

        // 2. Nhập tên học sinh
        printf("\nNhap ten hoc sinh thu %d: ", i + 1);
        scanf("%s", name[i]);
        while (getchar() != '\n'); // Clear bộ nhớ sau khi nhập tên

        // 3. Nhập điểm Toán (0 - 10)
        printf("Nhap diem Toan: ");
        while (scanf("%f", &toan) != 1 || toan < 0 || toan > 10) {
            while (getchar() != '\n');
            printf("Diem khong hop le (0-10)! Nhap lai diem Toan: ");
        }
        while (getchar() != '\n');

        // 4. Nhập điểm Lý (0 - 10)
        printf("Nhap diem Ly: ");
        while (scanf("%f", &ly) != 1 || ly < 0 || ly > 10) {
            while (getchar() != '\n');
            printf("Diem khong hop le (0-10)! Nhap lai diem Ly: ");
        }
        while (getchar() != '\n');

        // 5. Nhập điểm Hóa (0 - 10)
        printf("Nhap diem Hoa: ");
        while (scanf("%f", &hoa) != 1 || hoa < 0 || hoa > 10) {
            while (getchar() != '\n');
            printf("Diem khong hop le (0-10)! Nhap lai diem Hoa: ");
        }
        while (getchar() != '\n');

        // 6. Tính điểm trung bình
        diemTB[i] = (toan * 3 + ly * 2 + hoa) / 6;
    }

    // 7. In danh sách kết quả
    printf("\n===== DANH SACH DIEM TRUNG BINH =====\n");
    for (int i = 0; i < n; i++) {
        printf("Hoc sinh %s co diem trung binh: %.1f\n", name[i], diemTB[i]);
    }

    return 0;
}