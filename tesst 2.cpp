//	  |  ====GROUP 1====  |
// 	  | Nguyen Minh Duc   |
// 	  | Ngo Trung Hieu    |
// 	  | Nguyen Tuan Viet  |
// 	  | Ha Manh Chien     |
// 	  | Le Hoang Long     |
//================================ HE THONG QUAN LY BENH VIEN BANG CAU TRUC DSLK DON =========================================// 

#include <stdio.h> 
#include<stdlib.h> 
#include<string.h>  

//================================== DINH NGHIA CAC CAU TRUC DSLK, BIEN CAU TRUC =============================================// 

// dinh nghia danh sach thuoc 
typedef struct thuoc{ 
	int ID_thuoc; 
	char ten_thuoc[50]; 
	double gia_thuoc; 
	struct thuoc* next; 
	struct thuoc* prev; 
} thuoc; 

// Dinh nghia benh nhan
typedef struct benh_nhan {
    int ID_benh_nhan;      // Ma benh nhan
    char ho_ten[50];       // Ho ten
    char SDT[15];          // So dien thoai
    char ngay_sinh[15];    // Ngay sinh
    char gioi_tinh[10];    // Gioi tinh
    char CCCD[20];         // So CCCD 
} benh_nhan;

// Dinh nghia danh sach cac benh an
typedef struct benh_an {
    int ID_benh_an;            // Ma benh an
    char ngay_kham[11];        // Ngay kham
    char ten_benh_an[50];      // Ten benh an
    benh_nhan benh_nhan;       // Thong tin benh nhan 
    thuoc* danh_sach_thuoc;    // DSLK thuoc cua 1 benh_an
    struct benh_an* next;      // Con tro den benh an tiep theo 
    struct benh_an* prev;	   // con tro den benh an truoc do
} benh_an;

// Dinh nghia danh sach bac si trong benh vien
typedef struct bac_si {
    int ID_bac_si;             // Ma bac si
    char ho_ten[50];           // Ho ten bac si
    char SDT[15];              // So dien thoai
    char gmail[50];            // Email
    benh_an* danh_sach_benh_an; // DSLK benh an cua 1 bac_si
    struct bac_si* next;       // Con tro den bac si tiep theo 
    struct bac_si* prev;       // Con tro den bac si truoc do
} bac_si;

// Dinh nghia danh sach cac khoa trong benh vien
typedef struct khoa {
    char ten_khoa[50];         // Ten khoa
    bac_si* danh_sach_bac_si;  // DSLK bac_si cua 1 khoa
    struct khoa* next;         // Con tro den khoa tiep theo 
    struct khoa* prev;
} khoa;
   
//================================== CAC HAM TIM KIEM THONG TIN TRONG HE THONG ================================================// 

// Ham tim kiem 1 khoa trong DSLK khoa theo ten 
khoa* tim_khoa(khoa* Head_khoa, char ten_khoa[]) { 
    khoa* temp_khoa = Head_khoa;
    while (temp_khoa != NULL) {
        if (strcmp(temp_khoa->ten_khoa, ten_khoa) == 0) {
            return temp_khoa;  // Tra ve con tro den khoa tim duoc
        }
        temp_khoa = temp_khoa->next;  // Duyet tiep khoa tiep theo
    }
    return NULL;  // Khong tim thay khoa thi exit
} 
  
// Ham tim kiem bac_si theo ID
bac_si* tim_bac_si_theo_ID(khoa* danh_sach_khoa, int ID_bac_si) {
    // Duyet tung khoa trong DSLK cac khoa
    while (danh_sach_khoa != NULL) {
        // Duyet danh_sach_b?c_si trong khoa hien tai
        bac_si* temp = danh_sach_khoa->danh_sach_bac_si;
        while (temp != NULL) {
            if (temp->ID_bac_si == ID_bac_si) {
                return temp; // Tro ve con tro den b?c si tim thay
            }
            temp = temp->next; // Chuyen sang bac si tiep theo
        }
        danh_sach_khoa = danh_sach_khoa->next; // Chuyen sang khoa tiep theo neu k tim thay
    }
    return NULL; // Khong tim thay bac si
}

