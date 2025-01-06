//============================================ MENU DIEU KHIEN HE THONG =======================================================//

void menu(khoa** head_khoa) {
    int choice;
    do {
        printf("\n                |========== HE THONG QUAN LY BENH VIEN ==========|\n");  
        
        printf("\n   CAC HAM THEM: \n"); 
        printf("1. Them khoa vao dau\n"); 
        printf("2. Them khoa vao cuoi\n");
        printf("3. Them bac si vao dau DSLK bac_si cua khoa\n"); 
        printf("4. Them bac si vao cuoi DSLK bac_si cua khoa\n");
        printf("5. Them benh an cho vao dau DSLK benh_an cua bac si\n"); 
        printf("6. Them benh an cho vao cuoi DSLK benh_an cua bac si\n");
        printf("7. Them thuoc vao dau DSLK thuoc cua benh an\n"); 
        printf("8. Them thuoc vao cuoi DSLK thuoc cua benh an\n");   

        printf("    CAC HAM XOA: \n");  
		printf("9.  Xoa khoa o dau trong DSLK khoa\n"); 
		printf("10. Xoa khoa o cuoi trong DSLK khoa\n");  
		printf("11. Xoa khoa theo ten trong DSLK khoa\n");  
		
		printf("12. Xoa bac si o dau DSLK bac_si trong 1 khoa\n"); 
		printf("13. Xoa bac si o cuoi DSLK bac_si trong 1 khoa\n");  
		printf("14. Xoa bac si theo ID trong DSLK bac_si trong 1 khoa\n");  
		 
		printf("15. Xoa benh an o dau DSLK benh_an trong 1 bac si\n"); 
		printf("16. Xoa benh an o cuoi DSLK benh_an trong 1 bac si\n"); 
        printf("17. Xoa benh an theo ID trong DSLK benh_an trong 1 bac si\n");  
        printf("    CAC HAM SAP XEP: \n"); 
        printf("18. Sap xep DSLK Khoa (theo ten khoa)\n"); 
        printf("19. Sap xep DSLK Bac si (theo ten bac si)\n");  
        printf("20. Sap xep DSLK Benh an (theo ten benh nhan)\n"); 
        printf("    CAC HAM HIEN THI: \n"); 
        printf("21. Hien thi thong tin he thong\n"); 
        printf("22. In thong tin he thong vao file quanlybenhvien.txt\n"); 
        printf("23. Thoat\n");
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
                char ten_khoa[50];
                printf("Nhap ten khoa: ");
                scanf(" %[^\n]%*c", ten_khoa); // Dung scanf de nhap xau co khoang trang
                them_Khoa_vao_cuoi_DSLK(head_khoa, ten_khoa);
                break;
            }
            case 3: {
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
            case 4: {
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
                them_bac_si_vao_cuoi(*head_khoa, ten_khoa, ID_bac_si, ho_ten, SDT, gmail);
                break;
            }
            case 5: {
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
            case 6: {
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
                them_benh_an_vao_cuoi(bac_si_tim_duoc, ID_benh_an, ngay_kham, ten_benh_an, ID_benh_nhan, ho_ten, SDT, ngay_sinh, gioi_tinh, CCCD);
                break;
            }
            case 7: {
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
            case 8: {
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
                them_thuoc_vao_cuoi(*head_khoa, ID_benh_an, ID_thuoc, ten_thuoc, gia_thuoc);
                break;
            } 
            case 9: { 
            	xoa_khoa_dau(head_khoa);
				break;
			} 
			case 10: { 
				xoa_khoa_cuoi(head_khoa);
				break;
			} 
			case 11: {  
				char ten_khoa[50];
                printf("Nhap ten khoa: ");
                scanf(" %[^\n]%*c", ten_khoa);
				xoa_khoa_theo_ten(head_khoa,ten_khoa);
				break;
			} 
			case 12: {  
				char ten_khoa[50];
                printf("Nhap ten khoa: ");
                scanf(" %[^\n]%*c", ten_khoa);
				xoa_bac_si_dau(*head_khoa,ten_khoa);
				break;
			} 
			case 13: {  
				char ten_khoa[50];
                printf("Nhap ten khoa: ");
                scanf(" %[^\n]%*c", ten_khoa);
				xoa_bac_si_cuoi(*head_khoa,ten_khoa);
				break;
			} 
			case 14: { 
				int ID; 
				printf("Nhap ID bac_si can xoa: "); 
				scanf("%d",&ID); 
				xoa_bac_si_theo_ID(*head_khoa,ID);
				break;
			} 
			case 15: {  
				int ID; 
				printf("Nhap ID bac_si: "); 
				scanf("%d",&ID);
				xoa_benh_an_dau(*head_khoa,ID);
				break;
			} 
			case 16: {  
				int ID; 
				printf("Nhap ID bac_si: "); 
				scanf("%d",&ID);
				xoa_benh_an_cuoi(*head_khoa,ID);
				break;
			} 
			case 17: { 
				int ID_bac_si,ID_benh_an; 
				printf("Nhap ID bac_si: ");  
				scanf("%d",&ID_bac_si);
				printf("Nhap ID benh_an: ");  
				scanf("%d",&ID_benh_an); 
				xoa_benh_an_theo_ID(*head_khoa,ID_bac_si,ID_benh_an);
				break;
			} 
			case 18: { 
				quicksort_dslk_khoa(*head_khoa);
				break;
			} 
			case 19: { 
				sap_xep_bac_si_theo_ten((*head_khoa)->danh_sach_bac_si);
				break;
			} 
			case 20: {  
				int ID_bac_si; 
				printf("Nhap ID bac_si: ");  
				scanf("%d",&ID_bac_si); 
				bac_si* temp= tim_bac_si_theo_ID(*head_khoa, ID_bac_si);
				sap_xep_danh_sach_benh_an(temp->danh_sach_benh_an);
				break;
			}
            case 21:
                display(*head_khoa);
                break; 
            case 22: 
            	display_to_file(*head_khoa,"quanlybenhvien.txt");
            case 23:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break; 
        }
    } while (choice != 6);
}
