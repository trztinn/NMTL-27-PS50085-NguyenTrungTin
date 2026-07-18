#include <stdio.h>
int main() {
    // int kwh;
    // float tienDien;
    // printf("Nhap so kWh tieu thu: ");
    // scanf("%d", &kwh);
    // if (kwh <= 50) {
    //     tienDien = kwh * 1.678;
    // } else if (kwh <= 100) {
    //     tienDien = 50 * 1.678 + (kwh - 50) * 1.734;
    // } else {
    //     tienDien = 50 * 1.678 + 50 * 1.734 + (kwh - 100) * 2.014;
    // }
    // printf("So tien dien phai tra: %.3f VND\n", tienDien);

    // int count = 0;
    // for (int i = 0; i < 3; i++) {
    // for (int j = 0; j < 3; j++) {
    //     if (i == j) break;
    //     count++;
    // }}
    // printf("%d", count);
    
    // int i = 0, j = 0; 
    // while (i < 5){
    // if (i++ && j++) 
    // {
    //     j += 2; //| 1 0 | 2 1 | 3 4 | 4 7 | 5 10 |
    // }} 
    // printf("%d %d", i, j);

    // int x = 0;
    // for (int i = 1; i <= 3; i++) {
    // switch (i) {
    //     case 1: x += 1;
    //     case 2: x += 2; break;
    //     case 3: x += 3;
    //     default: x += 4;
    // }} 
    // printf("%d", x);    //| 1 2 | 2 | 3 4 |
    
    // int a = 5, b = 2;
    // do {
    // if (--a == b) {
    //     continue; //| 4 3 | 3 3 | 2 4 | 1 5 | 0 6 |
    // }
    // b++; 
    // } while (a > 0);
    // printf("%d %d", a, b);

    int n = 10, sum = 0;
    while (n > 0) {
    if (n & 1) {
        sum += n;
    } else {
        n--;
        continue;
    }
    n /= 2;  //| 9 0 | 4 9 | 3 9 | 1 12 | 0 13 |
    }
    printf("%d", sum);

    return 0;
}