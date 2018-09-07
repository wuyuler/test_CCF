#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


int N,K,key[1024];



struct Teacher{
	int keyName;
	int begin;
	int end;
	Teacher(int keyName,int begin,int end):keyName(keyName),begin(begin),end(end){
	}
	Teacher(){
	}
};

bool cmpp(const Teacher&a,const Teacher &b ){
	return a.begin<b.begin;
}

bool cmpq(const Teacher&a,const Teacher&b){
	return a.end==b.end?a.keyName<b.keyName:a.end<b.end;
}

int searchKey(int keyid){
	for(int i=0;i<N;i++){
		if(key[i]==keyid)return i;
	}
	cout<<"Î´ÕÒµ½";
	return -1; 
}
int main(){
	cin>>N>>K;
	
	vector<Teacher> p,q;
	for(int i=0;i<K;i++){
		
		Teacher t;
		cin>>t.keyName>>t.begin>>t.end;
		t.end+=t.begin;
		p.push_back(t);
		q.push_back(t);
		}
	sort(p.begin(),p.end(),cmpp);
	sort(q.begin(),q.end(),cmpq);
	for(int i=0;i<N;i++){
		key[i]=i+1;
	}
	int i=0,j=0;
	while(i<K&&j<K){
		if(p[i].begin<q[j].end){
		key[searchKey(p[i++].keyName)]=-1;
		
		}
		else{
			key[searchKey(-1)]=q[j++].keyName;
		}
	}
	while(j<K){
		key[searchKey(-1)]=q[j++].keyName;
	}

	
//	getKeys(keys,w,s,c,3,num_key,K) ;
	for(int i=0;i<N;i++){
		if(i==0)cout<<key[i];
		else cout<<" "<<key[i];
		
	}
	
	
	
	return 0;
} 
