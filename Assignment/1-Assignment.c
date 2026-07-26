#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

void inPhanSo(int tu, int mau) {
    if (mau == 0) {
        printf("Mẫu số không hợp lệ!");
        return;
    }
    if (tu == 0) {
        printf("0");
        return;
    }
    int ucln = timUCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
    
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    
    if (mau == 1) {
        printf("%d", tu);
    } else {
        printf("%d/%d", tu, mau);
    }
}

int main() {
    SetConsoleOutputCP(65001);
    srand((unsigned int)time(NULL));
    
    int choice;
    
    do {
        printf("\n=====================================\n");
        printf("         MENU CHƯƠNG TRÌNH LAB       \n");
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
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                printf("\n--- Chức năng 1: Kiểm tra số nguyên ---\n");
                float x;
                printf("Nhập vào số x: ");
                while (scanf("%f", &x) != 1) {
                    clearInputBuffer();
                    printf("Dữ liệu không hợp lệ! Vui lòng nhập lại số x: ");
                }
                clearInputBuffer();

                if (x == (int)x) {
                    int n = (int)x;
                    printf("=> %.2f LÀ số nguyên.\n", x);

                    int isPrime = (n >= 2);
                    for (int i = 2; i <= sqrt(n); i++) {
                        if (n % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) printf("=> %d LÀ số nguyên tố.\n", n);
                    else printf("=> %d KHÔNG PHẢI là số nguyên tố.\n", n);

                    int can = (int)sqrt(n);
                    if (n >= 0 && can * can == n) {
                        printf("=> %d LÀ số chính phương.\n", n);
                    } else {
                        printf("=> %d KHÔNG PHẢI là số chính phương.\n", n);
                    }
                } else {
                    printf("=> %.2f KHÔNG PHẢI là số nguyên.\n", x);
                }
                break;
            }
            
            case 2: {
                printf("\n--- Chức năng 2: Tìm ƯSCLN và BSCNN ---\n");
                int x, y;
                printf("Nhập số nguyên x: ");
                while (scanf("%d", &x) != 1) {
                    clearInputBuffer();
                    printf("Dữ liệu không hợp lệ! Nhập lại x: ");
                }
                printf("Nhập số nguyên y: ");
                while (scanf("%d", &y) != 1) {
                    clearInputBuffer();
                    printf("Dữ liệu không hợp lệ! Nhập lại y: ");
                }
                clearInputBuffer();

                int ucln = timUCLN(x, y);
                printf("=> Ước số chung lớn nhất (ƯCLN) của %d và %d là: %d\n", x, y, ucln);
                
                if (x == 0 || y == 0) {
                    printf("=> Không có Bội số chung nhỏ nhất (BSCNN) vì có số bằng 0.\n");
                } else {
                    int bscnn = abs(x * y) / ucln;
                    printf("=> Bội số chung nhỏ nhất (BSCNN) của %d và %d là: %d\n", x, y, bscnn);
                }
                break;
            }
                
            case 3: {
                printf("\n--- Chức năng 3: Tính tiền Karaoke ---\n");
                int gBatDau, gKetThuc;
                printf("Nhập giờ bắt đầu (12 - 23): ");
                scanf("%d", &gBatDau);
                printf("Nhập giờ kết thúc (12 - 23): ");
                scanf("%d", &gKetThuc);
                clearInputBuffer();

                if (gBatDau < 12 || gKetThuc > 23 || gBatDau >= gKetThuc) {
                    printf("=> Giờ nhập không hợp lệ! Quán chỉ mở cửa từ 12h đến 23h.\n");
                } else {
                    int soGio = gKetThuc - gBatDau;
                    double tongTien = 0;

                    if (soGio <= 3) {
                        tongTien = soGio * 150000;
                    } else {
                        tongTien = 3 * 150000 + (soGio - 3) * 150000 * 0.7;
                    }

                    if (gBatDau >= 14 && gBatDau <= 17) {
                        tongTien *= 0.9;
                    }

                    printf("=> Tổng số tiền Karaoke cần thanh toán: %.0f VNĐ\n", tongTien);
                }
                break;
            }

            case 4: {
                printf("\n--- Chức năng 4: Tính tiền điện ---\n");
                double kwh, tongTien = 0;
                printf("Nhập số kWh điện sử dụng: ");
                scanf("%lf", &kwh);
                clearInputBuffer();

                if (kwh < 0) {
                    printf("=> Số kWh không hợp lệ!\n");
                } else {
                    if (kwh <= 50) tongTien = kwh * 1678;
                    else if (kwh <= 100) tongTien = 50 * 1678 + (kwh - 50) * 1734;
                    else if (kwh <= 200) tongTien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
                    else if (kwh <= 300) tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
                    else if (kwh <= 400) tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
                    else tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
                    
                    printf("=> Số tiền điện phải trả: %.0f VNĐ\n", tongTien);
                }
                break;
            }
            
            case 5: {
                printf("\n--- Chức năng 5: Đổi tiền ---\n");
                int tien;
                printf("Nhập vào số tiền cần đổi: ");
                scanf("%d", &tien);
                clearInputBuffer();

                int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
                printf("Số tờ tiền đổi được:\n");
                for (int i = 0; i < 9; i++) {
                    int soTo = tien / menhGia[i];
                    if (soTo > 0) {
                        printf("- %d tờ mệnh giá %d\n", soTo, menhGia[i]);
                        tien %= menhGia[i];
                    }
                }
                break;
            }
                
            case 6: {
                printf("\n--- Chức năng 6: Tính lãi suất vay ngân hàng ---\n");
                double tienVay;
                printf("Nhập số tiền muốn vay (VNĐ): ");
                scanf("%lf", &tienVay);
                clearInputBuffer();

                double gocHangThang = tienVay / 12;
                double conLai = tienVay;

                printf("\n%-10s %-15s %-15s %-15s %-15s\n", "Kỳ hạn", "Lãi phải trả", "Gốc phải trả", "Số tiền trả", "Số tiền còn lại");
                for (int i = 1; i <= 12; i++) {
                    double lai = conLai * 0.05;
                    double tongTra = gocHangThang + lai;
                    conLai -= gocHangThang;
                    if (conLai < 1e-9) conLai = 0;
                    printf("%-10d %-15.0f %-15.0f %-15.0f %-15.0f\n", i, lai, gocHangThang, tongTra, conLai);
                }
                break;
            }

            case 7: {
                printf("\n--- Chức năng 7: Vay tiền mua xe ---\n");
                double pctVay;
                printf("Nhập phần trăm vay tối đa (ví dụ 80): ");
                scanf("%lf", &pctVay);
                clearInputBuffer();

                if (pctVay <= 0 || pctVay > 100) {
                    printf("=> Phần trăm vay không hợp lệ!\n");
                } else {
                    double giaTriXe = 500000000.0 / (pctVay / 100.0);
                    double tienTraTruoc = giaTriXe - 500000000.0;
                    int soThang = 24 * 12;
                    double gocThang = 500000000.0 / soThang;
                    double laiThang = 0.072 / 12;

                    printf("=> Tổng giá trị xe: %.0f VNĐ\n", giaTriXe);
                    printf("=> Số tiền cần trả trước (%.0f%%): %.0f VNĐ\n", 100 - pctVay, tienTraTruoc);
                    printf("=> Số tiền gốc trả hàng tháng (24 năm): %.0f VNĐ\n", gocThang);
                    printf("=> Lãi tháng đầu tiên: %.0f VNĐ\n", 500000000.0 * laiThang);
                }
                break;
            }

            case 8: {
                printf("\n--- Chức năng 8: Sắp xếp thông tin sinh viên ---\n");
                int n;
                printf("Nhập số lượng sinh viên: ");
                scanf("%d", &n);
                clearInputBuffer();

                char ten[100][50];
                float diem[100];

                for (int i = 0; i < n; i++) {
                    printf("Nhập tên SV thứ %d: ", i + 1);
                    fgets(ten[i], sizeof(ten[i]), stdin);
                    ten[i][strcspn(ten[i], "\n")] = 0;
                    
                    printf("Nhập điểm SV thứ %d: ", i + 1);
                    scanf("%f", &diem[i]);
                    clearInputBuffer();
                }

                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (diem[i] < diem[j]) {
                            float tempD = diem[i];
                            diem[i] = diem[j];
                            diem[j] = tempD;

                            char tempT[50];
                            strcpy(tempT, ten[i]);
                            strcpy(ten[i], ten[j]);
                            strcpy(ten[j], tempT);
                        }
                    }
                }

                printf("\nDANH SÁCH SINH VIÊN SẮP XẾP GIẢM DẦN:\n");
                for (int i = 0; i < n; i++) {
                    char hocLuc[20];
                    if (diem[i] >= 9.0) strcpy(hocLuc, "Xuất sắc");
                    else if (diem[i] >= 8.0) strcpy(hocLuc, "Giỏi");
                    else if (diem[i] >= 6.5) strcpy(hocLuc, "Khá");
                    else if (diem[i] >= 5.0) strcpy(hocLuc, "Trung bình");
                    else strcpy(hocLuc, "Yếu");

                    printf("Họ tên: %-20s | Điểm: %-4.1f | Học lực: %s\n", ten[i], diem[i], hocLuc);
                }
                break;
            }

            case 9: {
                printf("\n--- Chức năng 9: Game Lott (FPOLY-LOTT) ---\n");
                int s1, s2;
                printf("Nhập số thứ nhất (1-15): ");
                scanf("%d", &s1);
                printf("Nhập số thứ hai (1-15): ");
                scanf("%d", &s2);
                clearInputBuffer();

                if (s1 < 1 || s1 > 15 || s2 < 1 || s2 > 15 || s1 == s2) {
                    printf("=> Vui lòng nhập 2 số khác nhau trong khoảng từ 1 đến 15!\n");
                } else {
                    int r1 = rand() % 15 + 1;
                    int r2 = rand() % 15 + 1;

                    printf("Kết quả sổ xố hệ thống: %d - %d\n", r1, r2);

                    int count = 0;
                    if (s1 == r1 || s1 == r2) count++;
                    if (s2 == r1 || s2 == r2) count++;

                    if (count == 2) {
                        printf("=> Chúc mừng bạn đã trúng GIẢI NHẤT!\n");
                    } else if (count == 1) {
                        printf("=> Chúc mừng bạn đã trúng GIẢI NHÌ!\n");
                    } else {
                        printf("=> Chúc bạn may mắn lần sau!\n");
                    }
                }
                break;
            }

            case 10: {
                printf("\n--- Chức năng 10: Tính toán phân số ---\n");
                int tu1, mau1, tu2, mau2;
                printf("Nhập phân số 1 (tử và mẫu): ");
                scanf("%d%d", &tu1, &mau1);
                printf("Nhập phân số 2 (tử và mẫu): ");
                scanf("%d%d", &tu2, &mau2);
                clearInputBuffer();

                if (mau1 == 0 || mau2 == 0) {
                    printf("=> Mẫu số không được bằng 0!\n");
                } else {
                    printf("Tổng: ");
                    inPhanSo(tu1, mau1); printf(" + "); inPhanSo(tu2, mau2); printf(" = ");
                    inPhanSo(tu1 * mau2 + tu2 * mau1, mau1 * mau2); printf("\n");

                    printf("Hiệu: ");
                    inPhanSo(tu1, mau1); printf(" - "); inPhanSo(tu2, mau2); printf(" = ");
                    inPhanSo(tu1 * mau2 - tu2 * mau1, mau1 * mau2); printf("\n");

                    printf("Tích: ");
                    inPhanSo(tu1, mau1); printf(" * "); inPhanSo(tu2, mau2); printf(" = ");
                    inPhanSo(tu1 * tu2, mau1 * mau2); printf("\n");

                    printf("Thương: ");
                    if (tu2 == 0) {
                        printf("Không thể chia cho 0!\n");
                    } else {
                        inPhanSo(tu1, mau1); printf(" / "); inPhanSo(tu2, mau2); printf(" = ");
                        inPhanSo(tu1 * mau2, mau1 * tu2); printf("\n");
                    }
                }
                break;
            }

            case 11:
                printf("\nCảm ơn bạn đã sử dụng chương trình!\n");
                break;

            default:
                printf("\nLựa chọn không hợp lệ! Vui lòng chọn từ 1 đến 11.\n");
                break;
        }
    } while (choice != 11);

    return 0;
}