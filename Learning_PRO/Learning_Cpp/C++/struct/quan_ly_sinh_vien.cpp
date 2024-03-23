#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
struct ninja
{
	string name;
	int age;
	double gpa;
}sv[1000];
	int n,k; 
void ten(){
	int i,j;
	for(i=0; i<n-1; i++)
	  for(j=i+1; j<n; j++)
		if(sv[i].name > sv[j].name)	 
		  swap(sv[i], sv[j]);
}
void tuoi(){
	int i,j;
	for(i=0; i<n-1; i++)
	  for(j=i+1; j<n; j++)
		if(sv[i].age > sv[j].age)	
		  swap(sv[i], sv[j]);
}
void diem(){
	int i,j;
	for(i=0; i<n-1; i++)
	  for(j=i+1; j<n; j++)
		if(sv[i].gpa < sv[j].gpa)	
		  swap(sv[i], sv[j]);
}
	
int main(){
	cin>> n >> k;
	for(int i=0; i<n; i++)
		cin >>sv[i].name >> sv[i].age >> sv[i].gpa; 
	if(k==0) ten();
	else if(k==1) tuoi();
	else diem();
	for(int i=0; i<n; i++){
		cout<<sv[i].name <<" " <<sv[i].age <<" ";
		printf("%.1lf\n",sv[i].gpa);
	}
}
	

