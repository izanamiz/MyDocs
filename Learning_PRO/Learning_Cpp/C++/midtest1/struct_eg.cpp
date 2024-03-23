#include<iostream>
#include<string>
using namespace std;

struct student
{
   string name;
   int toan,li,tin;
};
int main()
{  
    int i,n;
    cin>>n;cin.ignore(); 
    student a[100];
    for(i=0; i<n; i++)
    {
    	getline(cin,a[i].name);
  		cin>>a[i].toan;
		cin>>a[i].li;
		cin>>a[i].tin;
    }
    for(i=0; i<n; i++)
    {
  		cout<<a[i].name<<" "<<a[i].toan<<" "<<a[i].li<<" "<<a[i].tin;
  		cout<<'\n';
    }
    return 0;
}
