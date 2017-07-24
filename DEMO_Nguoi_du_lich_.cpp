#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define int_MAX 9999
#define MAX 20

int cost[MAX][MAX], routine[MAX], bestWay[MAX];
int min_cost_0 = 0, sum_cost = 0, max_cost = int_MAX, cities, min_cost;
bool mark[MAX];

// Ghi nhan hanh trinh
void Record(){
	min_cost = sum_cost + cost[routine[cities-1]][0];
	if(min_cost < max_cost){
		max_cost = min_cost;
		for(int i = 0; i<cities; i++){
			bestWay[i] = routine[i];
		}
	}
}

//Giai thuat quy lui tim duong di tot nhat
void Try(int i){
	for(int j=1; j<cities; j++){
		if(!mark[j]){
			routine[i] = j;
			mark[j] = true;
			sum_cost += cost[routine[i-1]][routine[i]];
			
			if(i == cities -1) Record();
			else if((sum_cost + min_cost_0*(cities-i+1)) < max_cost) Try(i+1);
			
			sum_cost -= cost[routine[i-1]][routine[i]];
			mark[j] = false;
		}
	}
}

//In ket qua
void print_Result(){
	printf("\n Ma tran chi phi la: \n");
	for(int i=0; i<cities; i++){
		for(int j=0; j<cities; j++){
			printf("%4d", cost[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Hanh trinh toi uu la : \n");
	
	for(int i=0; i<cities; i++){
		printf("%d -> ", bestWay[i]);
	}
	
	printf("0\n");
	printf("Tong chi phi la: %d", max_cost);
}

//Input
void inIt(){
	int temp;
	
	printf("\nNhap so thanh pho: ");
	scanf("%d", &cities);
	//cities = 5;
	//cost[5][5]={{0,15,30,50,20}, {15,0,10,35,32}, {30,10,0,15,40}, {50,35,15,0,43}, {20,32,40,43,0}};
	for (int i=0; i<cities; i++){
		for (int j=0; j<cities; j++){
			if(i == j) cost[i][j] = 0;
			else{
				printf("Nhap cost[%d][%d]= ",i,j);
				scanf("%d", &cost[i][j]);
			}
		}
	}
	
	for(int i=0; i<cities; i++){
		mark[i] = false;
		for(int j = 0; j<cities; j++){
			temp = cost[i][j];
			if(min_cost_0 > temp) min_cost_0 = temp;
		}
	}
	
	routine[0] = 0;
}

//Chuong trinh chinh
int main()	{   
	inIt();	
	Try(1);
	print_Result();
	return 0;
}













	
