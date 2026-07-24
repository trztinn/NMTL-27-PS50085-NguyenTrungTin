#include <stdio.h>

int main() {
    int n;
    int dem = 0;
    printf("Nhap vao so tien can doi: ");
    scanf("%d", &n);

    int money = n;

    if (n <= 1) {
        printf("Khong the doi menh gia nho hon hoac bang 1!\n");
    } else {
        int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
        for (int i = 0; i < 9; i++)
        {
            if (menhGia[i] >= n)
            {
                continue;
            }
            else
            {
                int to = money / menhGia[i];

                if (to >= 1)
                {   
                    if (dem > 0)
                    {
                       printf(" va ");
                    }
                    printf("%d to %d", to, menhGia[i]);
                    money = money % menhGia[i];
                    dem++;
                }
                
            }    
        }
    }

    return 0;
}