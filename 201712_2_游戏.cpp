//游戏
#include<iostream>
using namespace std;
#include<math.h>
#include<vector> 
void isalive(int&alive,int m_num,int k){
	if((m_num%k==0)||(m_num%10==k))alive=0;
} 

bool hasOnePerson(vector<int> a){
	int count=0;
	for(int i=0;i<a.size();i++ ){
		if(a[i]==1)count++;
	}
	if(count==1)return true;
	return false;
}
int main(){
	int n,k;//n表示小朋友个数,k表示规定数字 
	int count=1;//从1开始报数 
	int p=0;//轮流选择小学生 
	cin>>n>>k;
	vector<int> a;//1表示未被淘汰 
	for(int i=0;i<n;i++){
		a.push_back(1); 
		} 
	while(!hasOnePerson(a)){
		if(a[p]!=0){
		isalive(a[p],count,k);
		count++;
		}
		
		p=(p+1)%n;
	}
	for(int i=0;i<a.size();i++)
		if(a[i]==1)cout<<i+1;
	
}
