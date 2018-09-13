#include<iostream>

using namespace std;

int n;
int main(){
	cin>>n;
	int sum=0;
	int a=1;
	for(int i=0;i<11;i++){
		int b = n%(a*10);
		b=b/a;
		a*=10;
		sum+=b;
	}
	cout<<sum;
	return 0;
} 
