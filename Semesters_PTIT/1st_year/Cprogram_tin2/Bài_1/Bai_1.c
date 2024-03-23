#include<stdio.h>
//khai bao public
#define PI 3.1416 //dinh nghia hang

float max=10.0;
float chuvitron(float bankinh)//cai chua biet xac dinh tu cai da biet
{
/*khai bao ham: 
<kieu_du_lieu_tra_ve> <ten_ham>(<cac_tham_so_cua_ham>)
{			
	noi_dung_ham;
}								*/
	float cv;
	cv=PI*2.0*bankinh;
	return cv;
}
int main(){
	float bk,cv;
	scanf("%f",&bk);
	cv=chuvitron(bk);
	printf("%f",cv);
	
	max=max+10;
	printf("\nmax=%f",max);
}
