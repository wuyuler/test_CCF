#include<iostream>
using namespace std;

int T;

double up(double base,double rule){
	if((base-rule)>0)return base-rule;
	else return 0;
}

double up(double base,double low,double high){
	if(base<=low)return 0;
	else if(base<=high)return base-low;
	else return high-low;
}
double down(double S,double high){
	if(S>high)return high;
	else return S;
}
double cal(double S){
	
	if(S<3500)return S;
	else{
		S=S-3500;
		return 3500+S-(up(S,80000)*0.45+up(S,55000,80000)*0.35+up(S,35000,55000)*0.3+up(S,9000,35000)*0.25+up(S,4500,9000)*0.2+up(S,1500,4500)*0.1+down(S,1500)*0.03);

	}
	
}
struct Qu{
	double low;
	double high;
	Qu(double low,double high):low(low),high(high){
	}
};

Qu getQu(double T){
	if(T<=3500)return Qu(0,3500);
	else if(T<=4955)return Qu(3500,5000);
	else if(T<=7655)return Qu(5000,8000);
	else if(T<=11255)return Qu(8000,12500);
	else if(T<=30755)return Qu(12500,38500);
	else if(T<=44755)return Qu(38500,58500);
	else if(T<=61005)return Qu(58500,83500);
	else return Qu(83500,200000); 
}

int main(){

//	cout<<5000-1500*0.03<<endl;
//	cout<<8000-(1500*0.03+3000*0.1)<<endl;
//	cout<<12500-(1500*0.03+3000*0.1+4500*0.2)<<endl;
//
//	cout<<38500-(1500*0.03+3000*0.1+4500*0.2+26000*0.25)<<endl;
//
//	cout<<58500-(1500*0.03+3000*0.1+4500*0.2+26000*0.25+20000*0.3)<<endl;
//
//	cout<<83500-(1500*0.03+3000*0.1+4500*0.2+26000*0.25+20000*0.3+25000*0.35)<<endl;
//
//	cout<<200000-(1500*0.03+3000*0.1+4500*0.2+26000*0.25+20000*0.3+25000*0.35+120000*0.45)<<endl;

//	Qu qu=getQu(9255);
//	cout<<"low:"<<qu.low<<"high:"<<qu.high<<endl;
		cin>>T;
	Qu qu=getQu(T);
	for(int i=qu.low;i<=qu.high;i+=100){
		if(cal(i)==T){
			cout<<i;
			break;	
		}
	}
		
	
	
	return 0;
}
