#include<iostream>
#include<math.h>
using namespace std;

struct set
{
	double x;
	double y;
};

int main()
{
	set a[100];
	int n;cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i].x;
		cin>>a[i].y;	
	}
	double len;
	double max=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			len= sqrt((double) (a[i].x-a[j].x)*(a[i].x-a[j].x) -(a[i].y-a[j].y)*(a[i].y-a[j].y));
			if(len>max) max=len;
		}
	}
	cout<<max;
	
}
