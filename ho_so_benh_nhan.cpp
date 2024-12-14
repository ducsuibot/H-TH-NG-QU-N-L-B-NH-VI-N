#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// Struct cho bac si
typedef struct BacSi {
    char ten[50];          // Ten bac si
    char chuyenKhoa[50];   // Chuyen khoa
    char soDienThoai[15];  // So dien thoai
} BacSi;

// Struct cho danh sach thuoc
typedef struct Thuoc {
    char ten[50];         // Ten thuoc
    int soLuong;          // So luong thuoc
    struct Thuoc* next;   // Con tro toi thuoc tiep theo trong danh sach
} Thuoc;

// Struct cho benh an
typedef struct BenhAn {
    char tenBenhAn[50];    // Ten benh an
    char ngayKham[20];     // Ngay kham
    BacSi bacSiPhuTrach;   // Thong tin bac si phu trach
    Thuoc* danhSachThuoc;  // Danh sach thuoc
    struct BenhAn* next;   // Con tro toi benh an tiep theo trong danh sach
} BenhAn;

// Struct cho benh nhan
typedef struct BenhNhan { 
    int id;
    char ten[50];          // Ten benh nhan
    int tuoi;              // Tuoi benh nhan
    char gioiTinh[10];     // Gioi tinh benh nhan
    BenhAn* danhSachBenhAn; // Danh sach benh an
    struct BenhNhan* next;  // Con tro toi benh nhan tiep theo trong danh sach
} BenhNhan; 

// Ham nhap thong tin thuoc
Thuoc* nhapThuoc() {
    Thuoc* thuocMoi = (Thuoc*)malloc(sizeof(Thuoc)); // Cap phat bo nho
    printf("Nhap ten thuoc: ");
    gets(thuocMoi->ten);                             // Nhap ten thuoc
    printf("Nhap so luong thuoc: ");
    scanf("%d", &thuocMoi->soLuong);                // Nhap so luong thuoc
    getchar(); // Doc ky tu '\n' con lai sau khi nhap so
    thuocMoi->next = NULL;                          // Chua co thuoc tiep theo
    return thuocMoi;                                // Tra ve thuoc moi
}

// Ham nhap thong tin bac si
BacSi nhapBacSi() {
    BacSi bacSiMoi;
    printf("Nhap ten bac si: ");
    gets(bacSiMoi.ten);                             // Nhap ten bac si
    printf("Nhap chuyen khoa bac si: ");
    gets(bacSiMoi.chuyenKhoa);                      // Nhap chuyen khoa
    printf("Nhap so dien thoai bac si: ");
    gets(bacSiMoi.soDienThoai);                     // Nhap so dien thoai
    return bacSiMoi;                                // Tra ve bac si
}

// Ham nhap thong tin benh an
BenhAn* nhapBenhAn() {
    BenhAn* benhAnMoi = (BenhAn*)malloc(sizeof(BenhAn)); // Cap phat bo nho
    printf("Nhap ten benh an: ");
    gets(benhAnMoi->tenBenhAn);                        // Nhap ten benh an
    printf("Nhap ngay kham: ");
    gets(benhAnMoi->ngayKham);                         // Nhap ngay kham

    // Nhap thong tin bac si phu trach cho benh an
    BacSi bacSiPhuTrach = nhapBacSi();                // Nhap bac si phu trach
    benhAnMoi->bacSiPhuTrach = bacSiPhuTrach;         // Gan bac si phu trach

    // Nhap danh sach thuoc cho benh an
    printf("Nhap so luong thuoc: ");
    int soLuongThuoc;
    scanf("%d", &soLuongThuoc);
    getchar(); // Doc ky tu '\n' con lai sau khi nhap so

    Thuoc* danhSachThuoc = NULL;  // Khoi tao danh sach thuoc rong
    Thuoc* thuocCuoi = NULL;

    // Nhap tung thuoc
    for (int i = 0; i < soLuongThuoc; i++) {
        Thuoc* thuocMoi = nhapThuoc();   // Nhap thong tin thuoc moi
        if (danhSachThuoc == NULL) {
            danhSachThuoc = thuocMoi;    // Neu danh sach rong, thu thuoc dau tien lam dau danh sach
        } else {
            thuocCuoi->next = thuocMoi;  // Gan thuoc moi vao cuoi danh sach
        }
        thuocCuoi = thuocMoi;            // Cap nhat lai cuoi danh sach
    }
    
    benhAnMoi->danhSachThuoc = danhSachThuoc;  // Gan danh sach thuoc cho benh an
    benhAnMoi->next = NULL;                     // Chua co benh an tiep theo
    return benhAnMoi;                           // Tra ve benh an moi
}

