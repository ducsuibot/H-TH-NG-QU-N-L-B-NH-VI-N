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
 void display_to_file(khoa* head_khoa, const char* file_name) {
    if (head_khoa == NULL) {
        printf("He thong quan ly benh vien trong!\n");
        return;
    }

    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi thong tin!\n");
        return;
    }

    fprintf(file, "========== DANH SACH CAC KHOA TRONG BENH VIEN ==========\n");
    khoa* temp_khoa = head_khoa;
    while (temp_khoa != NULL) {
        fprintf(file, "\nKhoa: %s\n", temp_khoa->ten_khoa);

        bac_si* temp_bac_si = temp_khoa->danh_sach_bac_si;
        if (temp_bac_si == NULL) {
            fprintf(file, "  Khong co bac si nao trong khoa nay.\n");
        } else {
            fprintf(file, "  Danh sach bac si:\n");
            while (temp_bac_si != NULL) {
                fprintf(file, "    - ID Bac Si: %d\n", temp_bac_si->ID_bac_si);
                fprintf(file, "      Ho Ten   : %s\n", temp_bac_si->ho_ten);
                fprintf(file, "      SDT      : %s\n", temp_bac_si->SDT);
                fprintf(file, "      Gmail    : %s\n", temp_bac_si->gmail);

                benh_an* temp_benh_an = temp_bac_si->danh_sach_benh_an;
                if (temp_benh_an == NULL) {
                    fprintf(file, "      Khong co benh an nao.\n");
                } else {
                    fprintf(file, "      Danh sach benh an:\n");
                    while (temp_benh_an != NULL) {
                        fprintf(file, "        + ID Benh An   : %d\n", temp_benh_an->ID_benh_an);
                        fprintf(file, "          Ngay Kham    : %s\n", temp_benh_an->ngay_kham);
                        fprintf(file, "          Ten Benh An  : %s\n", temp_benh_an->ten_benh_an);
                        fprintf(file, "          Benh Nhan:\n");
                        fprintf(file, "            > ID       : %d\n", temp_benh_an->benh_nhan.ID_benh_nhan);
                        fprintf(file, "            > Ho Ten   : %s\n", temp_benh_an->benh_nhan.ho_ten);
                        fprintf(file, "            > SDT      : %s\n", temp_benh_an->benh_nhan.SDT);
                        fprintf(file, "            > Ngay Sinh: %s\n", temp_benh_an->benh_nhan.ngay_sinh);
                        fprintf(file, "            > Gioi Tinh: %s\n", temp_benh_an->benh_nhan.gioi_tinh);
                        fprintf(file, "            > CCCD     : %s\n", temp_benh_an->benh_nhan.CCCD);

                        thuoc* temp_thuoc = temp_benh_an->danh_sach_thuoc;
                        if (temp_thuoc == NULL) {
                            fprintf(file, "          Khong co thuoc nao.\n");
                        } else {
                            fprintf(file, "          Danh sach thuoc:\n");
                            while (temp_thuoc != NULL) {
                                fprintf(file, "            * ID Thuoc: %d\n", temp_thuoc->ID_thuoc);
                                fprintf(file, "              Ten Thuoc: %c\n", temp_thuoc->ten_thuoc); // Ten thuoc dang 'char'
                                fprintf(file, "              Gia Thuoc: %.2f\n", temp_thuoc->gia_thuoc);
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
    fprintf(file, "\n========================================================\n");

    fclose(file);
    printf("Da ghi thong tin ra file %s thanh cong!\n", file_name);
}
