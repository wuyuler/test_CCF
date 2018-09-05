#include<iostream>
using namespace std;

int main(){
	int a=-1;
	int sum =0;
	int l =2;
	while(a!=0){
		if(a!=-1){
			
			cin>>a;
			if(a==1){
				l=2;
				sum+=1;
			}
			else if(a==2){
				
				sum+=l;
				l+=2;
			}
			
		}else{
			cin>>a;
			if(a==1)sum+=1;
			else if(a==2){
				sum+=2;
				l+=2;
			}
		}
		
		
	}
	cout<<sum; 
	
} 
