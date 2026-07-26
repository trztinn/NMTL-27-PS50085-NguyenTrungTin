#include <stdio.h>
#include <string.h>

// Định nghĩa cấu trúc SinhVien
typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;

int main() {
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // Đọc bỏ ký tự Enter thừa

    SinhVien ds[n];

    // 1. Nhập thông tin sinh viên & Xếp loại học lực
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin sinh vien %d ---\n", i + 1);
        printf("Ho va ten: ");
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = 0; // Xóa ký tự xuống dòng

        printf("Diem: ");
        scanf("%f", &ds[i].diem);
        getchar(); // Đọc bỏ ký tự Enter thừa

        // Xếp loại học lực trực tiếp trong vòng lặp
        if (ds[i].diem >= 9.0) {
            strcpy(ds[i].hocLuc, "Xuat sac");
        } else if (ds[i].diem >= 8.0) {
            strcpy(ds[i].hocLuc, "Gioi");
        } else if (ds[i].diem >= 6.5) {
            strcpy(ds[i].hocLuc, "Kha");
        } else if (ds[i].diem >= 5.0) {
            strcpy(ds[i].hocLuc, "Trung binh");
        } else {
            strcpy(ds[i].hocLuc, "Yeu");
        }
    }

    // 2. Sắp xếp danh sách theo điểm GIẢM DẦN (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // 3. Hiển thị danh sách sau khi sắp xếp
    printf("\n================ DANH SACH SINH VIEN (DIEM GIAM DAN) ================\n");
    printf("%-5s %-25s %-10s %-15s\n", "STT", "Ho va Ten", "Diem", "Hoc Luc");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-25s %-10.1f %-15s\n", i + 1, ds[i].hoTen, ds[i].diem, ds[i].hocLuc);
    }

    return 0;
}