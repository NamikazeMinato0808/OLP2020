#include <iostream>
#include <string>
using namespace std;

int freqA[202020], freqV[202020], freqC[202020];
string s;
int k;

int main(){
	cin>>k;
	cin>>s;
	freqA[0]=freqV[0]=0;
	freqC[0]=0;
	
	for(int i=0;i<s.size();i++){
		freqA[i+1]=freqA[i];
		freqV[i+1]=freqV[i];
		freqC[i+1]=freqC[i];
		if(s[i]=='V') freqV[i+1]++;
		else if(s[i]=='C') freqC[i+1]++;
		else freqA[i+1]++;
	}
	
	int ans=100000;
	for(int i=0;i<s.size()-3*k;i++){
		int HEAD=i+3*k-1;
		int TAIL=s.size()+1;
		
		int res=100000;
		while(HEAD<=TAIL){
			int MID=(HEAD+TAIL)/2;
			if(freqA[MID]>=freqA[i]+k && freqV[MID]>=freqV[i]+k && freqC[MID]>=freqC[i]+k){
				res=MID;
				TAIL=MID-1;
			}
			else HEAD=MID+1;
		}
		if(res!=100000){
			if(ans>res-i-3*k) ans=res-i-3*k;
		}
	}
	if(ans!=1000000) cout<<ans<<endl;
	else cout<<-1<<endl;
}
