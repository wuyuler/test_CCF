//×îĞ¡²îÖµ
#include<iostream>
using namespace std;
#include<math.h>
#include<vector>
int const MAX=10000;
int main(){
	int num;
	cin>>num;
	vector<int> v;
	for(int i=0;i<num;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int min=MAX;
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++){
			if(j!=i&&abs(v[j]-v[i])<min){
				min = abs(v[j]-v[i]);
				if(min==0)break;
			}
		}
		
		cout<<min;
	return 0;
}

