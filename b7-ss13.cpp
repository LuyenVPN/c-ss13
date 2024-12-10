#include<stdio.h>
void display(int m, int n, int a[100][100]);
void trakq(int m, int n, int a[100][100]); 
int main(){
	int m,n;
	printf("nhap so cot: ");
	scanf("%d",&m);
	printf("nhap so hang: ");
	scanf("%d",&n);
	int a[100][100];
	display(m,n,a); 
	trakq(m,n,a); 
	return 0; 
} 

void display(int m, int n, int a[100][100]){
	for (int i=0; i<m; i++){
		for (int j=0; j<n ; j++){
			printf("a[%d][%d]= ", i,j);
			scanf("%d",&a[i][j]); 
		} 
	} 
} 

void trakq(int m, int n, int a[100][100]){
	printf("cac phan tu cua mang la: \n");
	for (int i=0; i<m; i++){
		for (int j=0;j<n;j++){
			printf("%d \t", a[i][j]); 
		} printf("\n") ;
	} 
} 
