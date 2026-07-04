#include <stdio.h>

int main() {
    int a = 5;
    int b = 7;
    float nghiemX;

    // Tính nghiệm (ép kiểu sang float để ra kết quả chính xác -1.4)
    nghiemX = (float)-b / a; 

    // Xuất câu thông báo ra màn hình
    printf("Phuong trinh %dx + %d = 0 co nghiem x = %.1f", a, b, nghiemX);

    return 0;