#include <stdio.h>

void xuatSoLeMaTran(int row, int col){
    int a[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("So phan tu le: \n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] % 2 != 0)
            {
                printf(" a[%d][%d] = %d\n", i, j, a[i][j]);
            }
        }
    }
}

int main() {
    int row,col;
    printf("Nhap hang: ");
    scanf("%d", &row);

    printf("Nhap cot: ");
    scanf("%d", &col);
    
    xuatSoLeMaTran(row, col);

    return 0;
}