// Ham tim benh_an theo ID 
benh_an* tim_benh_an_theo_ID(khoa* danh_sach_khoa, int ID_benh_an) {
    // Duyet tung khoa trong danh sach cac khoa
    while (danh_sach_khoa != NULL) {
        // Duyet danh sach bac si trong khoa hien tai
        bac_si* danh_sach_bac_si = danh_sach_khoa->danh_sach_bac_si;
        while (danh_sach_bac_si != NULL) {
            // Duyet danh sach benh an cua bac si hien tai
            benh_an* danh_sach_benh_an = danh_sach_bac_si->danh_sach_benh_an;
            while (danh_sach_benh_an != NULL) {
                if (danh_sach_benh_an->ID_benh_an == ID_benh_an) {
                    return danh_sach_benh_an; // Tra ve con tro den benh an tim duoc
                }
                danh_sach_benh_an = danh_sach_benh_an->next; // Chuyen sang benh an tiep theo
            }
            danh_sach_bac_si = danh_sach_bac_si->next; // Chuyen sang bac si tiep theo
        }
        danh_sach_khoa = danh_sach_khoa->next; // Chuyen sang khoa tiep theo
    }
    return NULL; // Khong tim thay benh an
}


//====================================== CAC HAM THEM THONG TIN VAO HE THONG =================================================// 

//--------- HAM THEM TRONG DSLK KHOA ------------// 

void them_Khoa_vao_dau_DSLK(khoa**Head,char ten_khoa[50]){  
    //cap phat dong 1 khoa moi
 	khoa* new_khoa=(khoa*)malloc(sizeof(khoa)); 
 	if(new_khoa==NULL){ 
 		printf("khong du bo nho de cap phat!"); 
 		return; 
	 } 
 	
 	// Khoi tao gia tri cho khoa moi
    strcpy(new_khoa->ten_khoa, ten_khoa);
    new_khoa->danh_sach_bac_si = NULL; // Ban dau khong co bac si
    new_khoa->next = *Head;            // Ket noi khoa moi voi danh sach hien tai
    new_khoa->prev = NULL;             // Khoa moi la phan tu dau tien nen prev = NULL

    // Neu danh sach khong rong, cap nhat prev cua khoa dau tien
    if (*Head != NULL) {
        (*Head)->prev = new_khoa;
    }

    // Cap nhat con tro Head de tro den khoa moi
    *Head = new_khoa;

    printf("Them khoa '%s' vao dau DSLK thanh cong!\n", ten_khoa);
 } 
  
void them_khoa_vao_cuoi_DSLK(khoa** Head, char ten_khoa[50]) {
    // Cap phat bo nho cho khoa moi
    khoa* new_khoa = (khoa*)malloc(sizeof(khoa));
    if (new_khoa == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        return;
    }

    // Khoi tao gia tri cho khoa moi
    strcpy(new_khoa->ten_khoa, ten_khoa);
    new_khoa->danh_sach_bac_si = NULL; // Ban dau khong co bac si nen la NULL
    new_khoa->next = NULL;             // Khoa moi se la phan tu cuoi nên next = NULL

    // Neu danh sach rong, khoa moi se la phan tu dau tien
    if (*Head == NULL) {
        new_khoa->prev = NULL;         // Khong co phan tu tru?=oc dó
        *Head = new_khoa;              // Cap nhat Head tro den khoa moi
    } else {
        // Duyet den phan tu cuoi danh sach
        khoa* temp = *Head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Gan khoa moi vao cuoi danh sach
        temp->next = new_khoa;
        new_khoa->prev = temp;
    }

    printf("Them khoa '%s' vao cuoi DSLK thanh cong!\n", ten_khoa);
}
  
//--------- HAM THEM TRONG DSLK BAC_SI ----------// 

void them_bac_si_vao_dau(khoa* Head_khoa, char ten_khoa[], int ID_bac_si, char ho_ten[], char SDT[], char gmail[]) {
    // Tim khoa theo ten
    khoa* khoa_tim_duoc = tim_khoa(Head_khoa, ten_khoa);
    if (khoa_tim_duoc == NULL) {
        printf("Khoa %s khong ton tai!\n", ten_khoa);
        return;
    }

    // Cap phat dong cho bac si moi
    bac_si* new_bac_si = (bac_si*)malloc(sizeof(bac_si));
    if (new_bac_si == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        return;
    }

    // Gan gia tri cho bac si moi
    new_bac_si->ID_bac_si = ID_bac_si;
    strcpy(new_bac_si->ho_ten, ho_ten);
    strcpy(new_bac_si->SDT, SDT);
    strcpy(new_bac_si->gmail, gmail);
    new_bac_si->danh_sach_benh_an = NULL;

    // Them vao dau danh sach
    new_bac_si->next = khoa_tim_duoc->danh_sach_bac_si;
    new_bac_si->prev = NULL;
    if (khoa_tim_duoc->danh_sach_bac_si != NULL) {
        khoa_tim_duoc->danh_sach_bac_si->prev = new_bac_si;
    }
    khoa_tim_duoc->danh_sach_bac_si = new_bac_si;

    printf("Them bac si %s vao dau khoa %s thanh cong!\n", ho_ten, ten_khoa);
}
 
