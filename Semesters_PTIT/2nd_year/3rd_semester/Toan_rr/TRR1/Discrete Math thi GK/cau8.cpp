#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=0;
	int max=0;
	int gt[4]={10,5,3,6};
	int tl[4]={5,3,2,4};
	int x[1000];
	int y[1000];
	for(int i=0;i<4;i++){
		x[i]=0;
		y[i]=0;
	}
	int l=0;
	while(l<=14){
		int kg=0, cost=0;
        for(int i=4-1;i>=0;i--){
            if(x[i]==0){
                k=i;
                break;
            }
        }
        for(int i=k;i<4;i++){
            x[i]=1-x[i];
        }
        for(int i=0;i<4;i++){
        	kg+=tl[i]*x[i];
        	cost+=gt[i]*x[i];
		}
		if(kg<=8){
			if(cost>max){
				max=cost;
				for(int i=0;i<4;i++){
					y[i]=x[i];
				}
			}
		}
		l++;
    }
    cout << max << endl;
    for(int i=0; i<4; i++){
    	cout << y[i] << " ";
	}
}