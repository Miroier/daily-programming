#include "iostream"
#include "sstream"
#include "map"
#include "vector"
using namespace std;
vector<pair<string,int> >v;
int main(){
	int maxlen=0;
	string str;
	getline(cin,str);
	str=" "+str+" ";
	for(int i=0;i<str.size();i++)
		if(str[i]==','||str[i]=='.')
			str[i]=' ';
	for(int i=0;i<str.size();i++)
		if(str[i]>='a'&str[i]<='z')
			str[i]-=32;
	stringstream ssin(str);
	while(ssin>>str){
		if(maxlen<str.size())
			maxlen=str.size();
		int ind=0;
		for(ind=0;ind<v.size();ind++)
			if(v[ind].first==str)
				break;
		if(ind==v.size())
			v.push_back({str,1});
		else
			v[ind].second++;
	}
	cout<<maxlen<<endl;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<maxlen-v[i].first.size();j++)
			cout<<" ";
		cout<<v[i].first<<":";
		for(int j=0;j<v[i].second;j++)
			cout<<"*";
		cout<<v[i].second<<endl; 
	}
}
