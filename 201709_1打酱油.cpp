#include<iostream> 
using namespace std;

int main(){
	int money;
	cin>>money;
	int base_num = money/10;
	int numOf5=base_num/5;
	int numOf3=base_num%5/3;
	int sum = base_num+2*numOf5+numOf3;
	cout<<sum;
	
	return 0;
} 
