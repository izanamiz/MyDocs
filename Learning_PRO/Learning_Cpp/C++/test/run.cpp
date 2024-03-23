#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#define MAX 10000
typedef long long ll;
using namespace std;
vector<bool> dd(MAX,true);
vector<int> nt;
void sang()
{
	for(int i=2; i*i<=MAX; i++)
	{
		if(dd[i]){
			for(int j=i*i; j<=MAX;j+=i)
				dd[j]=false;
			nt.push_back(i);	
		}
	}
}
int main()
{
	int n,k;
	cin>>n>>k;
	sang();
	for(int i=0; i<=nt.size(); i++)
		if(nt[i]>=n && nt[i]<=k) cout<<nt[i]<<" ";
	cout<<'\n';	
	cout<<__gcd(n,k)<<'\n';
}
