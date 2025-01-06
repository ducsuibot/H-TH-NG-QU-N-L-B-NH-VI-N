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
