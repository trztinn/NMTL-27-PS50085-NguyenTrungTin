#include <stdio.h>
#include <stdlib.h> // Bắt buộc phải có để dùng malloc, realloc, free

int main() {
    int n;
    printf("Nhap so luong hoc sinh ban dau: ");
    scanf("%d", &n);

    // ==========================================================
    // BƯỚC 1: CẤP PHÁT BAN ĐẦU (Khởi tạo mảng động bằng malloc)
    // ==========================================================
    int *diem = (int*) malloc(n * sizeof(int));
    
    // Luôn kiểm tra xem hệ điều hành có cấp phát thành công không
    if (diem == NULL) {
        printf("Bo nho day, cap phat that bai!\n");
        return 1; 
    }

    // Nhập điểm cho n học sinh ban dau
    printf("\n--- Nhap diem cho %d hoc sinh ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Diem hoc sinh %d: ", i + 1);
        scanf("%d", &diem[i]); // Sử dụng như mảng bình thường
    }

    // ==========================================================
    // BƯỚC 2: NỚI RỘNG MẢNG (Sử dụng realloc khi có học sinh mới)
    // ==========================================================
    int them;
    printf("\nNhap so hoc sinh moi chuyen vao lop: ");
    scanf("%d", &them);
    
    int n_moi = n + them; // Kích thước mới của mảng

    // Dùng con trỏ tạm để hứng vùng nhớ mới nhằm đảm bảo an toàn dữ liệu
    int *vung_nho_moi = (int*) realloc(diem, n_moi * sizeof(int));
    
    if (vung_nho_moi == NULL) {
        printf("Khong the noi rong mang! Giu nguyen mang cu.\n");
    } else {
        diem = vung_nho_moi; // Cập nhật con trỏ chính sang vùng nhớ mới thành công
        
        // Nhập điểm tiếp cho các học sinh mới thêm vào từ vị trí cũ (n)
        printf("--- Nhap diem cho %d hoc sinh moi ---\n", them);
        for (int i = n; i < n_moi; i++) {
            printf("Diem hoc sinh moi %d: ", i + 1);
            scanf("%d", &diem[i]);
        }
        n = n_moi; // Cập nhật lại tổng số học sinh hiện tại
    }

    // ==========================================================
    // BƯỚC 3: IN KẾT QUẢ XUẤT DỮ LIỆU
    // ==========================================================
    printf("\n--- Danh sach diem so hien tai cua lop ---\n");
    for (int i = 0; i < n; i++) {
        printf("Hoc sinh %d: %d diem\n", i + 1, diem[i]);
    }

    // ==========================================================
    // BƯỚC 4: GIẢI PHÓNG BỘ NHỚ (free)
    // ==========================================================
    // Trả lại vùng nhớ Heap cho máy tính sau khi dùng xong để tránh rò rỉ bộ nhớ
    free(diem); 
    diem = NULL; // Xóa con trỏ rác để tránh lỗi bảo mật


  
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// // Hàm nhập mảng và trả về con trỏ vùng nhớ đã cấp phát
// int* nhapMang(int *size) {
//     printf("Nhap so nguyen: ");
//     if (scanf("%d", size) != 1 || *size <= 0) {
//         printf("Kich thuoc mang khong hop le!\n");
//         return NULL;
//     }

//     // Không cần ép kiểu (int*) trong C
//     int *arr = malloc(*size * sizeof(int)); 
//     if (arr == NULL) {
//         printf("Cap phat bo nho that bai!\n");
//         return NULL;
//     }

//     for (int i = 0; i < *size; i++) {
//         printf("Nhap phan tu thu %d: ", i + 1);
//         scanf("%d", &arr[i]);
//     }
//     return arr;
// }

// // Hàm tính tổng các phần tử trong mảng
// int tinhTong(int *arr, int size) {
//     int sum = 0;
//     for (int i = 0; i < size; i++) {
//         sum += arr[i];
//     }
//     return sum;
// }

// int main() {
//     int n1, n2;
    
//     // Nhập mảng 1
//     int *arr1 = nhapMang(&n1);
//     if (arr1 == NULL) return 1;

//     // Nhập mảng 2
//     int *arr2 = nhapMang(&n2);
//     if (arr2 == NULL) {
//         free(arr1); // Giải phóng mảng 1 nếu mảng 2 thất bại
//         return 1;
//     }

//     // Tính tổng và in kết quả
//     int tong1 = tinhTong(arr1, n1);
//     int tong2 = tinhTong(arr2, n2);
    
//     printf("Tong cua hai mang la: %d\n", tong1 + tong2);

//     // Dọn dẹp bộ nhớ
//     free(arr1);
//     free(arr2);

//     return 0;
// }