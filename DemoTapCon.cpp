#include <stdio.h> 
#include <conio.h> 
#define TRUE 1 
#define FALSE 0 
#define MAX 100 
int n, k, count, C[MAX], Stop;
void Init(){
 	int i;
 	//printf("\n Nhap n="); scanf("%d", &n);
 	//printf("\n Nhap k="); scanf("%d", &k);
 	for (i = 1; i <= k; i++){
 		C[i] = i;	
	}
  		
}
void Result(){
 	int i; count++;
 	printf("\n Tap con thu %d:", count);
 	for (i = 1; i <= k; i++){
 		printf("%3d", C[i]);
	}
 	
}
void Next_Combination(){
 	int i, j;
 	i = k;
 	while (i > 0 && C[i] == n - k + i)
  	i--;
 	if (i > 0) {
  		C[i] = C[i] + 1;
  		for (j = i + 1; j <= k; j++){
  			C[j] = C[i] + j - i;	
		}
   		
 	}
 	else Stop = TRUE;
}
void Combination(void){
 	Stop = FALSE;
	while (Stop == FALSE){
  		Result();
		Next_Combination();
 	}
}
int main(){
	printf("\n Nhap n="); scanf("%d", &n);
	int m;
	for(m=1; m<=n;m++){
		k=m;
		printf("\n");
		printf("\n Cac chuoi co %d phan tu la:",m);
		Init();
 		Combination();
 		//Result();
		//Next_Combination();
	}
 	getch();
 	return 0;
 	
}
