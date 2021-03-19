#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
struct p{
	int ind,val;
};
vector<p> x;
vector<p> y;
LL sum;
int n,a,b;
int main(){
	cin>>n>>a>>b;
	int ind,val;
	for(int i=1;i<=a;i++){
		cin>>ind>>val;
		if(val)
			x.push_back({ind,val});
	}
	for(int i=1;i<=b;i++){
		cin>>ind>>val;
		if(val)
			y.push_back({ind,val});
	}
	int pa=0,pb=0;
	while(pa<a&&pb<b){
		if(x[pa].ind==y[pb].ind)
			sum+=x[pa++].val*y[pb++].val;
		else if(x[pa].ind<y[pb].ind)
			pa++;
		else
			pb++;
	}
	cout<<sum;
}
