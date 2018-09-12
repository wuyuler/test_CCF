#include<iostream>
using namespace std;
int n;
int sale[1024];

int main(){
	int num=0;
	int last;
	int next;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sale[i];
	}
	for(int i=1;i<n-1;i++){
		last=i-1;
		next=i+1;
		if((sale[i]>sale[last]&&sale[i]>sale[next])||(sale[i]<sale[last]&&sale[i]<sale[next]))num++;
		
	}
	cout<<num;
	
	return 0;
} 
