#include <stdio.h>
#include <windows.h>
#include <math.h>

int main() {
    SetConsoleOutputCP(65001);
    
    int choice;
    
    do {
        printf("\n=====================================\n");
        printf("         MENU CHUONG TRINH LAB 3      \n");
        printf("=====================================\n");
        printf("1. Chức năng học lực sinh viên\n");
        printf("2. Chức năng giải phương trình bậc 2\n");
        printf("3. Chức năng tính tiền điện tiêu thụ hàng tháng\n");
        printf("4. Thoát chương trình\n");
        printf("-------------------------------------\n");
        
        printf("Nhap lua chon cua ban (1-4): ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Xóa đệm nếu nhập chữ ở menu
            choice = 0; // Đưa về mặc định để nhảy vào default
        
        }
        while (getchar() != '\n'); 
        printf("\n"); 
        
        switch (choice) {
            case 1: { 
                printf("--- Chức năng học lực sinh viên ---\n");
                float diem;
                
                printf("Nhập vào điểm của sinh viên (0 - 10): ");
                // Nhập và kiểm tra dữ liệu hợp lệ
                while (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
                    while (getchar() != '\n'); // Xóa đệm dư thừa/chữ lỗi
                    printf("Không hợp lệ! Điểm phải từ 0 đến 10.\n");
                    printf("Nhập lại điểm: ");
                }
                while (getchar() != '\n'); // Dọn đệm sau khi nhập điểm thành công
                
                // Xếp loại học lực
                if (diem >= 9) {
                    printf("Xếp loại: Xuất sắc\n");
                } else if (diem >= 8) {
                    printf("Xếp loại: Giỏi\n");
                } else if (diem >= 6.5) {
                    printf("Xếp loại: Khá\n");
                } else if (diem >= 5) {
                    printf("Xếp loại: Trung bình\n");
                } else {
                    printf("Xếp loại: Yếu\n");
                }
                break;
            }
            
            case 2: {
                printf("--- Chức năng giải phương trình bậc 2 ---\n");
                float a, b, c;
                
                printf("nhap a: ");
                while (scanf("%f", &a) != 1) { while (getchar() != '\n'); printf("Nhập lại a: "); }
                printf("nhap b: ");
                while (scanf("%f", &b) != 1) { while (getchar() != '\n'); printf("Nhập lại b: "); }
                printf("nhap c: ");
                while (scanf("%f", &c) != 1) { while (getchar() != '\n'); printf("Nhập lại c: "); }
                while (getchar() != '\n');
                
                printf("\nPhương trình: %.1fx^2 + %.1fx + %.1f = 0\n", a, b, c);
                
                if (a == 0) {
                    if (b == 0) {
                        if (c == 0) {
                            printf("pt vô số nghiệm.\n");
                        } else {
                            printf("pt vô nghiệm.\n");
                        }
                    } else {
                        float x = -c / b;
                        printf("Nghiệm x = %.1f\n", x);
                    }
                } 
                else {
                    float Delta = b * b - 4 * a * c;
                    
                    if (Delta < 0) {
                        printf("Pt vô nghiệm\n");
                    } 
                    else if (Delta == 0) {
                        float x = -b / (2 * a);
                        printf("pt có nghiệm kép x1 = x2 = %.1f\n", x);
                    } 
                    else {
                        float x1 = (-b + sqrt(Delta)) / (2 * a);
                        float x2 = (-b - sqrt(Delta)) / (2 * a);
                        printf("Pt có 2 nghiệm phân biệt:\n");
                        printf("x1 = %.1f\n", x1);
                        printf("x2 = %.1f\n", x2);
                    }
                }          
                break;
            }
            
            case 3: {
                printf("--- Chức năng tính tiền điện tiêu thụ hàng tháng ---\n");
                int kwh;
                printf("Nhap so kWh tieu thu: ");
                while (scanf("%d", &kwh) != 1 || kwh < 0) {
                    while (getchar() != '\n');
                    printf("Số kWh không hợp lệ! Nhập lại: ");
                }
                while (getchar() != '\n');
                
                if (kwh <= 50) {
                    long long money = 1678LL * kwh;
                    printf("Tiền điện: %lld đồng\n", money);
                }
                else if (kwh <= 100) {
                    long long money = 1678LL * 50 + (kwh - 50) * 1734LL;
                    printf("Tiền điện: %lld đồng\n", money);
                }
                else if (kwh <= 200) {
                    long long money = 1678LL * 50 + 1734LL * 50 + (kwh - 100) * 2014LL;
                    printf("Tiền điện: %lld đồng\n", money);
                }
                else if (kwh <= 300) {
                    long long money = 1678LL * 50 + 1734LL * 50 + 2014LL * 100 + (kwh - 200) * 2536LL;
                    printf("Tiền điện: %lld đồng\n", money);
                }
                else if (kwh <= 400) {
                    long long money = 1678LL * 50 + 1734LL * 50 + 2014LL * 100 + 2536LL * 100 + (kwh - 300) * 2834LL;
                    printf("Tiền điện: %lld đồng\n", money);
                }
                else {
                    long long money = 1678LL * 50 + 1734LL * 50 + 2014LL * 100 + 2536LL * 100 + 2834LL * 100 + (kwh - 400) * 2927LL;
                    printf("Tiền điện: %lld đồng\n", money);
                }
                break;
            }
            
            case 4:
                printf("Cảm ơn bạn đã sử dụng chương trình. Thoát hẳn!\n");
                break;
                
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng chọn lại từ 1 đến 4.\n");
        }
        
    } while (choice != 4); 
    
    return 0;
}