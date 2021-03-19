#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n,m;
int type1,type2;
int t0,t1,t2;
struct p{
	int x,y;
	int flag;
	string c;
	void inp(){
		cin>>x>>y>>c;
		if(c=="A")
			type1++,flag=1;
		if(c=="B")
			type2++,flag=17;
	}
}a[1005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i].inp();
	}
	for(int j=1;j<=m;j++){
		int cnt1=0,cnt2=0;
		cin>>t0>>t1>>t2;
		for(int i=1;i<=n;i++){
			if(t0+t1*a[i].x+t2*a[i].y>0)
				cnt1+=a[i].flag;
		}
		if(cnt1==type1||cnt1==17*type2)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
