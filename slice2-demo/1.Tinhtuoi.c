#include <stdio.h>
int main(){
    int namSinh;
    //UI/UX
    printf("Nhap nam sinh: ");
    scanf("%d",&namSinh);
    printf("Nam sinh: %d\nTuoi: %d\n",namSinh,2026 - namSinh);
    return 0;
}