void them_bac_si_vao_cuoi(khoa* Head_khoa, char ten_khoa[], int ID_bac_si, char ho_ten[], char SDT[], char gmail[]) {
    // Tim khoa theo ten
    khoa* khoa_tim_duoc = tim_khoa(Head_khoa, ten_khoa);
    if (khoa_tim_duoc == NULL) {
        printf("Khoa %s khong ton tai!\n", ten_khoa);
        return;
    }

    // Cap phat dong cho bac si moi
    bac_si* new_bac_si = (bac_si*)malloc(sizeof(bac_si));
    if (new_bac_si == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        return;
    }

    // Gan gia tri cho bac si moi
    new_bac_si->ID_bac_si = ID_bac_si;
    strcpy(new_bac_si->ho_ten, ho_ten);
    strcpy(new_bac_si->SDT, SDT);
    strcpy(new_bac_si->gmail, gmail);
    new_bac_si->danh_sach_benh_an = NULL;
    new_bac_si->next = NULL;

    // Neu danh sach rong, them bac si moi vao dau
    if (khoa_tim_duoc->danh_sach_bac_si == NULL) {
        new_bac_si->prev = NULL;
        khoa_tim_duoc->danh_sach_bac_si = new_bac_si;
    } else {
        // Duyet den phan tu cuoi danh sach
        bac_si* temp = khoa_tim_duoc->danh_sach_bac_si;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Them bac si moi vao cuoi danh sach
        temp->next = new_bac_si;
        new_bac_si->prev = temp;
    }

    printf("Them bac si %s vao cuoi khoa %s thanh cong!\n", ho_ten, ten_khoa);
}

//---------- HAM THEM TRONG DSLK BENH_AN ----------// 

void them_benh_an_vao_dau(bac_si* bac_si_tim_duoc, int ID_benh_an, char ngay_kham[], char ten_benh_an[], int ID_benh_nhan, char ho_ten[], char SDT[], char ngay_sinh[], char gioi_tinh[], char CCCD[]) {
    if (bac_si_tim_duoc == NULL) {
        printf("Khong tim thay bac si.\n");
        return;
    }

    // Cap phat bo nho cho benh an moi
    benh_an* new_benh_an = (benh_an*)malloc(sizeof(benh_an));
    if (new_benh_an == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        return;
    }

    // Gan thong tin benh an
    new_benh_an->ID_benh_an = ID_benh_an;
    strcpy(new_benh_an->ngay_kham, ngay_kham);
    strcpy(new_benh_an->ten_benh_an, ten_benh_an);

    // Gan thong tin benh nhan vao benh an
    new_benh_an->benh_nhan.ID_benh_nhan = ID_benh_nhan;
    strcpy(new_benh_an->benh_nhan.ho_ten, ho_ten);
    strcpy(new_benh_an->benh_nhan.SDT, SDT);
    strcpy(new_benh_an->benh_nhan.ngay_sinh, ngay_sinh);
    strcpy(new_benh_an->benh_nhan.gioi_tinh, gioi_tinh);
    strcpy(new_benh_an->benh_nhan.CCCD, CCCD);

    // Khoi tao danh sach thuoc rong cho benh an moi
    new_benh_an->danh_sach_thuoc = NULL;

    // Them vao dau danh sach
    new_benh_an->next = bac_si_tim_duoc->danh_sach_benh_an;
    new_benh_an->prev = NULL;
    if (bac_si_tim_duoc->danh_sach_benh_an != NULL) {
        bac_si_tim_duoc->danh_sach_benh_an->prev = new_benh_an;
    }
    bac_si_tim_duoc->danh_sach_benh_an = new_benh_an;

    printf("Them benh an '%s' vao dau danh sach cua bac si '%s' thanh cong!\n", ten_benh_an, bac_si_tim_duoc->ho_ten);
}

