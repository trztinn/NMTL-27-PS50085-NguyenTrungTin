#include <stdio.h>
#include <windows.h>
#include <math.h>

int findMax(int a, int b, int c) {
    int Max = a;

    if (Max < b) {
        Max = b;
    }

    if (Max < c) {
        Max = c;
    }

    return Max;
}

int checkYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    }
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void checkTriangle(float *a, float *b, float *c) {

    printf("Nhập độ dài 3 cạnh: ");

    while (scanf("%f %f %f", a, b, c) != 3 ||
           *a <= 0 || *b <= 0 || *c <= 0 ||
           !(*a + *b > *c && *a + *c > *b && *b + *c > *a))
    {
        printf("Đây không phải là 3 cạnh của một tam giác!\n");
        printf("Vui lòng nhập lại: ");

        while (getchar() != '\n');
    }

    printf("Độ dài hợp lệ: %.2f %.2f %.2f\n", *a, *b, *c);
}

int isRightTriangle(float a, float b, float c) {
    return fabs(a*a + b*b - c*c) < 0.001 ||
           fabs(a*a + c*c - b*b) < 0.001 ||
           fabs(b*b + c*c - a*a) < 0.001;
}


int main() {

    SetConsoleOutputCP(65001);

    int luachon;

    do {

        printf("\n+-----------------------------------------------+\n");
        printf("|              MENU CHƯƠNG TRÌNH LAB 5          |\n");
        printf("+-----------------------------------------------+\n");
        printf("| 1. Tìm giá trị lớn nhất trong 3 số            |\n");
        printf("| 2. Kiểm tra Năm nhuận                         |\n");
        printf("| 3. Hoán vị 2 số (Sử dụng Con trỏ)             |\n");
        printf("| 4. Kiểm tra & Phân loại Tam giác              |\n");
        printf("| 5. Thoát chương trình                         |\n");
        printf("+-----------------------------------------------+\n");

        printf("Mời bạn chọn chức năng (1-5): ");

        if (scanf("%d", &luachon) != 1) {

            printf("[Lỗi] Bạn phải nhập số!\n");

            while(getchar() != '\n');

            continue;
        }

        switch(luachon) {
            case 1:
            {
                int a,b,c;

                printf("\n---> Tìm giá trị lớn nhất trong 3 số\n");

                printf("Nhập ba số nguyên: ");
                scanf("%d %d %d",&a,&b,&c);

                printf("Số lớn nhất là: %d\n",
                       findMax(a,b,c));

                break;
            }

            case 2:
            {
                int year;

                printf("\n---> Kiểm tra năm nhuận\n");

                printf("Nhập năm cần kiểm tra: ");
                scanf("%d",&year);


                if(checkYear(year)) {
                    printf("%d là năm nhuận\n",year);
                }
                else {
                    printf("%d không phải năm nhuận\n",year);
                }

                break;
            }

            case 3:
            {
                int a,b;

                printf("\n---> Hoán vị 2 số\n");

                printf("Nhập A: ");
                scanf("%d",&a);

                printf("Nhập B: ");
                scanf("%d",&b);

                printf("Trước khi đổi: A=%d B=%d\n",a,b);

                swap(&a,&b);

                printf("Sau khi đổi: A=%d B=%d\n",a,b);

                break;
            }

            case 4:
            {
                float a,b,c;

                printf("\n---> Kiểm tra & Phân loại Tam giác\n");

                checkTriangle(&a,&b,&c);

                if(a==b && b==c) {
                    printf("Kết quả: Tam giác đều\n");
                }
                else if(a==b || a==c || b==c) {

                    if(isRightTriangle(a,b,c)) {
                        printf("Kết quả: Tam giác vuông cân\n");
                    }
                    else {
                        printf("Kết quả: Tam giác cân\n");
                    }
                }
                else if(isRightTriangle(a,b,c)) {
                    printf("Kết quả: Tam giác vuông\n");
                }
                else {
                    printf("Kết quả: Tam giác thường\n");
                }
                break;
            }

            case 5:

                printf("\nĐang thoát chương trình... Tạm biệt!\n");
                break;

            default:

                printf("\n[Lỗi] Chỉ được chọn từ 1 đến 5!\n");
        }
    } while(luachon != 5);

    return 0;
}
