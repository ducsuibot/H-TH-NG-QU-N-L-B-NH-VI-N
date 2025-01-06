//====================================== CAC HAM SAP XEP THONG TIN TRONG HE THONG =================================================//

//----------- HAM SAP XEP TRONG DSLK KHOA(theo ten khoa) -------------// 
void swap_khoa(khoa* a, khoa* b) {
    // Hoan doi ten khoa
    char temp_ten_khoa[50];
    strcpy(temp_ten_khoa, a->ten_khoa);
    strcpy(a->ten_khoa, b->ten_khoa);
    strcpy(b->ten_khoa, temp_ten_khoa);

    // Hoan doi danh sach bac si
    bac_si* temp_danh_sach_bac_si = a->danh_sach_bac_si;
    a->danh_sach_bac_si = b->danh_sach_bac_si;
    b->danh_sach_bac_si = temp_danh_sach_bac_si;
}
khoa* partition(khoa* low, khoa* high) {
    char pivot = high->ten_khoa[0]; // Lay chu cai dau cua khoa cuoi lam pivot
    khoa* i = low->prev; // Node nam truoc node low

    // Duyet qua cac phan tu tu low den truoc high
    for (khoa* j = low; j != high; j = j->next) {
        if (j->ten_khoa[0] < pivot) { // Neu chu cai dau nho hon pivot
            if (i == NULL) {
                i = low; // Khoi tao i neu ban dau i NULL
            } else {
                i = i->next; // Di chuyen i den node ke tiep
            }
            swap_khoa(i, j); // Hoan doi i va j
        }
    }

    // Dua pivot ve dung vi tri
    if (i == NULL) {
        i = low; // Khoi tao i neu ban dau i NULL
    } else {
        i = i->next; // Di chuyen i den node ke tiep
    }
    swap_khoa(i, high);
    return i; // Tra ve vi tri cua pivot
}
void quicksort_khoa(khoa* low, khoa* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        // Phan vung danh sach quanh pivot
        khoa* pivot = partition(low, high);

        // De quy sap xep phan truoc va sau pivot
        quicksort_khoa(low, pivot->prev);
        quicksort_khoa(pivot->next, high);
    }
}
void quicksort_dslk_khoa(khoa* head) {
    // Kiem tra danh sach rong
    if (head == NULL) {
        printf("Danh sach khoa trong!\n");
        return;
    }

    // Tim node cuoi cung
    khoa* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Goi ham Quicksort
    quicksort_khoa(head, tail);
    printf("Sap xep danh sach khoa theo ten thanh cong!\n");
}

//----------- HAM SAP XEP TRONG DSLK BAC SI (theo ten bac si) -------------//   
void swap_bac_si(bac_si* a, bac_si* b) {
    char temp_ho_ten[50];
    char temp_SDT[15];
    char temp_gmail[50];
    int temp_ID;

    // Hoan doi ten
    strcpy(temp_ho_ten, a->ho_ten);
    strcpy(a->ho_ten, b->ho_ten);
    strcpy(b->ho_ten, temp_ho_ten);

    // Hoan doi so dien thoai
    strcpy(temp_SDT, a->SDT);
    strcpy(a->SDT, b->SDT);
    strcpy(b->SDT, temp_SDT);

    // Hoan doi email
    strcpy(temp_gmail, a->gmail);
    strcpy(a->gmail, b->gmail);
    strcpy(b->gmail, temp_gmail);

    // Hoan doi ID
    temp_ID = a->ID_bac_si;
    a->ID_bac_si = b->ID_bac_si;
    b->ID_bac_si = temp_ID;
} 
bac_si* partition_bac_si(bac_si* low, bac_si* high) {
    char pivot[50];
    strcpy(pivot, low->ho_ten); // Lay ho ten cua bac si dau lam pivot

    bac_si* i = low; // Vi tri phan tu nho hon pivot
    bac_si* j = low->next;

    while (j != NULL && j != high->next) {
        if (strcmp(j->ho_ten, pivot) < 0) { // So sanh ten bac si
            i = i->next; // Di chuyen vi tri i
            swap_bac_si(i, j); // Hoan doi voi phan tu nho hon pivot
        }
        j = j->next; // Duyet sang phan tu tiep theo
    }

    // Hoan doi pivot voi phan tu duoc danh dau boi i
    swap_bac_si(low, i);
    return i; // Tra ve vi tri cua pivot
}
void quicksort_bac_si(bac_si* low, bac_si* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        bac_si* pivot = partition_bac_si(low, high);

        quicksort_bac_si(low, pivot->prev);  // Sap xep phan truoc pivot
        quicksort_bac_si(pivot->next, high); // Sap xep phan sau pivot
    }
}
void sap_xep_bac_si_theo_ten(bac_si* head) {
    if (head == NULL) {
        printf("Danh sach bac si rong!\n");
        return;
    }

    // Tim bac si cuoi trong danh sach
    bac_si* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Goi ham Quick Sort
    quicksort_bac_si(head, tail);

    printf("Danh sach bac si da duoc sap xep theo ten!\n");
}

