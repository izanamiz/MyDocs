#include<stdio.h>
void Min2(int a[],int n, int *min1, int *min2)
{
	*min1 = *min2 = a[0];
	for(int j = 1; j < n; j++)
		if(a[j] < *min1)
		{
			*min2 = *min1;
			*min1 = a[j];
		}
		else if(a[j] > *min1)
		{
			if(*min1 == *min2) *min2 = a[j];
			else if(a[j] < *min2) *min2 = a[j];
		}

}
int main()
{
	int a[100] , n, t;
	int min1, min2;
	int i, j;
	FILE *fd = fopen ("input1.txt","r");
	FILE *fg = fopen ("output1.txt","w");
	fscanf(fd, "%d", &t);
	while(t--)
	{
		fscanf(fd, "%d",&n);
		for(j = 0; j < n; j++)
			fscanf(fd, "%d", &a[j]);
		Min2(a,n, &min1, &min2);
		if(min1 == min2)
			fprintf(fg,"-1\n");
		else fprintf(fg,"%d %d\n",min1, min2);

	}
	fclose(fd);
	fclose(fg);
}
