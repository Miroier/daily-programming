#include "iostream"
using namespace std;
typedef long long LL;
const int N=2000005,MOD=50000;
bool isprime[N];
LL prime[100005];
LL cnt;
int n;
void Prime(){
	for(int i=2;i<N;i++)
		isprime[i]=true;
	for(LL i=2;i<N;i++){
		if (isprime[i])
        {
            prime[cnt++] = i;
            if(cnt==100000)
            	return;
        }
        for(LL j=0;j<cnt&&prime[j]*i<N;j++){
    		isprime[prime[j]*i]=false;
    		if(i%prime[j]==0)
    			break;
		} 
	}		
}
int main(){
	Prime();
	LL ans=1;
	cin>>n;
	for(int i=0;i<n;i++)
		ans=(ans*prime[i])%MOD;
	cout<<ans;
}