void them_benh_an_vao_cuoi(bac_si* bac_si_tim_duoc, int ID_benh_an, char ngay_kham[], char ten_benh_an[], int ID_benh_nhan, char ho_ten[], char SDT[], char ngay_sinh[], char gioi_tinh[], char CCCD[]) {
    if (bac_si_tim_duoc == NULL) {
        printf("Khong tim thay bac si.\n");
        return;
    }

    // Cap phat bo nho cho benh an moi
    benh_an* new_benh_an = (benh_an*)malloc(sizeof(benh_an));
    if (new_benh_an == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        return;
    }

    // Gan thong tin benh an
    new_benh_an->ID_benh_an = ID_benh_an;
    strcpy(new_benh_an->ngay_kham, ngay_kham);
    strcpy(new_benh_an->ten_benh_an, ten_benh_an);

    // Gan thong tin benh nhan vao benh an
    new_benh_an->benh_nhan.ID_benh_nhan = ID_benh_nhan;
    strcpy(new_benh_an->benh_nhan.ho_ten, ho_ten);
    strcpy(new_benh_an->benh_nhan.SDT, SDT);
    strcpy(new_benh_an->benh_nhan.ngay_sinh, ngay_sinh);
    strcpy(new_benh_an->benh_nhan.gioi_tinh, gioi_tinh);
    strcpy(new_benh_an->benh_nhan.CCCD, CCCD);

    // Khoi tao danh sach thuoc rong cho benh an moi
    new_benh_an->danh_sach_thuoc = NULL;

    // Neu danh sach rong, them vao dau
    if (bac_si_tim_duoc->danh_sach_benh_an == NULL) {
        new_benh_an->next = NULL;
        new_benh_an->prev = NULL;
        bac_si_tim_duoc->danh_sach_benh_an = new_benh_an;
    } else {
        // Duyet den phan tu cuoi danh sách
        benh_an* temp = bac_si_tim_duoc->danh_sach_benh_an;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Them benh an moi vao cuoi danh sach
        temp->next = new_benh_an;
        new_benh_an->prev = temp;
        new_benh_an->next = NULL;
    }

    printf("Them benh an '%s' vao cuoi danh sach cua bac si '%s' thanh cong!\n", ten_benh_an, bac_si_tim_duoc->ho_ten);
}

//----------- HAM THEM TRONG DSLK THUOC -------------//

void them_thuoc_vao_dau(khoa* danh_sach_khoa, int ID_benh_an, int ID_thuoc, char ten_thuoc[], double gia_thuoc) {
    // Tim benh an theo ID 
    benh_an* benh_an_tim_duoc = tim_benh_an_theo_ID(danh_sach_khoa, ID_benh_an);

    // Neu khong tim thay benh an, thong bao va thoat ham
    if (benh_an_tim_duoc == NULL) {
        printf("Khong tim thay benh an co ID %d!\n", ID_benh_an);
        return;
    }

    // Cap phat bo nho cho thuoc moi
    thuoc* new_thuoc = (thuoc*)malloc(sizeof(thuoc));
    if (new_thuoc == NULL) {
        printf("Khong du bo nho de cap phat thuoc!\n");
        return;
    }

    // Gan gia tri cho thuoc moi
    new_thuoc->ID_thuoc = ID_thuoc;
    strcpy(new_thuoc->ten_thuoc, ten_thuoc);
    new_thuoc->gia_thuoc = gia_thuoc;

    // Gan thuoc moi vao dau DSLK thuoc
    new_thuoc->next = benh_an_tim_duoc->danh_sach_thuoc;
    new_thuoc->prev = NULL; // Vi gan vao vi tri dau tien nen prev tro ve NULL

    // Neu danh sach thuoc khong rong, cap nhat con tro `prev` cua phan tu dau tien
    if (benh_an_tim_duoc->danh_sach_thuoc != NULL) {
        benh_an_tim_duoc->danh_sach_thuoc->prev = new_thuoc;
    }

    // Cap nhat danh sach thuoc de tro den thuoc moi
    benh_an_tim_duoc->danh_sach_thuoc = new_thuoc;

    printf("Them thuoc '%s' vao dau danh sach thuoc cua benh an ID %d thanh cong!\n", ten_thuoc, ID_benh_an);
}

