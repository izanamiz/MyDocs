#include<stdio.h>
#include<math.h>

int main()
{
	// 7 && 1 = 1 (dung & dung = dung)
	// 7 && 0 = 0
	int i = 5,j,k=5;
	j = (i++) + 10;
	printf(" j = %d \n i = %d \n", j ,i);
	j=(++k) + 10;
	printf(" j = %d \n i = %d \n", j ,k);
}
