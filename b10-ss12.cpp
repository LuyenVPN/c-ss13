#include<stdio.h>

void hienThiMenu(){
    printf("---MENU---\n");
    printf("1. Nhap so phan tu va gia tri cac phan tu \n");
    printf("2. In ra gia tri cac phan tu \n");
    printf("3. Them 1 phan tu vao vi tri chi dinh \n");
    printf("4. Xoa 1 phan tu o vi tri chi dinh \n");
    printf("5. Sua 1 phan tu o vi tri chi dinh \n");
    printf("6. Sap xep cac phan tu \n");
    printf("   a. Giam dan \n");
    printf("   b. Tang dan \n");
    printf("7. Tim kiem phan tu nhap vao \n");
    printf("   a. Tim kiem tuyen tinh \n");
    printf("   b. Tim kiem nhi phan \n");
    printf("8. Thoat \n");
    printf("Nhap lua chon: ");
}

void nhapMang(int mang[100], int n){
    if(n < 0 || n > 100){
        printf("Vui long nhap lai so phan tu mang.\n");
        return;
    }
    for(int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
    printf("Nhap thanh cong.\n");
}

void hienThiMang(int mang[100], int n){
    printf("Mang hien tai: ");
    for(int i = 0; i < n; i++){
        printf("%d \t", mang[i]);
    }
    printf("\n");
}

void themPhanTu(int mang[100], int giaTriThem, int viTriThem, int *n){
    for(int i = *n; i > viTriThem; i--){
        mang[i] = mang[i - 1];
    }
    mang[viTriThem] = giaTriThem;
    (*n)++;
    hienThiMang(mang, *n);
}

void xoaPhanTu(int mang[100], int viTriXoa, int *n){
    for(int i = viTriXoa; i < *n - 1; i++){
        mang[i] = mang[i + 1];
    }
    (*n)--;
    hienThiMang(mang, *n);
}

void suaPhanTu(int mang[100], int viTriSua, int giaTriSua, int n){
    mang[viTriSua] = giaTriSua;
    hienThiMang(mang, n);
}

int main(){
    int mang[100];
    int soPhanTu;
    int luaChon;

    do{
        hienThiMenu();
        scanf("%d", &luaChon);
        switch(luaChon){
            case 1: {
                printf("Nhap so phan tu: ");
                scanf("%d", &soPhanTu);
                nhapMang(mang, soPhanTu);
                break;
            }
            case 2: {
                hienThiMang(mang, soPhanTu);
                break;
            }
            case 3: {
                int giaTriThem, viTriThem;
                printf("Nhap gia tri muon them: ");
                scanf("%d", &giaTriThem);
                printf("Nhap vi tri muon them (0 den %d): ", soPhanTu);
                scanf("%d", &viTriThem);
                if(viTriThem < 0 || viTriThem > soPhanTu){
                    printf("Vi tri khong hop le.\n");
                } else {
                    themPhanTu(mang, giaTriThem, viTriThem, &soPhanTu);
                }
                break;
            }
            case 4: {
                int viTriXoa;
                printf("Nhap vi tri muon xoa (0 den %d): ", soPhanTu - 1);
                scanf("%d", &viTriXoa);
                if(viTriXoa < 0 || viTriXoa >= soPhanTu){
                    printf("Vi tri khong hop le.\n");
                } else {
                    xoaPhanTu(mang, viTriXoa, &soPhanTu);
                }
                break;
            }
            case 5: {
                int viTriSua, giaTriSua;
                printf("Nhap vi tri muon sua (0 den %d): ", soPhanTu - 1);
                scanf("%d", &viTriSua);
                if(viTriSua < 0 || viTriSua >= soPhanTu){
                    printf("Vi tri khong hop le.\n");
                } else {
                    printf("Nhap gia tri moi: ");
                    scanf("%d", &giaTriSua);
                    suaPhanTu(mang, viTriSua, giaTriSua, soPhanTu);
                }
                break;
            }
            case 6: {
                printf("Chuc nang sap xep chua duoc trien khai.\n");
                break;
            }
            case 7: {
                printf("Chuc nang tim kiem chua duoc trien khai.\n");
                break;
            }
            case 8: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le.\n");
                break;
            }
        }
    } while(luaChon != 8);

    return 0;
}

