#include "iostream"
#include "algorithm"
using namespace std;
int n;
string s;
void func(int head,int tail){
	if(head>=tail)
		return;
	swap(s[head],s[tail]);
	cout<<s<<endl;
	func(head+1,tail-1);
}
int main(){
	cin>>n>>s;
	func(0,n-1);
	cout<<endl<<s<<endl;
}
