#include<stdio.h>
int t, a[105] , n;

int ktdx()
{

	int l = 0;
	int r = n-1;
	while(l <= r)
	{
		if(a[l] == a[r])
		{
			l++;
			r--;
		}
		else return 0;
	}
	return 1;
}
void ghitep()
{
	FILE *f2 = fopen("output.txt","a+");
	if(ktdx()) fprintf(f2,"YES\n");
	else fprintf(f2,"NO\n");
}
void doctep()
{
	FILE *f1 = fopen("input.txt","r");
	FILE *f2;
	fscanf(f1,"%d", &t);
	while(t--)
	{
		fscanf(f1,"%d",&n);
		for(int i=0; i<n; i++) fscanf(f1,"%d",&a[i]);
		ghitep();
	}
	f2 = fopen("output.txt","w");
	fclose(f1); fclose(f2);
}
int main()
{
	doctep();
}
