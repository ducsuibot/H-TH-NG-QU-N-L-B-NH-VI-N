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

    // Truong hop chi co mot khoa
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
    // Su dung ham tim_khoa theo ten
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
        khoa_tim_duoc->prev->next = NULL;  // Cap nhat next cua phan tu truoc do
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
    // Tim khoa theo ten
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
    // Tim khoa theo ten
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

        // Duyet qua cac b?c si trong khoa hien tai
        while (bac_si_duyet != NULL) {
            if (bac_si_duyet->ID_bac_si == ID_bac_si) {
                // Giai phong bo nho cho danh sach benh ?n
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
                    };
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
            bac_si_duyet = bac_si_duyet->next; // Duyet tiep bac si ke tiep trong danh s?ch
        }
        khoa_duyet = khoa_duyet->next; // Duyet tiep khoa ke tiep
    }
    printf("Khong tim thay bac si voi ID %d!\n", ID_bac_si); 
}


//----------- HAM XOA TRONG DSLK BENH_AN -------------// 
 
void xoa_benh_an_dau(khoa* danh_sach_khoa, int ID_bac_si) {
    bac_si* bac_si_tim_duoc = tim_bac_si_theo_ID(danh_sach_khoa, ID_bac_si);

    if (bac_si_tim_duoc == NULL) {
        printf("Khong tim thay bac si voi ID %d!\n", ID_bac_si);
        return;
    }

    if (bac_si_tim_duoc->danh_sach_benh_an == NULL) {
        printf("Danh sach benh an cua bac si ID %d trong!\n", ID_bac_si);
        return;
    }

    // Luu con tro dau tien cua danh sach benh an
    benh_an* temp = bac_si_tim_duoc->danh_sach_benh_an;
    bac_si_tim_duoc->danh_sach_benh_an = temp->next;

    // Neu con benh an sau do, cap nhat con tro `prev`
    if (bac_si_tim_duoc->danh_sach_benh_an != NULL) {
        bac_si_tim_duoc->danh_sach_benh_an->prev = NULL;
    }

    free(temp); // Giai phong bo nho cua benh an dau tien
    printf("Xoa benh an dau cua bac si ID %d thanh cong!\n", ID_bac_si);
}

void xoa_benh_an_cuoi(khoa* danh_sach_khoa, int ID_bac_si) {
    bac_si* bac_si_tim_duoc = tim_bac_si_theo_ID(danh_sach_khoa, ID_bac_si);

    if (bac_si_tim_duoc == NULL) {
        printf("Khong tim thay bac si voi ID %d!\n", ID_bac_si);
        return;
    }

    if (bac_si_tim_duoc->danh_sach_benh_an == NULL) {
        printf("Danh sach benh an cua bac si ID %d trong!\n", ID_bac_si);
        return;
    }

    // Tim benh an cuoi
    benh_an* temp = bac_si_tim_duoc->danh_sach_benh_an;
    while (temp->next != NULL) {
        temp = temp->next; // Duyet den phan tu cuoi
    }

    // Cap nhat con tro cua benh an truoc do (neu co)
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        // Neu chi co mot benh an
        bac_si_tim_duoc->danh_sach_benh_an = NULL;
    }

    free(temp); // Giai phong bo nho cua benh an cuoi
    printf("Xoa benh an cuoi cua bac si ID %d thanh cong!\n", ID_bac_si);
}

void xoa_benh_an_theo_ID(khoa* danh_sach_khoa, int ID_bac_si, int ID_benh_an) {
    // Tim bac si dua theo ID bac si
    bac_si* bac_si_tim_duoc = tim_bac_si_theo_ID(danh_sach_khoa, ID_bac_si);

    if (bac_si_tim_duoc == NULL) {
        printf("Khong tim thay bac si voi ID %d!\n", ID_bac_si);
        return;
    }

    // Tim danh sach benh an cua bac si do
    benh_an* temp = bac_si_tim_duoc->danh_sach_benh_an;

    if (temp == NULL) {
        printf("Danh sach benh an cua bac si ID %d trong!\n", ID_bac_si);
        return;
    }

    // Duyet qua danh sach benh an de tim benh an can xoa
    while (temp != NULL) {
        if (temp->ID_benh_an == ID_benh_an) {
            // Xu ly neu benh an la phan tu dau tien
            if (temp->prev == NULL) {
                bac_si_tim_duoc->danh_sach_benh_an = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = NULL;
                }
            } 
            // Xu ly neu benh an la phan tu cuoi cung
            else if (temp->next == NULL) {
                temp->prev->next = NULL;
            } 
            // Xu ly neu benh an nam giua
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            free(temp); // Giai phong bo nho benh an
            printf("Xoa benh an ID %d cua bac si ID %d thanh cong!\n", ID_benh_an, ID_bac_si);
            return;
        }

        temp = temp->next; // Duyet sang benh an tiep theo
    }

    // Neu khong tim thay benh an voi ID_benh_an
    printf("Khong tim thay benh an voi ID %d cua bac si ID %d!\n", ID_benh_an, ID_bac_si);
}

