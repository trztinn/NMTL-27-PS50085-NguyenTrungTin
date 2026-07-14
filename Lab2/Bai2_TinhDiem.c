#include <stdio.h>

int main() {
    float diemToan, diemLy, diemHoa;

    printf(" Diem toan: ");
    scanf("%f", &diemToan); 
    printf(" Diem ly: ");   
    scanf("%f", &diemLy);   
    printf(" Diem hoa: ");  
    scanf("%f", &diemHoa);  
    
    float diemTrungBinh = ((float)(diemToan * 3 + diemLy * 2 + diemHoa) / 6);
    printf("Diem trung binh: %.2f\n", diemTrungBinh);
    
    return 0;
}   