//----------- HAM SAP XEP TRONG DSLK BENH AN (theo ten benh nhan) -------------//   
void swap_benh_an(benh_an* a, benh_an* b) {
    // Hoan doi ID benh an
    int temp_id = a->ID_benh_an;
    a->ID_benh_an = b->ID_benh_an;
    b->ID_benh_an = temp_id;

    // Hoan doi ngay kham
    char temp_ngay_kham[11];
    strcpy(temp_ngay_kham, a->ngay_kham);
    strcpy(a->ngay_kham, b->ngay_kham);
    strcpy(b->ngay_kham, temp_ngay_kham);

    // Hoan doi ten benh an
    char temp_ten_benh_an[50];
    strcpy(temp_ten_benh_an, a->ten_benh_an);
    strcpy(a->ten_benh_an, b->ten_benh_an);
    strcpy(b->ten_benh_an, temp_ten_benh_an);

    // Hoan doi thong tin benh nhan
    benh_nhan temp_benh_nhan = a->benh_nhan;
    a->benh_nhan = b->benh_nhan;
    b->benh_nhan = temp_benh_nhan;

    // Hoan doi danh sach thuoc
    thuoc* temp_danh_sach_thuoc = a->danh_sach_thuoc;
    a->danh_sach_thuoc = b->danh_sach_thuoc;
    b->danh_sach_thuoc = temp_danh_sach_thuoc;
}
benh_an* partition_benh_an(benh_an* low, benh_an* high) {
    char pivot[50];
    strcpy(pivot, low->benh_nhan.ho_ten); // Chon ten benh nhan cua benh an dau lam pivot
    benh_an* left = low->next;
    benh_an* right = high;

    while (left != right->next) {
        // Di chuyen left den khi tim thay phan tu lon hon hoac bang pivot
        while (left != NULL && strcmp(left->benh_nhan.ho_ten, pivot) < 0) {
            left = left->next;
        }

        // Di chuyen right den khi tim thay phan tu nho hon hoac bang pivot
        while (right != NULL && strcmp(right->benh_nhan.ho_ten, pivot) > 0) {
            right = right->prev;
        }

        // Neu left va right khong vuot qua nhau, hoan doi va tiep tuc
        if (left != NULL && right != NULL && left != right->next) {
            swap_benh_an(left, right);
            left = left->next;
            right = right->prev;
        }
    }

    // Hoan doi pivot voi right
    swap_benh_an(low, right);

    // Tra ve vi tri cua pivot
    return right;
}
void quicksort_benh_an(benh_an* low, benh_an* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        // Phan vung danh sach quanh pivot
        benh_an* pivot = partition_benh_an(low, high);

        // De quy sap xep phan truoc pivot
        quicksort_benh_an(low, pivot->prev);

        // De quy sap xep phan sau pivot
        quicksort_benh_an(pivot->next, high);
    }
}
void sap_xep_danh_sach_benh_an(benh_an* head) {
    if (head == NULL) {
        printf("Danh sach benh an trong!\n");
        return;
    }

    // Tim node cuoi danh sach
    benh_an* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Goi ham QuickSort
    quicksort_benh_an(head, tail);

    printf("Sap xep danh sach benh an theo ten benh nhan thanh cong!\n");
}
