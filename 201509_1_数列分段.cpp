#include<iostream>
using namespace std;

int n;
int a[1024];

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=1;
	int b=a[0];
	for(int i=1;i<n;i++){
		if(a[i]==b)continue;
		else{
			sum++;
			b=a[i];
		}
		}
		cout<<sum;
		
	}
	

