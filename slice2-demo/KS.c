#include <stdio.h>
int main(){
    int giaNgay = 200;
    int giaTuan = 1300;
    int soNgay;

    int soTuan, soNgayLe;
    printf("Nhap so ngay o KS: ");
    scanf("%d",&soNgay); //16
    soTuan = soNgay/7;
    soNgayLe = soNgay % 7;

    printf("So ngay o: %d\nSo tuan: %d\nSo ngay le: %d\nTong tien: %d\n",soNgay,soTuan,soNgayLe,soTuan*giaTuan + soNgayLe*giaNgay);
    return 0;
}