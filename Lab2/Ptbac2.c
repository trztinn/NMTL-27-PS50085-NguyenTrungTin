#include <stdio.h>
#include <math.h>
int main() {
    printf(" ax2 + bx + c = 0\n");
    float a,b,c;
    printf("Nhap so a: ");
    scanf("%f", &a);
    if (a == 0) {
        printf("Phuong trinh vo nghiem hoac vo so nghiem\n");
        return 0;
    }
    printf("Nhap so b: ");
    scanf("%f", &b);
    printf("Nhap so c: ");
    scanf("%f", &c);
    printf("Phuong trinh bac 2: %.1fx2 + %.1fx + %.1f = 0\n",a,b,c);
    float delta = b*b - 4*a*c;
    if (delta < 0) {
        printf("Phuong trinh vo nghiem\n");
        return 0;
    }
    else if (delta == 0) {
        float x = -b/(2*a);
        printf("Phuong trinh co nghiem kep x = %.1f\n", x);
        return 0;
    }
    else {
    float x1,x2;
    x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
    printf("Nghiem x1 = %.1f\n", x1);
    printf("Nghiem x2 = %.1f\n", x2);    
    return 0;
    }
}   
