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
        if (scanf("%d", &choice) != 1 )
        {
            choice = 100;
        }
        while (getchar() != '\n');
        printf("\n"); 
        
        switch (choice) {
            case 1:{ 
                printf("--- Chức năng học lực sinh viên ---\n");
                printf("Nhập vào điểm của sinh viên: "); 
                float diem;
                while (scanf("%f", &diem) != 1 || diem < 0 || diem > 10)
                {
                    while (getchar() != '\n');
                    printf("Không hợp lệ! \n"); 
                    printf("Nhập lại: ");
                }
                
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
            
            case 3:{
                printf("--- Chức năng tính tiền điện tiêu thụ hàng tháng ---\n");
                int kwh;
                printf("Nhap so kWh tieu thu: ");
                scanf("%d", &kwh);          
                if (kwh <= 0)
                {
                    printf("Không hợp lệ\n"); 
                    break;  
                }
                else    
                {
                    if (kwh <= 50)
                    {
                        long long money = 1678 * kwh;
                        printf("Tiền điện: %lld đồng\n", money);
                    }
                    else if (kwh <= 100)
                    {
                        long long money = 1678 * 50 + (kwh - 50) * 1734;
                        printf("Tiền điện: %lld đồng\n", money);
                    }
                    else if (kwh <= 200)
                    {
                        long long money = 1678 * 50 + 1734 * 50 + (kwh - 100) * 2014;
                        printf("Tiền điện: %lld đồng\n", money);
                    }
                    else if (kwh <= 300)
                    {
                        long long money = 1678 * 50 + 1734 * 50 + 2014 * 100 + (kwh - 200) * 2536;
                        printf("Tiền điện: %lld đồng\n", money);
                    }
                    else if (kwh <= 400)
                    {
                        long long money = 1678 * 50 + 1734 * 50 + 2014 * 100 + 2536 * 100 + (kwh - 300) * 2834;
                        printf("Tiền điện: %lld đồng\n", money);
                    }
                    else
                    {
                        long long money = 1678 * 50 + 1734 * 50 + 2014 * 100 + 2536 * 100 + 2834 * 100 + (kwh - 400) * 2927;
                        printf("Tiền điện: %lld đồng\n", money);
                    }
                    printf(" ");
                }
                printf(" Nhap");
                break;
            }
            
            case 4:
                printf("Cảm ơn bạn đã sử dụng chương trình. Thoát hẳn!\n");
                break;
                
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng chọn lại từ 1 đến 4.\n");
        }
        
    } while (choice != 4 ); 
    
    return 0;
}