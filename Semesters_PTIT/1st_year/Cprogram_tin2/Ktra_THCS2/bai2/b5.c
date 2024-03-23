#include<stdio.h>
int n;
int b[105];
void doctep()
{
	FILE *f1 = fopen("in.txt","r");
	fscanf(f1,"%d",&n);
	for(int i=0; i<n; i++) fscanf(f1,"%d",&b[i]);
	fclose(f1);
}

void xuly()
{
	for(int i=0; i<n-1; i++)
	{
		int index = i;
		for(int j=i+1; j<n; j++)
		{
			if(b[j] < b[index])
				index = j;
		}
		if(index != i)
        {
            int tmp = b[i];
            b[i] = b[index];
            b[index] = tmp;

        }
	}

}
void ghitep()
{
	FILE *f2 = fopen("out.txt","w");
	for(int i=0; i<n; i++) fprintf(f2,"%d ",b[i]);
	fclose(f2);
}
int main()
{
	doctep();
	xuly();
	ghitep();
}
