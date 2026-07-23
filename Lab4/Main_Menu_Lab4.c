#include <stdio.h>
#include <windows.h>
#include <math.h>

int main() {
    SetConsoleOutputCP(65001);

    int luachon;

    do {
        printf("\n+---------------------------------------+\n");
        printf("|        MENU CHƯƠNG TRÌNH LAB 4        |\n");
        printf("+---------------------------------------+\n");
        printf("| 1. Tính trung bình tổng các số chia 2 |\n");
        printf("| 2. Kiểm tra Số nguyên tố              |\n");
        printf("| 3. Kiểm tra Số chính phương           |\n");
        printf("| 4. Thoát chương trình                 |\n");
        printf("+---------------------------------------+\n");
        
        printf("Mời bạn chọn chức năng (1-4): ");
        
        if (scanf("%d", &luachon) != 1) {
            printf("\n[Lỗi] Bạn phải nhập vào một số! Vui lòng thử lại.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (luachon) {
            case 1:{
                printf("\n---> Bạn đã chọn: Tính trung bình tổng các số chia hết cho 2\n");
                int min,max;
                    printf("Nhap min: ");
                    scanf("%d", &min);
                
                do
                {
                    printf("Nhap max: ");
                    scanf("%d", &max);
                } while (max < min); 

                int count = 0;
                int sum = 0;
                
                for (int i = min; i <= max; i++)
                {
                    if (i % 2 == 0)
                    {
                        printf("A: %d\n", i);
                        sum = sum + i;
                        count++;
                    }              
                }
                printf("Tổng: %d\n", sum);
                printf("Đếm số: %d\n", count);
                int tbc = sum / count;
                printf("Trung bình cộng: %d\n", tbc);
                break;
            }
            case 2:{
                printf("\n---> Bạn đã chọn: Kiểm tra Số nguyên tố\n");
            
                int x;
                printf("Nhập số nguyên tố: ");
                scanf("%d", &x);
            
                int check = 1;
            
                if (x < 2)
                {
                    check = 0;
                }
                else
                {
                    for (int i = 2; i <= sqrt(x); i++)
                    {
                        if (x % i == 0)
                        {
                            check = 0;
                            break;
                        }
                    }
                }
            
                if (check == 1)
                {
                    printf("%d là số nguyên tố", x);
                }
                else
                {
                    printf("%d không phải là số nguyên tố", x);
                }
            
                break;
            }
    
            case 3:
                printf("\n---> Bạn đã chọn: Kiểm tra Số chính phương\n");
                int a;
                printf("Nhập số nguyên: ");
                scanf("%d", &a);
                int bac2 = sqrt(a);
                if ( bac2 * bac2 == a)
                {
                    printf("Số chính phương ");
                }
                else
                {
                    printf("Đây không phải là số chính phương ");
                }
                
                break;

            case 4:
                printf("\n---> Đang thoát chương trình... Tạm biệt!\n");
                break;

            default:
                printf("\n[Lỗi] Lựa chọn không hợp lệ! Vui lòng chọn từ 1 đến 4.\n");
                break;
        }

    } while (luachon != 4); 

    return 0;
}