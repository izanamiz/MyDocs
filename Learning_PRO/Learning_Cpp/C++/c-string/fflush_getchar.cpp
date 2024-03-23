#include<stdio.h>
int main(){
	int age;char name[20];
	scanf("%d",&age);
// k nhap duoc name 
// do truoc khi nhap chuoi ban co nhap vao 1 bien so nao do
// dieu do khien bo nho dem con luu lai ky tu \n	
//su ket hop giua scanf va gets()
	getchar();// doc ky tu '\n'
	fgets(name,sizeof name,stdin);//read string
/*
	Neu dung gets():
	fflush(stdin);//doc ki tu '\n'
	gets(name);
*/	
	printf("%s - %d",name,age);

}
