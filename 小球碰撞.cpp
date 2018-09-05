#include<iostream>
using namespace std;

int main(){
	int n,L,t;
	cin>>n;
	cin>>L;
	cin>>t;
	
	int *sum = new int[n];
	int *f=new int[n];
	int *lastf=new int[n];
	
	for(int i=0;i<n;i++){
		cin>>sum[i];
		f[i] = 1;
		lastf[i]=1;
	}
		
	for(int i=1;i<=t;i++){//时间计数 
		
		 
		
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(k!=j&&sum[j]==sum[k]){
				f[k] =lastf[k]*-1;
				f[j] =lastf[j]*-1; 
			}
			}
			if(sum[j]==L){
				f[j]=-1;
			}
			else if(sum[j]==0){
				f[j] = 1;
			}
		}
		
		for(int k=0;k<n;k++){
			
			sum[k]+=f[k];
			lastf[k] = f[k];
		}
		
		
	}
	
	for(int i=0;i<n;i++){
		if(i==n-1)cout<<sum[i];
		else
		cout<<sum[i]<<" ";
	}
	return 0;
} 
