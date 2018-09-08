#include<iostream>
#include<algorithm>
#include<vector>
 using namespace std;
 
 int n;
 
 int cmpLeft(vector<int>& v,int index){
 	int sum=0;
	 for(int i=0;i<index;i++){
 		if(v[i]<v[index])sum++;
	 }
	 return sum;
 }
  int cmpRight(vector<int>& v,int index){
 	int sum=0;
	 for(int i=index+1;i<v.size();i++){
 		if(v[i]>v[index])sum++;	
	 }
	 return sum;
 }
 int main(){
 	cin>>n;
 	vector<int> v(n);
 	for(int i=0;i<n;i++){
 		cin>>v[i];
	 }
	 sort(v.begin(),v.end());
	 if(v.size()==1)cout<<v[0];
	 else{
	 	int a=0;
	 	for(int i=0;i<v.size();i++){
	 		if(cmpLeft(v,i)==cmpRight(v,i)){
	 			cout<< v[i];
	 			a=1;
	 			break;
			 }
		 }
		 if(a==0)
		 cout<< -1;
	 }
 	
 	return 0;
 } 
