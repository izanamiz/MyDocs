#include<iostream>

using namespace std;

int main()
{
	int n;cin>>n;
	int x=0,y=0;
	string s;
	cin>>s;
	int drt=1;
	for(int i=0;i<s.length();i++)
	{
		if(drt==1)
		{
			if(s[i]=='G'){
				y++;
				drt=1;
			}
			if(s[i]=='L'){
				x--;
				drt=2;	
			}
			if(s[i]=='R'){
				drt=4;
				x++;
			}
			if(s[i]=='B')
			{
				drt=3;
				y--;
			}		
		}
		else if(drt==2){
			if(s[i]=='G'){
				drt=2;
				x--;
			}
			if(s[i]=='L'){
				drt=3;
				y--;
			}
			if(s[i]=='R'){
				drt=1;
				y++;
			}
			if(s[i]=='B'){
				drt=4;
				x++;
			}
		}
		else if(drt==3){
			if(s[i]=='G'){
				drt=3;
				y--;
			}
			if(s[i]=='L'){
				drt=4;
				x++;
			}
			if(s[i]=='R'){
				drt=2;
				x--;
			}
			if(s[i]=='B'){
				drt=1;
				y++;
			}
		}
		else if(drt==4){
			if(s[i]=='G'){
				drt=4;
				x++;
			}
			if(s[i]=='L'){
				drt=1;
				y++;
			}
			if(s[i]=='R'){
				drt=3;
				y--;
			}
			if(s[i]=='B'){
				drt=2;
				x--;
			}
		}
	
	}
	cout<<x<<" "<<y;
}
