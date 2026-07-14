#include <stdio.h>
#define PI 3.14159

int main() {
    float chieuDai, chieuRong;

    printf("--- TINH TOAN HINH CHU NHAT ---\n");
    printf("Nhap chieu dai: ");
    scanf("%f", &chieuDai);
    printf("Nhap chieu rong: ");
    scanf("%f", &chieuRong);

    float chuViHCN = (chieuDai + chieuRong) * 2;
    float dienTichHCN = chieuDai * chieuRong;

    printf("Chu vi Hinh Chu Nhat: %.2f\n", chuViHCN);
    printf("Dien tich Hinh Chu Nhat: %.2f\n\n", dienTichHCN);


    // ==========================================
    // 2. XỬ LÝ HÌNH TRÒN
    // ==========================================
    float banKinh;
    printf("--- TINH TOAN HINH TRON ---\n");
    printf("Nhap ban kinh hinh tron: ");
    scanf("%f", &banKinh);

    float chuViTron = 2 * PI * banKinh;
    float dienTichTron = PI * banKinh * banKinh;

    printf("Chu vi Hinh Tron: %.2f\n", chuViTron);
    printf("Dien tich Hinh Tron: %.2f\n", dienTichTron);

    return 0;
}