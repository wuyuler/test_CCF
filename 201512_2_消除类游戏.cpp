#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<vector<int> > v;
vector<vector<int> > isRemove;

void output(vector<vector<int> >& v1){
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<v1[i].size();j++){
			if(j==0)cout<<v1[i][j];
			else cout<<" "<<v1[i][j];
		}
		if(i!=v1.size()-1)cout<<endl;
	}
	
}

bool toRemove(int r,int c){
	
	int num_Row=1;
	int num_Col=1;
	//横向
	//左
	for(int i=c-1;i>=0;i--){
		 if(v[r][i]==v[r][c])num_Row++;
		 else break;
	} 
	//向右
	for(int i=c+1;i<m;i++){
		 if(v[r][i]==v[r][c])num_Row++;
		 else break;
	}
	
	//竖向
	//向上
	for(int i=r-1;i>=0;i--){
		if(v[i][c]==v[r][c])num_Col++;
		else break;
	} 
	//向下
	 for(int i=r+1;i<n;i++){
		if(v[i][c]==v[r][c])num_Col++;
		else break;
	} 
	
	//cout<<"row:"<<num_Row<<"col:"<<num_Col<<endl;
	if(num_Row>=3||num_Col>=3)isRemove[r][c]=1;
}

void update(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(isRemove[i][j]==1)
				v[i][j]=0;
			
		} 
	} 
	
}
int main(){
	cin>>n>>m;
	v.resize(n);
	isRemove.resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			v[i].push_back(a);
			isRemove[i].push_back(0);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		toRemove(i,j);
		
	}
	//output(isRemove);
	update();
	output(v);
	return 0;
}
