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
//	for(int i=0; i<n-1; i++)
//	{
//		for(int j=i+1; j<n; j++)
//		{
//			if(b[j] < b[i]) 
//			{
//				int tmp = b[i];
//				b[i] = b[j];
//				b[j] = tmp;
//			}
//		}
//	}
	int i=0;
	while(i<n){
		int j=0;
		while(j<n-1)
		{
			// 	7 	6	5	8
			//	13	7
			//  6   7	5
				//	12	7
				//	5   7	
			//	6	5	7	8
			//	5	6	7	8
					
			while(b[j] > b[j+1] && j<n-1)
			{
				b[j]   = b[j] + b[j+1];
				b[j+1] = b[j] - b[j+1];
				b[j]   = b[j] - b[j+1];
				j++;
			}
			j++;
		}
		i++;
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
