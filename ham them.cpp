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
  
void them_Khoa_vao_cuoi_DSLK(khoa** Head, char ten_khoa[50]) {
    // Cap phat bo nho cho khoa moi
    khoa* new_khoa = (khoa*)malloc(sizeof(khoa));
    if (new_khoa == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        return;
    }

    // Khoi tao gia tri cho khoa moi
    strcpy(new_khoa->ten_khoa, ten_khoa);
    new_khoa->danh_sach_bac_si = NULL; // Ban dau khong co bac si nen la NULL
    new_khoa->next = NULL;             // Khoa moi se la phan tu cuoi n?n next = NULL

    // Neu danh sach rong, khoa moi se la phan tu dau tien
    if (*Head == NULL) {
        new_khoa->prev = NULL;         // Khong co phan tu truoc do
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
        // Duyet den phan tu cuoi danh s?ch
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


