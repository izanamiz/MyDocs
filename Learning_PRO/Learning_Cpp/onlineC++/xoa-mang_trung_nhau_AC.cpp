#include<bits/stdc++.h>
#include<string>
#include<vector>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define f0(i,n) for(int i=0;i<n;i++)
#define sp(x) cout<<x<<" ";
#define en(x) cout<<x<<endl;
using namespace std;
typedef long long ll;
const int N=1e6+3;
const int MOD=1e9+7;
int main()
{
  ll n,m;
  cin>>n>>m;
  vector<ll>a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  vector<ll>b(m);
  for(int i=0;i<m;i++) cin>>b[i];
  for(int i=0;i<n;i++)
    {
    	if(a[i]==b[0])
        {
			int pos1=i,pos2=0;
			while(a[pos1]==b[pos2])
			{
				pos1++;
                pos2++;
			}
			if(pos2==m) a.erase(a.begin()+i,a.begin()+i+m);
		}
	}
	for(int i=0;i<a.size();i++) sp(a[i]);
}