void them_thuoc_vao_cuoi(khoa* danh_sach_khoa, int ID_benh_an, int ID_thuoc, char ten_thuoc[], double gia_thuoc) {
    // Tim benh an theo ID 
    benh_an* benh_an_tim_duoc = tim_benh_an_theo_ID(danh_sach_khoa, ID_benh_an);

    // Neu khong tim thay benh an, thong bao va thoat ham
    if (benh_an_tim_duoc == NULL) {
        printf("Khong tim thay benh an co ID %d!\n", ID_benh_an);
        return;
    }

    // Cap phat bo nho cho thuoc moi
    thuoc* new_thuoc = (thuoc*)malloc(sizeof(thuoc));
    if (new_thuoc == NULL) {
        printf("Khong du bo nho de cap phat thuoc!\n");
        return;
    }

    // Gan gia tri cho thuoc moi
    new_thuoc->ID_thuoc = ID_thuoc;
    strcpy(new_thuoc->ten_thuoc, ten_thuoc);
    new_thuoc->gia_thuoc = gia_thuoc;
    new_thuoc->next = NULL; // Vi gan vao cuoi cung nen next la NULL

    // Neu DSLK thuoc rong, them vao dau
    if (benh_an_tim_duoc->danh_sach_thuoc == NULL) {
        new_thuoc->prev = NULL;
        benh_an_tim_duoc->danh_sach_thuoc = new_thuoc;
    } else {
        // Duyet den phan tu cuoi DSLK thuoc
        thuoc* temp = benh_an_tim_duoc->danh_sach_thuoc;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Them thuoc moi vao cuoi danh sach
        temp->next = new_thuoc;
        new_thuoc->prev = temp;
    }

    printf("Them thuoc '%s' vao cuoi danh sach thuoc cua benh an ID %d thanh cong!\n", ten_thuoc, ID_benh_an);
}


//====================================== CAC HAM XOA THONG TIN TRONG HE THONG =================================================//  
 
//----------- HAM XOA TRONG DSLK KHOA -------------// 

void xoa_khoa_dau(khoa** Head) {
    // Kiem tra danh sach rong
    if (*Head == NULL) {
        printf("Danh sach khoa rong, khong co khoa de xoa!\n");
        return;
    }
    // luu con tro dau khoa de ti giai phong
    khoa* khoa_can_xoa = *Head;

    // Cap nhat con tro Head tro den khoa ke tiep
    *Head = khoa_can_xoa->next;

    // Neu danh sach khong rong sau khi xaa, cap nhat `prev` Head
    if (*Head != NULL) {
        (*Head)->prev = NULL;
    }

    // Giai phong bo nho cua khoa vua xoa
    free(khoa_can_xoa);

    printf("Xoa khoa o dau danh sach thanh cong!\n");
}

void xoa_khoa_cuoi(khoa** Head) {
    // Kiem tra danh sach rong
    if (*Head == NULL) {
        printf("Danh sach khoa rong, khong co khoa de xoa!\n");
        return;
    }

    // Truong hop chi có mot khoa
    if ((*Head)->next == NULL) {
        free(*Head);
        *Head = NULL;
        printf("Xoa khoa o cuoi danh sach thanh cong!\n");
        return;
    }

    // Duyet den khoa cuoi
    khoa* temp = *Head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Cap nhat con tro `next` cua khoa truoc do
    temp->prev->next = NULL;

    // Giai phong bo nho cua khoa vua xoa
    free(temp);

    printf("Xoa khoa o cuoi danh sach thanh cong!\n");
}

void xoa_khoa_theo_ten(khoa** Head, char ten_khoa[]) {
    // Su dung ham tim_khoa theo tên
    khoa* khoa_tim_duoc = tim_khoa(*Head, ten_khoa);

    // Neu khong tim thay khoa, thong bao va thoat
    if (khoa_tim_duoc == NULL) {
        printf("Khong tim thay khoa co ten '%s' trong danh sach!\n", ten_khoa);
        return;
    }

    // Neu khoa can xoa la dau danh sach
    if (khoa_tim_duoc == *Head) {
        *Head = khoa_tim_duoc->next;  // Cap nhat Head tro den phan tu tiep theo
        if (*Head != NULL) {
            (*Head)->prev = NULL;  // Cap nhat prev cua Head
        }
    }
    // Neu khoa can xoa la cuoi danh sach
    else if (khoa_tim_duoc->next == NULL) {
        khoa_tim_duoc->prev->next = NULL;  // C?p nh?t next c?a ph?n t? tru?c dó
    }
    // Neu khoa can xoa nam giua danh sach
    else {
        khoa_tim_duoc->prev->next = khoa_tim_duoc->next;  // Noi phan tu truoc voi phan tu sau bang next
        khoa_tim_duoc->next->prev = khoa_tim_duoc->prev;  // Noi phan tu sau voi phan tu truoc bang prev
    }

    // Giai phong bo nho cua khoa vua xoa
    free(khoa_tim_duoc);

    printf("Xoa khoa co ten '%s' thanh cong!\n", ten_khoa);
}

