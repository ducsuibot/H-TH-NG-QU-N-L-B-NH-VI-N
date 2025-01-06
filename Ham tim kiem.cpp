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
        // Duyet danh_sach_bac_si trong khoa hien tai
        bac_si* temp = danh_sach_khoa->danh_sach_bac_si;
        while (temp != NULL) {
            if (temp->ID_bac_si == ID_bac_si) {
                return temp; // Tro ve con tro den bac si tim thay
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

