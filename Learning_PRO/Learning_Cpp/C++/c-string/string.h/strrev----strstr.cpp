#include<stdio.h>
#include<string.h>
int main(){
	char name[]="Dong A Van Anh";

//ham tim chuoi con trong chuoi
// tim kiem su xuat hien cua chuoi con sub trong chuoi str
// neu tim k thay thi tra ve con tro NULL
//neu tim thay thi tra ve con tro toi vi tri tim thay
	char *first;
	first= strstr(name,"An");
	if(first!=NULL)	{
		printf("Vi tri xuat hien dau tien cua \"An\" trong \"%s\" la \"%s\"",
			name,first);
	}else printf("Khong tim thay! \n");

	printf("\nTruoc khi dao nguoc: %s\n ",name);
	printf("Sau khi dao nguoc: %s\n",strrev(name));
}
