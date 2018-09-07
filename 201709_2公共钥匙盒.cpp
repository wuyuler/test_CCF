#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//return key
void returnKey(int keys[],vector<int>& numberOfKey,int sizeOfKeys){
	if(numberOfKey.size()!=0){
		sort(numberOfKey.begin(),numberOfKey.end());
	int a=0;
	for(int i=0;i<sizeOfKeys;i++){
		if(keys[i]==0){
			keys[i] = numberOfKey[a];
			a++;
			if(a==numberOfKey.size())break;
		}
		
	}
	}
	
}

void getKey(int keys[],vector<int>& numberOfKey,int sizeOfKeys){
	if(numberOfKey.size()!=0){
		int a=0;
	//cout<<numberOfKey[0]<<endl;
	for(int i=0;i<sizeOfKeys;i++){
		//cout<<1<<endl;
		if(keys[i]==numberOfKey[a]){
			keys[i]=0;
			a++;
			
			if(a==numberOfKey.size())break;
		}
	}
	}
	
	
}

//return the keys at the specified time
void setKeys(int keys[],int w[],int s[],int c[],int times,int sizeOfKeys,int sizeOfW){
	vector<int> keysReturned;
	for(int i=0;i<sizeOfW;i++){
		if(s[i]+c[i]==times){
			keysReturned.push_back(w[i]);
			//cout<<"在时间"<<times<<"还钥匙"<<w[i]<<endl;
		}
	}
	returnKey(keys,keysReturned,sizeOfKeys);
}
//get keys needed at a certain moment
void getKeys(int keys[],int w[],int s[],int c[],int times,int sizeOfKeys,int sizeOfW){
	vector<int> keysNeeds;
	for(int i=0;i<sizeOfW;i++){
		if(s[i]==times){
			keysNeeds.push_back(w[i]);
			//cout<<"在时间"<<times<<"拿钥匙"<<w[i]<<endl;
		}
	}
	getKey(keys,keysNeeds,sizeOfKeys);
} 
int main(){
	int num_key;
	int K;
	cin>>num_key>>K;
	int w[K],s[K],c[K];
	for(int i=0;i<K;i++)
	{
		cin>>w[i]>>s[i]>>c[i];
	}
	int keys[num_key];
	for(int i=0;i<num_key;i++){
		keys[i]=i+1;
	}
	int endTime[K];
	for(int i=0;i<K;i++){
		endTime[i]=s[i]+c[i];
	} 
	int max_time=*max_element(endTime,endTime+K);
	for(int i=0;i<=max_time;i++){
		setKeys(keys,w,s,c,i,num_key,K) ;
		getKeys(keys,w,s,c,i,num_key,K);
	} 
	

	
//	getKeys(keys,w,s,c,3,num_key,K) ;
	for(int i=0;i<num_key;i++){
		if(i==0)cout<<keys[i];
		else cout<<" "<<keys[i];
		
	}
	
	
	
	return 0;
} 
