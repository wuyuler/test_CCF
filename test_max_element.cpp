#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	
	vector<int> v;
	for(int i=0;i<5;i++)
	v.push_back(i);
	
	cout<<*max_element(v.begin(),v.end());
	return 0;
} 
