#include <stdio.h>
#include <windows.h>
#include <math.h>

int main() {
    SetConsoleOutputCP(65001);
    
    int choice;
    
    do {
        printf("\n=====================================\n");
        printf("        MENU CHUONG TRINH LAB 3      \n");
        printf("=====================================\n");
        printf("1. Chức năng học lực sinh viên\n");
        printf("2. Chức năng giải phương trình bậc 2\n");
        printf("3. Chức năng tính tiền điện tiêu thụ hàng tháng\n");
        printf("4. Thoát chương trình\n");
        printf("-------------------------------------\n");
        
        printf("Nhap lua chon cua ban (1-4): ");
        scanf("%d", &choice);
        printf("\n"); 
        
        switch (choice) {
            case 1: { 
                printf("--- Chức năng học lực sinh viên ---\n");
                printf("Nhập vào điểm của sinh viên: "); 
                float diem;
                scanf("%f", &diem);
                
                if (diem < 0 || diem > 10) {
                    printf("Nhập không hợp lệ! Điểm phải từ 0 đến 10.\n");
                } 
                else {
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
                }
                break;
            }
            
            case 2: {
                printf("--- Chức năng giải phương trình bậc 2 ---\n");
                float a, b, c;
                printf("nhap a: ");
                scanf("%f", &a);
                printf("nhap b: ");
                scanf("%f", &b);
                printf("nhap c: ");
                scanf("%f", &c);
                
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
            
            case 3:
                printf("--- Chức năng tính tiền điện tiêu thụ hàng tháng ---\n");
                // Viết code tính tiền điện của bạn ở đây
                break;
                
            case 4:
                printf("Cảm ơn bạn đã sử dụng chương trình. Thoát hẳn!\n");
                break;
                
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng chọn lại từ 1 đến 4.\n");
        }
        
    } while (choice != 4 ); // Vòng lặp sẽ tiếp tục nếu người dùng KHÔNG chọn số 4
    
    return 0;
}