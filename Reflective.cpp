#include <iostream>
#include <cmath>
using namespace std;

long long com(long long i){
	long long ans=i;
	long long expo=1;
	while(i-1>0){
		i--;
		ans+=expo*i;
		expo=expo*2;
	}
	return ans;
}

long long lf, rt;

int main(){
	/*
	Code Test
	cin>>lf>>rt;
	long long ans=0;
	for(long long i=lf;i<=rt;i++){
		long long p=1;
		long long pValue=2;
		while(i>=pValue && i%pValue==0){
			p++;
			pValue=pValue*2;
		}
		ans+=p-1;
	}
	cout<<ans<<endl;
	*/
	
	
	cin>>lf>>rt;
	lf--;
	long long L=0;
	while(lf>1){
		long long temp=lf & (lf-1);
		L+=com(log2(lf-temp));
		lf=temp;
	}	
	long long R=0;
	while(rt>1){
		long long temp=rt & (rt-1);
		R+=com(log2(rt-temp));
		rt=temp;
	}
	cout<<R-L<<endl;
	
}
