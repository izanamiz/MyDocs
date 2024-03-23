#include<stdio.h>
#include<string.h>
int main(){
	char key[]="apple";
	char buffer[80];
// k the dung dau == de so san 2 chuoi
// khi truy xuat ten chuoi thi thuc te dang truy xuat toi dia chi cua no
// chu k phai gia tri
	do{
		printf("Hay nhap loai qua toi thich: ");
		fflush(stdout);
		scanf("%s", buffer);		
	}while(strcmp(key,buffer)!=0);
	puts("Ban doan dung roi!");
}
