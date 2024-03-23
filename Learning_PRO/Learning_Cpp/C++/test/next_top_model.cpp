#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct ts
{
	string name;
	int h;
	int w;
	int id;
}a[10000];
bool cmp(ts t1, ts t2)
{
	if((double) t1.h/t1.w == (double) t2.h/t2.w) 
	{
		if(t1.h == t2.h) return t1.id < t2.id;
		return t1.h > t2.h;
	}
	return (double) t1.h/t1.w > (double) t2.h/t2.w;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++)	
	{
		getline(cin, a[i].name);
		getline(cin, a[i].name);
		cin>>a[i].h >> a[i].w;	
		a[i].id=i+1;
	}
	sort(a,a+n,cmp);
	for(int i=0; i<n; i++)
	{	
		printf("SBD %04d: ",a[i].id);
		cout<<a[i].name<<", "<<a[i].h<<", "<<a[i].w;
		cout<<'\n';
	}
}
