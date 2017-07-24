//thuat toan nhanh can, tim phuong an toi uu
#include <stdio.h>

const int max=100;
int a[max],c[max],n; //khai bao mang chua khoi luong ai, gia tri ci tuong ung cua cac do vat, va n 
float wv[max];		//Mang luu ti so gia tri/khoi luong
int so_luong;
int khoi_luong;
int khoi_luong_con_lai;
int gia_tri_hien_tai =0;
int khoi_luong_con_lai_gia_su;
int dem=0;
int vat[100];	//khai bao cac mang de ghi nhan
int gt[100];		//cac buoc cua thuat toan
int sl[100];		//nhanh can

void input(){
	printf("Nhap so luong do vat: "); scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("%d\n",i);
		printf("Khoi luong: "); scanf("%d",&a[i]);
		printf("Gia tri: "); scanf("%d",&c[i]);
		wv[i]=(float)c[i]/a[i]; 
	}
}
void swap(float &a, float &b){
	float temp=a;
	a= b;
	b=temp;
}
//sap xep theo thu tu cua v[i]/w[i] tuc la wv[i]
void sort(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++) {
			if(wv[j]>wv[i]){
				swap((float&)a[j],(float&)a[i]);
				swap((float&)c[j],(float&)c[i]);
				swap(wv[j],wv[i]);
			}
			else if(wv[j]==wv[i]){
				if(a[j]<a[i]){
					swap((float&)a[j],(float&)a[i]);
					swap((float&)c[j],(float&)c[i]);
					swap(wv[j],wv[i]);
				}
			}
		}
	}
}
//hien thi 
void display(){
	printf("\nDo vat   Khoiluong    Giatri      Tyso\n");
	for(int i=0;i<n;i++){
		printf("%d  \t  %3d  \t       %3d  \t%5.2f",i,a[i],c[i],wv[i]);
		printf("\n");
	}
}
//thuat toan nhanh can
void nhanh_can(int i){
	so_luong = khoi_luong_con_lai/a[i]; //lay toi da co the phan tu i;
	khoi_luong_con_lai -= so_luong*c[i];
	gia_tri_hien_tai += so_luong * c[i];
	vat[dem] = i; sl[dem] = so_luong;  gt[dem] = c[dem] * sl[dem];
	dem++;
	while(i < n){
		khoi_luong_con_lai_gia_su=khoi_luong_con_lai-a[i+1];
		if(khoi_luong_con_lai_gia_su >=0 ) break;
		i++;
	}
	if(khoi_luong_con_lai > khoi_luong_con_lai_gia_su) //xem con loi nao ko
		nhanh_can(i+1);
	
}
main(){
	printf("\nNhap khoi luong balo: ");
	scanf("%d",&khoi_luong);
	khoi_luong_con_lai = khoi_luong;
	input();
	//display();
	printf("\nSau khi sap xep:\n");
	sort();
	display();
	printf("\nThuat toan nhanh can: \n");
	nhanh_can(0);
	printf("\nDoVat    Soluong     Tonggiatri\n");
	for(int i=0; i<dem; i++){
		printf("%d     \t%d  \t      %d\n",vat[i],sl[i],gt[i]);
	}
	printf("\nKhoi luong con lai: %d", khoi_luong_con_lai);
	printf("\nTong gia tri: %d", gia_tri_hien_tai);
	
	
}
