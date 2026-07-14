#include <stdio.h>

int main() {
    float a,b;
    printf("Nhap so a: ");
    scanf("%f", &a);
    if (a == 0) {
        printf("Phuong trinh vo nghiem hoac vo so nghiem\n");
        return 0;
    }

    printf("Nhap so b: ");
    scanf("%f", &b);

    printf("Phuong trinh bac 1: %.1fx + %.1f = 0\n",a,b);

    float x = -(b/a); 
    printf("Nghiem x = %.1f\n", x);
    return 0;
}   
