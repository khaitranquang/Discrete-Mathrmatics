#include <stdio.h>
#include <conio.h>
#define n 5
//int n = 5;
int hau[n];
char cot[n],cheo1[2*n-1],cheo2[2*n-1];
int dem;
 
void InKq()
{
    int i,j;
 
    printf("Phuong an %d:\n", ++dem);   
    for (i=0; i<n; i++)
    {
        for (j=0; j<hau[i]; j++) printf(" .");
        printf(" x");
        for (j=hau[i]+1; j<n; j++) printf(" .");
        printf("\n");
    }
    printf("\n");
}
 
void Try(int i)
{
    for (int j=0; j<n; j++)
        if (cot[j] && cheo1[i+j] && cheo2[j-i+n])
        {
            hau[i] = j;
 
            cot[j] = 0;
            cheo1[i+j] = 0;
            cheo2[j-i+n] = 0;
             
            if (i==n-1) InKq();
            else Try(i+1);
 
            cot[j] = 1;
            cheo1[i+j] = 1;
            cheo2[j-i+n] = 1;           
        }
}
 
int main()
{
    int i;
    /*do{
    	printf("\n Nhap m= ");
    	scanf("%d", &m);
	} while(m<=0);*/
    
    /*for (i=0; i<m; i++) {
        cot[i]  = 1;
    }
    for (i=0; i<2*m; i++) {
        cheo1[i] = 1;
        cheo2[i] = 1;
    }*/
   
    for (i=0; i<n; i++) {
        cot[i]  = 1;
    }
    for (i=0; i<2*n; i++) {
        cheo1[i] = 1;
        cheo2[i] = 1;
    }
    dem = 0;
 
    Try(0);
 
    getch();
    return 0;
}
