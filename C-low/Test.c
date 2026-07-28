#include <stdio.h>

int main() {
    int a[5];

    // Nhập
    for (int i = 0; i < 5; i++) {
        printf("Mang so %d: ",i+1);
        scanf("%d", &a[i]);
    }

    printf("In so:{ ");
    for (int i = 0; i < 5; i++) {
        
        printf("%d ", a[i]);
    }
    printf("} ");
    return 0;
}
