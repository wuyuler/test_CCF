#include<iostream>
#include<vector>
using namespace std;

int n;
int ins[100];
bool isEmpty[100];

vector<int>getOneRow(int num){
	vector<int> oneRow;
	for(int i=0;i<100;i+=5){
		for(int j=i;j<i+5;j++){
			if(oneRow.size()==num)break;
			else if(isEmpty[j]==true){
				oneRow.push_back(j+1);
			}
			
		}
	if(oneRow.size()==num)break;
	else oneRow.clear();		
	}
	for(int i=0;i<oneRow.size();i++){
		isEmpty[oneRow[i]-1]=false;
	}
	return oneRow;
}

void output(vector<int>& v){
	for(int i=0;i<v.size();i++){
		if(i==0)cout<<v[i];
		else cout<<" "<<v[i];
	}
}
int main(){
	for(int i=0;i<100;i++)
		isEmpty[i]=true;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>ins[i];
	
	for(int i=0;i<n;i++){
	vector<int> v=	getOneRow(ins[i]);
	if(v.size()!=0){
		output(v);
		if(i!=n-1)cout<<endl;
	}
	else{
		for(int j=0;j<100;j++){
			if(isEmpty[j]==true){
				v.push_back(j+1);
				isEmpty[j]=false;
			}
			if(v.size()==ins[i]){
				output(v);
				if(i!=n-1)cout<<endl;
				break;
			}
		}
	}
	} 

	
	return 0;
	
}
