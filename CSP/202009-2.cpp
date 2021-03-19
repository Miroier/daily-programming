#include <iostream>
using namespace std;
int n,k,t,xl,yd,xr,yu;
struct loc{
	int x[1005],y[1005];
	bool pass;
	int cnt;
	bool stay;
	void inp(){
		for(int i=1;i<=t;i++){
			cin>>x[i]>>y[i];
			if(x[i]>=xl&&x[i]<=xr&&y[i]>=yd&&y[i]<=yu)
			{
				pass=true;
				cnt++;
				if(cnt>=k)
					stay=true;
				continue;
			}
			cnt=0;
		}
	}
}a[25];
int passcnt,staycnt;
int main(){
	cin>>n>>k>>t>>xl>>yd>>xr>>yu;
	for(int i=1;i<=n;i++){
		a[i].inp();
	}
	for(int i=1;i<=n;i++){
		if(a[i].pass)
			passcnt++;
		if(a[i].stay)
			staycnt++;
	}
	cout<<passcnt<<endl<<staycnt;
	return 0;
}