//----------- HAM XOA TRONG DSLK BAC_SI -------------//   

void xoa_bac_si_dau(khoa* Head_khoa, char ten_khoa[]) {
    // Tìm khoa theo tên
    khoa* khoa_tim_duoc = tim_khoa(Head_khoa, ten_khoa);
    if (khoa_tim_duoc == NULL) {
        printf("Khoa %s khong ton tai!\n", ten_khoa);
        return;
    }

    // Kiem tra danh sach bac si cua khoa
    if (khoa_tim_duoc->danh_sach_bac_si == NULL) {
        printf("Khoa %s khong co bac si!\n", ten_khoa);
        return;
    }

    // Luu bac si dau danh sach khoa de ti nua giai phong
    bac_si* bac_si_dau = khoa_tim_duoc->danh_sach_bac_si;

    // di chuyen Head sang phai
    khoa_tim_duoc->danh_sach_bac_si = bac_si_dau->next;

    // Neu dslk Khoa hien tai khong rong, cap nhat lai prev cua Head
    if (khoa_tim_duoc->danh_sach_bac_si != NULL) {
        khoa_tim_duoc->danh_sach_bac_si->prev = NULL;
    }

    // Giai phong bo nho cua bac si vua xoa
    free(bac_si_dau);

    printf("Xoa bac si dau cua khoa '%s' thanh cong!\n", ten_khoa);
}

void xoa_bac_si_cuoi(khoa* Head_khoa, char ten_khoa[]) {
    // Tìm khoa theo tên
    khoa* khoa_tim_duoc = tim_khoa(Head_khoa, ten_khoa);
    if (khoa_tim_duoc == NULL) {
        printf("Khoa %s khong ton tai!\n", ten_khoa);
        return;
    }

    // Kiem tra DSLK co rong khong
    if (khoa_tim_duoc->danh_sach_bac_si == NULL) {
        printf("Khoa %s khong co bac si!\n", ten_khoa);
        return;
    }

    // Duyet den bac si cuoi cung trong danh sach bac si
    bac_si* bac_si_cuoi = khoa_tim_duoc->danh_sach_bac_si;
    while (bac_si_cuoi->next != NULL) {
        bac_si_cuoi = bac_si_cuoi->next;
    }

    // Neu bac si cuoi cung la bac si duy nhat
    if (bac_si_cuoi->prev == NULL) {
        khoa_tim_duoc->danh_sach_bac_si = NULL;
    } else {
        bac_si_cuoi->prev->next = NULL;
    }

    // Giai phong bo nho cua bac si vua xoa
    free(bac_si_cuoi);

    printf("Xoa bac si cuoi cua khoa '%s' thanh cong!\n", ten_khoa);
}

