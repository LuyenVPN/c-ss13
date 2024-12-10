#include<stdio.h>

void display(int a, int b) { 
    while (b != 0) {
       int  temp = a % b;  
        a = b;
        b = temp;
    }
    printf("UCLN cua hai so la: %d\n", a);
}
int main() {
    int m, n;
    printf("Nhap so thu nhat: ");
    scanf("%d", &m);
    printf("Nhap so hai: ");
    scanf("%d", &n);
    display(m, n);

    return 0;
}

