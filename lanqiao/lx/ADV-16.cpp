#include "iostream"
using namespace std;
int a[100005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=0;
	int maxsum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum<0)
		{
			sum=0;
			continue;
		}
		if(maxsum<sum)
			maxsum=sum; 
	}
	cout<<maxsum;
} 
