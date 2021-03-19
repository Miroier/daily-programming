#include <iostream>
#include <algorithm>
using namespace std;
int n;
double X,Y;
struct loc{
	int count;
	double x,y;
	double dis;
	void inp(){
		cin>>x>>y;
		dist();
	}
	void dist(){
		dis=(x-X)*(x-X)+(y-Y)*(y-Y);
	}
}a[205];
bool cmp(loc a,loc b){
	if(a.dis!=b.dis)
		return a.dis<b.dis;
	else
		return a.count<b.count;
}
int main(){
	int cnt=1;
	cin>>n>>X>>Y;
	for(int i=1;i<=n;i++)
	{	
		a[i].inp();
		a[i].count=cnt++;
	}	
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=3;i++){
		cout<<a[i].count<<endl;
	}
	return 0;
}
