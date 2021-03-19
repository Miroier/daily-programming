#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef long long LL;
int n;
string s;
string a="1";
int pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)
			ans=ans*a;
		a*=a;
		b>>=1;
	}
	return ans; 
}
string num2str(int x){
	int a[10];
	int cnt=0;
	string ans="";
	while(x){
		a[cnt++]=x%10;
		x/=10;
	}
	cnt--;
	for(int i=cnt;i>=0;i--)
		ans+='0'+a[i];
	return ans;
}
LL cnt;
int main(){
	scanf("%d\n",&n);
	cin>>s;
	while(n--){
		string b="";
		for(int i=0;i<a.size();i++){
			int tmp=a[i]-'0';
			tmp=pow(2,tmp);
			b+=num2str(tmp);
		}
		a=b;
		cout<<a.size()<<endl;
	}
	int pos=a.find(s);
	while(pos!=-1){
		cnt++;
		if(cnt==998244353)
			cnt=0;
		pos=a.find(s,pos+1);
	}
	cout<<cnt;
} 
