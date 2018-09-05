#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//bug:无法判断最后斜杠是否匹配 
void subUrl(string s,vector<string>& v) {
	int last=0,num=0;
	int length = s.length();
	v.clear();
	for(int i=0; i<length; i++) {
		if(s[i]!='/') {
			num++;
			if(i==length-1) {
				string s_temp = s.substr(last+1,num);
				v.push_back(s_temp);
			}
		} else if(i!=0) {
			string s_temp = s.substr(last+1,num);
			v.push_back(s_temp);
			last = i;//上一个'/' 所在的位置
			num = 0;
		}
	}


}

int findIndexOfPath(vector<string> rule) {
	
	for(int i=0; i<rule.size(); i++)
		if(rule[i]=="<path>")
			return i;

	return -1;

}
string getPathInUrl(string url,vector<string> url2,int index_path) {
	string pir_url="/";
	for(int i=0; i<index_path; i++) {
		pir_url+=url2[i]+"/";
	}
	//cout<<pir_url<<endl;
	return url.substr(pir_url.size());

}

bool is_rule(vector<string> rule,vector<string>& url,vector<int>& numOfPara) {
	int a=0;	
	  
	if((rule.size()!=url.size())&&findIndexOfPath(rule)==-1) return false;
	else {

		for(int i=0; i<rule.size(); i++) {
			if(rule[i]=="<int>") {

				for(int j=0; j<url[i].size(); j++) {
					if(url[i][j]<'0'||url[i][j]>'9') {
						a=-1;
						break;
					}

				}
				if(a==-1)break;
				else {
					while(url[i][0]=='0'&&url[i].size()!=1)url[i].erase(0,1);
					
					numOfPara.push_back(i);
					continue;
				}
			} else if(rule[i]=="<str>") {
				for(int j=0; j<url[i].size(); j++) {
					char temp = url[i][j];
					if((temp>='0'&&temp<='9')||(temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||(temp=='-')||temp=='_'||temp=='.') {
						continue;
					} else {
						a=-1;
						break;
					}

				}
				if(a==-1)break;
				else {
					numOfPara.push_back(i);
					continue;
				}
			} else if(rule[i]=="<path>") {
				for(int k=i; k<url.size(); k++) {
					for(int j=0; j<url[k].size(); j++) {
						char temp = url[k][j];
						if((temp>='0'&&temp<='9')||(temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||(temp=='-')||temp=='_'||temp=='.') {
							continue;
						} else {
							a=-1;
							break;
						}

					}
					if(a==-1)break;
					else {
						numOfPara.push_back(i);
						break;
					}
				}
			} else {
				if(rule[i]==url[i])continue;
				else {
					a=-1;
					break;
				}
			}

		}

		if(a==-1) {
			numOfPara.clear();
			return	false;
		} else return true;

	}



}
int main() {
	int n,m;
	
	cin>>n;
	cin>>m;
	 
	string* rule = new string[2*n];//存储规则,2i为规则的模式2i+1为规则的名称 (i=0,1...)
	string* url=new string[m];
	
	vector<vector<int> > numOfPara;
	numOfPara.resize(m);
	isdigit(rule[0][0]); 
	for(int i=0; i<2*n; i++) {
		cin>>rule[i];
	}
	for(int i=0; i<m; i++) {
		cin>>url[i];
	}
	vector<vector<string> > all_rule ;//两个> >要空格分开
	all_rule.resize(n);
	for(int i=0; i<n; i++) {
		subUrl(rule[2*i],all_rule[i]);
		//	cout<<all_rule[i][1]<<endl;
	}

	vector<vector<string> > all_url ;
	all_url.resize(m);
	for(int i=0; i<m; i++) {
		subUrl(url[i],all_url[i]);
		//cout<<all_url[i][0]<<endl;
	}

//	if(is_rule(all_rule[1],all_url[0]))cout<<"yes"<<endl;
//	else cout<<"no";
	//cout<<getPathInUrl(url[3],all_url[3],findIndexOfPath(all_rule[4]));
	for(int i=0; i<m; i++) {
		int a=-1;//-1表示未找到匹配规则
		for(int j=0; j<n; j++) {
			//判断i个url和j个规则是否匹配,如果匹配,a=j;否则continue


			if(is_rule(all_rule[j],all_url[i],numOfPara[i])) {
				a=j;
				break;
			} else continue;

		}
		if(a==-1)cout<<"404"<<endl;
		else {
			if(findIndexOfPath(all_rule[a])==-1) {
				cout<<rule[2*a+1];
				for(int j=0; j<numOfPara[i].size(); j++)
					cout<<" "<<all_url[i][numOfPara[i][j]];
				//cout<<numOfPara[i];
				if(i!=m-1)
					cout<<endl;

			} else {
				cout<<rule[2*a+1];
				for(int j=0; j<numOfPara[i].size()-1; j++) {
					cout<<" "<<all_url[i][numOfPara[i][j]];

				}



				cout<<" "<<getPathInUrl(url[i],all_url[i],findIndexOfPath(all_rule[a]));
				if(i!=m-1)
					cout<<endl;
			}

		}
	}



	return 0;
}



