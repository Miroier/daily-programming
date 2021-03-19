#include "bits/stdc++.h"
using namespace std;
int n;
int cnt[5];
queue<int> q;
bool check(int x){
	if(x%7==0)
		return false;
	else{
		while(x){
			if(x%10==7)
				return false;
			x/=10;
		}
	}
	return true;
}
int j;
int main(){
	cin>>n;
	for(int i=1;i<=4;i++)
		q.push(i);
	for(int i=1,j=1;j<=n;i++,j++){
		int x=q.front();
		q.pop();
		if(!check(i))
			cnt[x]++,j--;
		q.push(x);
	}
	for(int i=1;i<=4;i++)
		cout<<cnt[i]<<endl;
} 