// Ham nhap thong tin benh nhan
BenhNhan* nhapBenhNhan() {
    BenhNhan* benhNhanMoi = (BenhNhan*)malloc(sizeof(BenhNhan)); // Cap phat bo nho
    printf("Nhap ID benh nhan: ");
    scanf("%d", &benhNhanMoi->id);                              // Nhap ID benh nhan
    getchar(); // Doc ky tu '\n' con lai sau khi nhap so
    printf("Nhap ten benh nhan: ");
    gets(benhNhanMoi->ten);                                       // Nhap ten benh nhan
    printf("Nhap tuoi benh nhan: ");
    scanf("%d", &benhNhanMoi->tuoi);                             // Nhap tuoi benh nhan
    getchar(); // Doc ky tu '\n' con lai sau khi nhap so
    printf("Nhap gioi tinh benh nhan: ");
    gets(benhNhanMoi->gioiTinh);                                  // Nhap gioi tinh benh nhan

    // Nhap danh sach benh an cho benh nhan
    printf("Nhap so luong benh an: ");
    int soLuongBenhAn;
    scanf("%d", &soLuongBenhAn);
    getchar(); // Doc ky tu '\n' con lai sau khi nhap so

    BenhAn* danhSachBenhAn = NULL;  // Khoi tao danh sach benh an rong
    BenhAn* benhAnCuoi = NULL;

    // Nhap tung benh an
    for (int i = 0; i < soLuongBenhAn; i++) {
        BenhAn* benhAnMoi = nhapBenhAn();  // Nhap thong tin benh an moi
        if (danhSachBenhAn == NULL) {
            danhSachBenhAn = benhAnMoi;    // Neu danh sach rong, benh an dau tien lam dau danh sach
        } else {
            benhAnCuoi->next = benhAnMoi;  // Gan benh an moi vao cuoi danh sach
        }
        benhAnCuoi = benhAnMoi;            // Cap nhat lai cuoi danh sach
    }

    benhNhanMoi->danhSachBenhAn = danhSachBenhAn;  // Gan danh sach benh an cho benh nhan
    benhNhanMoi->next = NULL;                       // Chua co benh nhan tiep theo
    return benhNhanMoi;                             // Tra ve benh nhan moi
}

// Ham them benh nhan vao danh sach
void themBenhNhan(BenhNhan** danhSach, BenhNhan* benhNhanMoi) {
    if (*danhSach == NULL) {
        *danhSach = benhNhanMoi; // Neu danh sach rong, gan benh nhan moi vao
    } else {
        BenhNhan* temp = *danhSach; 
        while (temp->next != NULL) {
            temp = temp->next; // Di chuyen den cuoi danh sach
        }
        temp->next = benhNhanMoi; // Them benh nhan moi vao cuoi danh sach
    }
}

// Ham xoa benh nhan theo ID
void xoaBenhNhan(BenhNhan** danhSach, int id) {
    BenhNhan* temp = *danhSach;
    BenhNhan* prev = NULL;

    // Kiem tra benh nhan dau tien
    if (temp != NULL && temp->id == id) {
        *danhSach = temp->next;  // Xoa benh nhan dau tien
        free(temp);
        printf("Benh nhan co ID %d da duoc xoa.\n", id);
        return;
    }

    // Tim benh nhan trong danh sach
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // Neu benh nhan khong duoc tim thay
    if (temp == NULL) {
        printf("Khong tim thay benh nhan co ID %d.\n", id);
        return;
    }

    // Xoa benh nhan
    prev->next = temp->next;
    free(temp);
    printf("Benh nhan co ID %d da duoc xoa.\n", id);
}

// Ham in danh sach benh nhan
void inDanhSachBenhNhan(BenhNhan* danhSach) {
    BenhNhan* temp = danhSach;
    while (temp != NULL) {
        printf("ID: %d, Ten: %s, Tuoi: %d, Gioi tinh: %s\n", temp->id, temp->ten, temp->tuoi, temp->gioiTinh);
        
        BenhAn* tempBenhAn = temp->danhSachBenhAn;
        while (tempBenhAn != NULL) {
            printf("  Ten benh an: %s, Ngay kham: %s, Bac si: %s\n", tempBenhAn->tenBenhAn, tempBenhAn->ngayKham, tempBenhAn->bacSiPhuTrach.ten);

            Thuoc* tempThuoc = tempBenhAn->danhSachThuoc;
            while (tempThuoc != NULL) {
                printf("    Thuoc: %s, So luong: %d\n", tempThuoc->ten, tempThuoc->soLuong);
                tempThuoc = tempThuoc->next;
            }

            tempBenhAn = tempBenhAn->next;
        }

        temp = temp->next;
    }
}

int main() {
    BenhNhan* danhSachBenhNhan = NULL; // Danh sach benh nhan rong
    int luaChon;

    do {
        printf("\nMenu:\n");
        printf("1. Them benh nhan\n");
        printf("2. Xoa benh nhan theo ID\n");
        printf("3. In danh sach benh nhan\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        getchar(); // Doc ky tu '\n' con lai sau khi nhap so

        switch (luaChon) {
            case 1:
                {
                    BenhNhan* benhNhanMoi = nhapBenhNhan();
                    themBenhNhan(&danhSachBenhNhan, benhNhanMoi);
                    printf("Da them benh nhan thanh cong!\n");
                    break;
                }
            case 2:
                {
                    printf("Nhap ID benh nhan can xoa: ");
                    int idXoa;
                    scanf("%d", &idXoa);
                    xoaBenhNhan(&danhSachBenhNhan, idXoa);
                    break;
                }
            case 3:
                inDanhSachBenhNhan(danhSachBenhNhan);
                break;
            case 0:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}

