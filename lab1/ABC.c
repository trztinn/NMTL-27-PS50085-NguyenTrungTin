#include <stdio.h>
int main()
{
    int A;
    printf("Nhap gia tri A: ");
    scanf("%d", &A);

    int B;
    printf("Nhap gia tri B: ");
    scanf("%d", &B);

    int Dientich = A * B;
    printf("Dien tich hinh chu nhat la: %d\n", Dientich);
    int Chuvi = (A + B) * 2;
    printf("Chu vi hinh chu nhat la: %d\n", Chuvi);
    
    return 0;
}