#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


int N,K,key[1024];
////return key
//void returnKey(int keys[],vector<int>& numberOfKey,int sizeOfKeys){
//	if(numberOfKey.size()!=0){
//		sort(numberOfKey.begin(),numberOfKey.end());
//	int a=0;
//	for(int i=0;i<sizeOfKeys;i++){
//		if(keys[i]==0){
//			keys[i] = numberOfKey[a];
//			a++;
//			if(a==numberOfKey.size())break;
//		}
//		
//	}
//	}
//	
//}
//
//void getKey(int keys[],vector<int>& numberOfKey,int sizeOfKeys){
//	if(numberOfKey.size()!=0){
//		int a=0;
//	//cout<<numberOfKey[0]<<endl;
//	for(int i=0;i<sizeOfKeys;i++){
//		//cout<<1<<endl;
//		if(keys[i]==numberOfKey[a]){
//			keys[i]=0;
//			a++;
//			
//			if(a==numberOfKey.size())break;
//		}
//	}
//	}
//	
//	
//}
//
////return the keys at the specified time
//void setKeys(int keys[],int w[],int s[],int c[],int times,int sizeOfKeys,int sizeOfW){
//	vector<int> keysReturned;
//	for(int i=0;i<sizeOfW;i++){
//		if(s[i]+c[i]==times){
//			keysReturned.push_back(w[i]);
//			//cout<<"在时间"<<times<<"还钥匙"<<w[i]<<endl;
//		}
//	}
//	returnKey(keys,keysReturned,sizeOfKeys);
//}
////get keys needed at a certain moment
//void getKeys(int keys[],int w[],int s[],int c[],int times,int sizeOfKeys,int sizeOfW){
//	vector<int> keysNeeds;
//	for(int i=0;i<sizeOfW;i++){
//		if(s[i]==times){
//			keysNeeds.push_back(w[i]);
//			//cout<<"在时间"<<times<<"拿钥匙"<<w[i]<<endl;
//		}
//	}
//	getKey(keys,keysNeeds,sizeOfKeys);
//} 


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
	cout<<"未找到";
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