void xoa_bac_si_theo_ID(khoa* danh_sach_khoa, int ID_bac_si) {
    // Duyet qua cac khoa trong danh sach khoa
    khoa* khoa_duyet = danh_sach_khoa;
    while (khoa_duyet != NULL) {
        bac_si* bac_si_duyet = khoa_duyet->danh_sach_bac_si;

        // Duyet qua cac bác si trong khoa hien tai
        while (bac_si_duyet != NULL) {
            if (bac_si_duyet->ID_bac_si == ID_bac_si) {
                // Giai phong bo nho cho danh sach benh án
                benh_an* benh_an_duyet = bac_si_duyet->danh_sach_benh_an;
                while (benh_an_duyet != NULL) {
                    benh_an* benh_an_xoa = benh_an_duyet;
                    benh_an_duyet = benh_an_duyet->next;
                    free(benh_an_xoa); // Giai phong bo nho cho benh an
                }

                // Neu bac si la bac si dau tien trong danh sach cua khoa
                if (bac_si_duyet == khoa_duyet->danh_sach_bac_si) {
                    khoa_duyet->danh_sach_bac_si = bac_si_duyet->next;
                    if (khoa_duyet->danh_sach_bac_si != NULL) {
                        khoa_duyet->danh_sach_bac_si->prev = NULL;
                    }
                } else {
                    // Neu bac si khong phai la bac si dau tien, cap nhat lien ket
                    if (bac_si_duyet->prev != NULL) {
                        bac_si_duyet->prev->next = bac_si_duyet->next;
                    }
                    if (bac_si_duyet->next != NULL) {
                        bac_si_duyet->next->prev = bac_si_duyet->prev;
                    }
                }

                // Giai phong bo nho cho bac si
                free(bac_si_duyet);
                printf("Xoa bac si voi ID %d thanh cong!\n", ID_bac_si);
                return; 
            }
            bac_si_duyet = bac_si_duyet->next; // Duyet tiep bac si ke tiep trong danh sách
        }
        khoa_duyet = khoa_duyet->next; // Duyet tiep khoa ke tiep
    }
    printf("Khong tim thay bac si voi ID %d!\n", ID_bac_si); 
}


//======================================= HAM HIEN THONG TIN TRONG HE THONG ===================================================// 
void display(khoa* head_khoa) {
    if (head_khoa == NULL) {
        printf("He thong quan ly benh vien trong!\n");
        return;
    }

    printf("\n========== DANH SACH CAC KHOA TRONG BENH VIEN ==========\n");
    khoa* temp_khoa = head_khoa;
    while (temp_khoa != NULL) {
        printf("\nKhoa: %s\n", temp_khoa->ten_khoa);

        bac_si* temp_bac_si = temp_khoa->danh_sach_bac_si;
        if (temp_bac_si == NULL) {
            printf("  Khong co bac si nao trong khoa nay.\n");
        } else {
            printf("  Danh sach bac si:\n");
            while (temp_bac_si != NULL) {
                printf("    - ID Bac Si: %d\n", temp_bac_si->ID_bac_si);
                printf("      Ho Ten   : %s\n", temp_bac_si->ho_ten);
                printf("      SDT      : %s\n", temp_bac_si->SDT);
                printf("      Gmail    : %s\n", temp_bac_si->gmail);

                benh_an* temp_benh_an = temp_bac_si->danh_sach_benh_an;
                if (temp_benh_an == NULL) {
                    printf("      Khong co benh an nao.\n");
                } else {
                    printf("      Danh sach benh an:\n");
                    while (temp_benh_an != NULL) {
                        printf("        + ID Benh An   : %d\n", temp_benh_an->ID_benh_an);
                        printf("          Ngay Kham    : %s\n", temp_benh_an->ngay_kham);
                        printf("          Ten Benh An  : %s\n", temp_benh_an->ten_benh_an);
                        printf("          Benh Nhan:\n");
                        printf("            > ID       : %d\n", temp_benh_an->benh_nhan.ID_benh_nhan);
                        printf("            > Ho Ten   : %s\n", temp_benh_an->benh_nhan.ho_ten);
                        printf("            > SDT      : %s\n", temp_benh_an->benh_nhan.SDT);
                        printf("            > Ngay Sinh: %s\n", temp_benh_an->benh_nhan.ngay_sinh);
                        printf("            > Gioi Tinh: %s\n", temp_benh_an->benh_nhan.gioi_tinh);
                        printf("            > CCCD     : %s\n", temp_benh_an->benh_nhan.CCCD);

                        thuoc* temp_thuoc = temp_benh_an->danh_sach_thuoc;
                        if (temp_thuoc == NULL) {
                            printf("          Khong co thuoc nao.\n");
                        } else {
                            printf("          Danh sach thuoc:\n");
                            while (temp_thuoc != NULL) {
                                printf("            * ID Thuoc: %d\n", temp_thuoc->ID_thuoc);
                                printf("              Ten Thuoc: %c\n", temp_thuoc->ten_thuoc); // Ten thuoc dang 'char'
                                printf("              Gia Thuoc: %.2f\n", temp_thuoc->gia_thuoc);
                                temp_thuoc = temp_thuoc->next;
                            }
                        }
                        temp_benh_an = temp_benh_an->next;
                    }
                }
                temp_bac_si = temp_bac_si->next;
            }
        }
        temp_khoa = temp_khoa->next;
    }
    printf("\n========================================================\n");
}

