#include<stdio.h>
#include<math.h>

void hienThiMenu(){
    printf("\n--- Menu---\n");
    printf("1. Nhap gia tri cac phan tu cua ma tran \n");
    printf("2. In ra cac phan tu cua ma tran theo ma tran \n");
    printf("3. In ra cac phan tu o goc theo ma tran \n");
    printf("4. In ra cac phan tu nam tren duong bien theo ma tran \n");
    printf("5. In ra cac phan tu nam tren duong cheo phu va duong cheo chinh theo ma tran \n");
    printf("6. In ra cac phan tu la so nguyen to theo ma tran \n");
    printf("Nhap vao lua chon : ");
}

void nhapMaTran(int mang[100][100], int hang, int cot){
    for(int i = 0; i < hang; i++){
        for(int j = 0; j < cot; j++){
            printf("Nhap phan tu [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mang[i][j]);
        }
    }
    printf("Nhap thanh cong.\n");
}

void hienThiMaTran(int mang[100][100], int hang, int cot){
    for(int i = 0; i < hang; i++){
        for(int j = 0; j < cot; j++){
            printf("%d ", mang[i][j]);
        }
        printf("\n");
    }
}

void inDuongBien(int mang[100][100], int hang, int cot){
    for(int i = 0; i < hang; i++){
        for(int j = 0; j < cot; j++){
            if (i == 0 || i == hang - 1 || j == 0 || j == cot - 1){
                printf("%d ", mang[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void inDuongCheo(int mang[100][100], int hang, int cot){
    if (hang != cot){
        printf("Khong phai ma tran vuong, khong the in duong cheo.\n");
        return;
    }
    printf("Duong cheo chinh: ");
    for (int i = 0; i < hang; i++){
        printf("%d ", mang[i][i]);
    }
    printf("\nDuong cheo phu: ");
    for (int i = 0; i < hang; i++){
        printf("%d ", mang[i][hang - 1 - i]);
    }
    printf("\n");
}

int laSoNguyenTo(int n){
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

void inSoNguyenTo(int mang[100][100], int hang, int cot){
    printf("Cac so nguyen to trong ma tran: ");
    for (int i = 0; i < hang; i++){
        for (int j = 0; j < cot; j++){
            if (laSoNguyenTo(mang[i][j])){
                printf("%d ", mang[i][j]);
            }
        }
    }
    printf("\n");
}

int main(){
    int cot, hang;
    int mang[100][100];
    int luaChon;
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        switch(luaChon){
            case 1: {
                printf("Nhap so hang cua ma tran: ");
                scanf("%d", &cot);
                printf("Nhap so cot cua ma tran: ");
                scanf("%d", &hang);
                nhapMaTran(mang, hang, cot);
                break;
            }
            case 2: {
                hienThiMaTran(mang, hang, cot);
                break;
            }
            case 3: {
                break; 
            }
            case 4: {
                inDuongBien(mang, hang, cot);
                break;
            }
            case 5: {
                inDuongCheo(mang, hang, cot);
                break;
            }
            case 6: {
                inSoNguyenTo(mang, hang, cot);
                break;
            }
            default: {
                printf("Lua chon khong hop le.\n");
                break;
            }
        }
    } while(luaChon != 6);
    return 0;
}

