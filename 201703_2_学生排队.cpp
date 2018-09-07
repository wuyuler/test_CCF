#include<iostream>
using namespace std;
#include<vector>
#include<math.h>

int n,m;
int queue[1024];
struct Move{
	int id;
	int length;
	Move(int id,int length):id(id),length(length){
	}
	Move(){
		
	}
};

int findIndexById(int id){
	for(int i=0;i<n;i++){
		if(queue[i]==id)return i;
	}
	cout<<"未找到"; 
}

void swapAfter(int id){
	int index=findIndexById(id);
	queue[index] = queue[index+1];
	queue[index+1]=id;
	//cout<<id<<"向后交换一次"<<endl; 
		
}
void swapBefore(int id){
	int index=findIndexById(id);
	queue[index] = queue[index-1];
	queue[index-1]=id;
	//cout<<id<<"向前交换一次"<<endl; 
}
void moveStu(Move m){
	if(m.length>0){
		for(int i=0;i<m.length;i++)
			swapAfter(m.id);
	}
	if(m.length<0){
		for(int i=0;i<abs(m.length);i++)
			swapBefore(m.id);
	}
}
int main(){
	cin>>n>>m;
	vector<Move> v;
	for(int i=0;i<m;i++){
		Move move;
		cin>>move.id>>move.length;
		v.push_back(move);
	}
	for(int i=0;i<n;i++){
		queue[i]=i+1;
	}

	for(int i=0;i<m;i++){
		//cout<<"本次调转"<<v[i].id<<endl; 
		moveStu(v[i]);
	}
	
	for(int i=0;i<n;i++){
		if(i==0)
		cout<<queue[i];
		else cout<<" "<<queue[i];
	}
	return 0;
}
