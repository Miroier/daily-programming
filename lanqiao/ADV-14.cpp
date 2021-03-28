#include "iostream"
#include "map"
#include "set"
using namespace std;
map<string,int> s2i;
map<int,string> i2s;
set<int> in[205];
set<int> out[205];
bool st[205];
int cnt;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		fill(st,st+205,false);
		s2i.clear();
		i2s.clear();
		for(int i=0;i<205;i++)
			in[i].clear();
		for(int i=0;i<205;i++)
			out[i].clear();
		cnt=1;
		for(int i=0;i<n;i++){
			string s1,s2;
			cin>>s1>>s2;
			int x,y;
			if(!s2i[s1]){
				x=cnt++;
				s2i[s1]=x;
				i2s[x]=s1;
			}
			else
				x=s2i[s1];
			if(!s2i[s2]){
				y=cnt++;
				s2i[s2]=y;
				i2s[y]=s2;
			}
			else
				y=s2i[s2];
			out[x].insert(y);
			in[y].insert(x);
		}
		for(int i=1;i<cnt;i++){
			int ind;
			for(int j=1;j<cnt;j++)
				if(in[j].size()==0&&!st[j])
					ind=j,st[j]=true;
			cout<<i2s[ind]<<" ";
			for(set<int>::iterator it=out[ind].begin();it!=out[ind].end();it++)
//				if(in[*it].find(ind)!=in[*it].end())
					in[*it].erase(ind);
		}
		cout<<endl;
	}
}
