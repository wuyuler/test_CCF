#include<iostream>
#include<vector>
using namespace std;

	struct Plot{
		int x,y;
		int dis;
		Plot(int x,int y):x(x),y(y){
		}
		Plot(){
		}
	};

	vector<vector<int> > plat(15);
	vector<vector<int> > shape(4);
	int shapeDis[4];
	int col;
	Plot plot[4];
	
	
//获取矩阵某列第一个1的行数 
int getDistance(int col,vector<vector<int> > v){
	//row和column从0开始
	 
	 for(int i=0;i<v.size();i++){
	 	if(v[i][col]==1)return i; 
	 }
	return 15;
} 

//根据x的新坐标系更新y,保证位置关系不变 
Plot move(Plot x1,Plot x2,Plot y1){
	int dis_y=y1.y-x1.y;
	int dis_x=y1.x-x1.x;
	return(Plot(x2.x+dis_x,x2.y+dis_y));
	 
}
 void getShapeDis(){
 	
 	int item=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(shape[i][j]==1){
				int dis_shape=shape.size()-i-1;
				int dis_plat=getDistance(col+j-1,plat);
				plot[item].x=i;
				plot[item].y=j;
				plot[item].dis=dis_shape+dis_plat;
				item++;
			}
		}
	}
	
}

int getMaxDis(){
	int num=0;
	int max=plot[0].dis;
	for(int i=0;i<4;i++){
		if(plot[i].dis<max){
			num=i;
			max=plot[i].dis;
		}
	}
	return num;
}
void output(vector<vector<int> >& v){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			if(j==0)cout<<v[i][j];
			else cout<<" "<<v[i][j];
		}
		if(i!=v.size()-1)cout<<endl;
			
	}
	
}
int main(){
	
	for(int i=0;i<15;i++){
		for(int j=0;j<10;j++){
			int a;
			cin>>a;
			plat[i].push_back(a);
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int a;
			cin>>a;
			shape[i].push_back(a);
		}
	}
	cin>>col;
	//cout<<getDistance(0,plat);
//	output(plat);cout<<endl;
//	output(shape);
	//cout<<getDistance(0,1,shape);
	getShapeDis();
//	for(int i=0;i<4;i++){
//		cout<<plot[i].dis<<endl;
//	}
	int max=getMaxDis();
	Plot max1=plot[max];
	plot[max].y=col+plot[max].y-1;
	plot[max].x=getDistance(plot[max].y,plat)-1;
	//cout<<"移动完后:"<< "x:"<<plot[max].x<<"y:"<<plot[max].y<<endl;
	for(int i=0;i<4;i++){
		if(i!=max){
		plot[i]=move(max1,plot[max],plot[i]);
		//cout<<"移动完后:"<< "x:"<<plot[i].x<<"y:"<<plot[i].y<<endl; 
		}
	}
	for(int i=0;i<4;i++){
		if(plot[i].y>=0){
			plat[plot[i].x][plot[i].y]=1;
		}
		
	}
	output(plat);
	
	return 0;
}
