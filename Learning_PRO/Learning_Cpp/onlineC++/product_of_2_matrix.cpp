#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,i,j;cin>>n;
	vector<vector<int> > a(n,vector<int>(n));
	vector<vector<int> > b(n,vector<int>(n));
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			cin>>a[i][j];

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			cin>>b[i][j];
			
	vector<vector<int> > mult(n,vector<int>(n));
	for(i = 0; i<n; ++i)
        for(j=0; j<n; ++j)
            mult[i][j]=0;
        
    for(i=0; i<n; i++)
    {
    	for(j = 0; j<n; j++)
            for(int k=0; k<n; k++)
            {
                mult[i][j] += a[i][k] * b[k][j];
			 
			}
	 	
	}
        
            
    

    for(i = 0; i<n; ++i)
    	for(j = 0; j<n; ++j)
    	{
	        cout <<" " << mult[i][j];
	        if(j==n-1)
	            cout << endl;
    	}
   } 
