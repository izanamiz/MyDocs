#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[1000][1000];
ll m,n;

ll Sum(ll x, ll y)// viet hoa chu cai dau
{
	if(a[x][y]==0) return 0;
	ll s=0;
	if(x-1>=0){
		s+=max((ll)0,a[x][y]-a[x-1][y]);
	}else s+=a[x][y];
	
	if(x+1<m){
		s+=max((ll)0,a[x][y]-a[x+1][y]);
	}else s+=a[x][y];
	
	if(y+1<n){
		s+=max((ll)0,a[x][y]-a[x][y+1]);
	}else s+=a[x][y];
	
	if(y-1>=0){
		s+=max((ll)0,a[x][y]-a[x][y-1]);
	}else s+=a[x][y];

	return s+1;
}
int main(){
	ll t;scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&m,&n);
			
		for(ll i=0; i<m; i++){
			for(ll j=0; j<n; j++){
				scanf("%lld",&a[i][j]);
			}
		}
		ll tong=0;
		for(ll i=0; i<m; i++){
			for(ll j=0; j<n; j++){
				tong+=Sum(i,j);
			}
		}
		cout<<tong;
		cout<<endl;
	
	}
}
