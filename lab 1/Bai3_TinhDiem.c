#include <stdio.h>
#include <string.h>

int main() {
    char mssv[20];
    char hoTen[50];
    float diemToan, diemLy, diemHoa;
    float diemTrungBinh;

    // 1. Nhập dữ liệu từ bàn phím
    printf("Nhap ma so sinh vien (MSSV): ");
    scanf("%s", mssv);
    
    // Xóa bộ nhớ đệm để tránh trôi hàm fgets tiếp theo
    while (getchar() != '\n'); 

    printf("Nhap Ho va Ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0'; // Xóa ký tự xuống dòng ở cuối chuỗi

    printf("Nhap diem Toan: ");
    scanf("%f", &diemToan);

    printf("Nhap diem Ly: ");
    scanf("%f", &diemLy);

    printf("Nhap diem Hoa: ");
    scanf("%f", &diemHoa);

    // 2. Tính toán điểm trung bình theo công thức (Toán hệ số 2)
    diemTrungBinh = (diemToan * 2 + diemLy + diemHoa) / 4;

    // 3. Xuất dữ liệu ra màn hình theo đúng định dạng yêu cầu
    printf("\nMa so sinh vien: [%s]\n", mssv);
    printf("Ho Va Ten: [%s]\n", hoTen);
    printf("Diem Trung Binh: [%.2f]\n", diemTrungBinh); // Làm tròn 2 chữ số thập phân

    return 0;
}