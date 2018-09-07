#include<iostream>
using namespace std;

int n,k;
int weight[1024];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	int num=0;
	int oneForPerson=0;
	for(int i=0;i<n;i++){
		oneForPerson+=weight[i];
		if(oneForPerson>=k){
			oneForPerson=0;
			num++;
		}
	}
	if(oneForPerson!=0) 
	cout<<num+1;
	else cout<<num;
	return 0;
}
