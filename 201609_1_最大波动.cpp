#include<iostream>
#include<math.h>
using namespace std;
int n;
int num[1024];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>num[i];
	
	int max=abs(num[1]-num[0]);
	for(int i=0;i<n-1;i++){
		if(abs(num[i+1]-num[i])>max)max=abs(num[i+1]-num[i]);
	}
	cout<<max;
	
	
	return 0;
} 
