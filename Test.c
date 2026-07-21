#include <stdio.h>
#include <windows.h>
#include <math.h>

void clear() {
    while (getchar() != '\n');
}

// ================= 50% LOGIC NGOÀI: HÀM BỔ TRỢ =================
// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Hàm kiểm tra số chính phương
int laSoChinhPhuong(int n) {
    if (n < 0) return 0;
    int can = (int)sqrt(n);
    return (can * can == n);
}

// Hàm tìm Ước số chung lớn nhất (sử dụng thuật toán Euclid)
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Hàm tìm Bội số chung nhỏ nhất: BSCNN = (a * b) / UCLN
int timBSCNN(int a, int b, int ucln) {
    if (a == 0 || b == 0) return 0;
    return abs(a * b) / ucln;
}

// ================= CHƯƠNG TRÌNH CHÍNH =================
int main() {
    SetConsoleOutputCP(65001); // Hỗ trợ tiếng Việt Console
    
    int choice;
    
    do {
        printf("\n=====================================\n");
        printf("        MENU CHƯƠNG TRÌNH LAB        \n");
        printf("=====================================\n");
        printf("1.  Chức năng 1: Kiểm tra số nguyên\n");
        printf("2.  Chức năng 2: Tìm ƯSCLN và BSCNN\n");
        printf("3.  Chức năng 3: Tính tiền Karaoke\n");
        printf("4.  Chức năng 4: Tính tiền điện\n");
        printf("5.  Chức năng 5: Đổi tiền\n");
        printf("6.  Chức năng 6: Tính lãi suất vay ngân hàng\n");
        printf("7.  Chức năng 7: Vay tiền mua xe\n");
        printf("8.  Chức năng 8: Sắp xếp thông tin sinh viên\n");
        printf("9.  Chức năng 9: Game Lott (FPOLY-LOTT)\n");
        printf("10. Chức năng 10: Tính toán phân số\n");
        printf("11. Thoát chương trình\n");
        printf("-------------------------------------\n");
        
        printf("Nhập lựa chọn của bạn (1-11): ");
        if (scanf("%d", &choice) != 1) {
            choice = -1;
        }
        clear();
        
        switch (choice) {
            // ----- CHỨC NĂNG 1 -----
            case 1: {
                printf("\n--- Chức năng 1: Kiểm tra số nguyên ---\n");
                float x;
                char check;
                printf("Nhập vào số x: ");

                while (scanf("%f%c", &x, &check) != 2 || check != '\n') {
                    clear();
                    printf("Dữ liệu không hợp lệ! Vui lòng nhập lại số x: ");
                }

                if (x == (int)x) {
                    int n = (int)x;
                    printf("=> %.2f LÀ số nguyên.\n", x);

                    if (laSoNguyenTo(n)) {
                        printf("=> %d LÀ số nguyên tố.\n", n);
                    } else {
                        printf("=> %d KHÔNG PHẢI là số nguyên tố.\n", n);
                    }

                    if (laSoChinhPhuong(n)) {
                        printf("=> %d LÀ số chính phương.\n", n);
                    } else {
                        printf("=> %d KHÔNG PHẢI là số chính phương.\n", n);
                    }

                } else {
                    printf("=> %.2f KHÔNG PHẢI là số nguyên.\n", x);
                }
                
                break;
            }
            
            // ----- CHỨC NĂNG 2 -----
            case 2: {
                printf("\n--- Chức năng 2: Tìm ƯSCLN và BSCNN ---\n");
                int x, y;
                char check1, check2;

                // Nhập x (bắt lỗi nếu nhập chữ hoặc số thực)
                printf("Nhập số nguyên x: ");
                while (scanf("%d%c", &x, &check1) != 2 || check1 != '\n') {
                    clear();
                    printf("Dữ liệu không hợp lệ! Vui lòng nhập lại x: ");
                }

                // Nhập y (bắt lỗi nếu nhập chữ hoặc số thực)
                printf("Nhập số nguyên y: ");
                while (scanf("%d%c", &y, &check2) != 2 || check2 != '\n') {
                    clear();
                    printf("Dữ liệu không hợp lệ! Vui lòng nhập lại y: ");
                }

                int ucln = timUCLN(x, y);
                int bscnn = timBSCNN(x, y, ucln);

                printf("=> Ước số chung lớn nhất (ƯCLN) của %d và %d là: %d\n", x, y, ucln);
                if (bscnn == 0) {
                    printf("=> Không có Bội số chung nhỏ nhất (BSCNN) vì có số bằng 0.\n");
                } else {
                    printf("=> Bội số chung nhỏ nhất (BSCNN) của %d và %d là: %d\n", x, y, bscnn);
                }

                break;
            }
                
            case 3:
                printf("\n--- Chức năng 3: Tính tiền Karaoke ---\n");
                // TODO: Thêm code xử lý chức năng 3 tại đây
                break;

            case 4:
                printf("\n--- Chức năng 4: Tính tiền điện ---\n");
                // TODO: Thêm code xử lý chức năng 4 tại đây
                break;
            
            case 5:
                printf("\n--- Chức năng 5: Đổi tiền ---\n");
                // TODO: Thêm code xử lý chức năng 5 tại đây
                break;
                
            case 6:
                printf("\n--- Chức năng 6: Tính lãi suất vay ngân hàng ---\n");
                // TODO: Thêm code xử lý chức năng 6 tại đây
                break;

            case 7:
                printf("\n--- Chức năng 7: Vay tiền mua xe ---\n");
                // TODO: Thêm code xử lý chức năng 7 tại đây
                break;
            
            case 8:
                printf("\n--- Chức năng 8: Sắp xếp thông tin sinh viên ---\n");
                // TODO: Thêm code xử lý chức năng 8 tại đây
                break;
                
            case 9:
                printf("\n--- Chức năng 9: Game Lott ---\n");
                // TODO: Thêm code xử lý chức năng 9 tại đây
                break;

            case 10:
                printf("\n--- Chức năng 10: Tính toán phân số ---\n");
                // TODO: Thêm code xử lý chức năng 10 tại đây
                break;

            case 11:
                printf("\nĐã thoát chương trình! Tạm biệt.\n");
                break;
                
            default:
                printf("\nLựa chọn không hợp lệ! Vui lòng chọn lại từ 1 đến 11.\n");
        }
        
    } while (choice != 11); 
    
    return 0;
}