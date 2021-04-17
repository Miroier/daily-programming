#include "iostream"
#include "algorithm"
using namespace std;
int a[1005],b[1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i]; 
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=(a[i]*b[n-i-1]);
		cout<<sum<<endl;
	}
}