//============================================ MENU DIEU KHIEN HE THONG =======================================================//

void menu(khoa** head_khoa) {
    int choice;
    do {
        printf("\n========== HE THONG QUAN LY BENH VIEN ==========\n");
        printf("1. Them khoa\n");
        printf("2. Them bac si vao khoa\n");
        printf("3. Them benh an cho bac si\n");
        printf("4. Them thuoc cho benh an\n");
        printf("5. Hien thi thong tin he thong\n");
        printf("6. Thoat\n");
        printf("Chon thao tac: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char ten_khoa[50];
                printf("Nhap ten khoa: ");
                scanf(" %[^\n]%*c", ten_khoa); // Dung scanf de nhap xau co khoang trang
                them_Khoa_vao_dau_DSLK(head_khoa, ten_khoa);
                break;
            }
            case 2: {
                char ten_khoa[50], ho_ten[50], SDT[15], gmail[50];
                int ID_bac_si;
                printf("Nhap ten khoa: ");
                scanf(" %[^\n]%*c", ten_khoa);
                printf("Nhap ID bac si: ");
                scanf("%d", &ID_bac_si);
                printf("Nhap ho ten bac si: ");
                scanf(" %[^\n]%*c", ho_ten);
                printf("Nhap so dien thoai bac si: ");
                scanf(" %[^\n]%*c", SDT);
                printf("Nhap email bac si: ");
                scanf(" %[^\n]%*c", gmail);
                them_bac_si_vao_dau(*head_khoa, ten_khoa, ID_bac_si, ho_ten, SDT, gmail);
                break;
            }
            case 3: {
                int ID_bac_si, ID_benh_an,ID_benh_nhan;
                char ngay_kham[11], ten_benh_an[50], ho_ten[50], SDT[15], ngay_sinh[15], gioi_tinh[10], CCCD[20];
                printf("Nhap ID bac si: ");
                scanf("%d", &ID_bac_si);
                bac_si* bac_si_tim_duoc = tim_bac_si_theo_ID(*head_khoa, ID_bac_si);
                if (bac_si_tim_duoc == NULL) {
                    printf("Khong tim thay bac si co ID %d!\n", ID_bac_si);
                    break;
                }
                printf("Nhap ID benh an: ");
                scanf("%d", &ID_benh_an);
                printf("Nhap ngay kham (dd/mm/yyyy): ");
                scanf(" %[^\n]%*c", ngay_kham);
                printf("Nhap ten benh an: ");
                scanf(" %[^\n]%*c", ten_benh_an);
                printf("Nhap ID benh nhan: ");
                scanf("%d", &ID_benh_nhan);
                printf("Nhap ho ten benh nhan: ");
                scanf(" %[^\n]%*c", ho_ten);
                printf("Nhap so dien thoai benh nhan: ");
                scanf(" %[^\n]%*c", SDT);
                printf("Nhap ngay sinh benh nhan (dd/mm/yyyy): ");
                scanf(" %[^\n]%*c", ngay_sinh);
                printf("Nhap gioi tinh benh nhan: ");
                scanf(" %[^\n]%*c", gioi_tinh);
                printf("Nhap CCCD benh nhan: ");
                scanf(" %[^\n]%*c", CCCD);
                them_benh_an_vao_dau(bac_si_tim_duoc, ID_benh_an, ngay_kham, ten_benh_an, ID_benh_nhan, ho_ten, SDT, ngay_sinh, gioi_tinh, CCCD);
                break;
            }
            case 4: {
                int ID_benh_an, ID_thuoc;
                char ten_thuoc[50];
                double gia_thuoc;
                printf("Nhap ID benh an: ");
                scanf("%d", &ID_benh_an);
                printf("Nhap ID thuoc: ");
                scanf("%d", &ID_thuoc);
                printf("Nhap ten thuoc: ");
                scanf(" %[^\n]%*c", ten_thuoc);
                printf("Nhap gia thuoc: ");
                scanf("%lf", &gia_thuoc);
                them_thuoc_vao_dau(*head_khoa, ID_benh_an, ID_thuoc, ten_thuoc, gia_thuoc);
                break;
            }
            case 5:
                display(*head_khoa);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break;
        }
    } while (choice != 6);
}

int main() {
    khoa* head_khoa = NULL; // Khoi tao danh sach khoa ban dau
    menu(&head_khoa); // Goi menu de dieu khien he thong
    return 0;
}

