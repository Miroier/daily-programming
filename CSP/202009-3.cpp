#include "bits/stdc++.h"
using namespace std;
int q;
int m, n;
int s;
bool input[10005][2505]; //10005是运行次数，2505是输入数量
int ques[10005][505];	 //ques[0]代表输出的信号数量,505是器件数量
struct gate
{
	string name;
	int k;
	string input[10];
};
bool ind[505], ans[505]; //记忆化搜索 
gate g[505]; //505是器件数量，也是输出数量
int cnt;
int stoi(string s)
{
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		num = num * 10 + s[i] - '0';
	}
	return num;
}
bool vis[505];
bool flag=true; //判断有无环 
bool dfs(int x)
{
	if(vis[x])
	{
		flag=false;
		return 0;
	}
	if(ind[x]){
		return ans[x]; 
	} 
	vis[x]=true;
	bool res;
	if (g[x].name == "NOT")
	{
		string tmp = g[x].input[1];
		tmp.erase(tmp.begin());
		int number = stoi(tmp);
		if (g[x].input[1][0] == 'I')
			res = !input[cnt][number];
		if (g[x].input[1][0] == 'O')
			res = !dfs(number);
	}
	else if (g[x].name == "AND")
	{
		res = true;
		for (int i = 1; i <= g[x].k; i++)
		{
			string tmp = g[x].input[i];
			tmp.erase(tmp.begin());
			int number = stoi(tmp);
			if (g[x].input[i][0] == 'I')
				res &= input[cnt][number];
			if (g[x].input[i][0] == 'O')
				res &= dfs(number);
		}
	}
	else if (g[x].name == "NAND")
	{
		res = true;
		for (int i = 1; i <= g[x].k; i++)
		{
			string tmp = g[x].input[i];
			tmp.erase(tmp.begin());
			int number = stoi(tmp);
			if (g[x].input[i][0] == 'I')
				res &= input[cnt][number];
			if (g[x].input[i][0] == 'O')
				res &= dfs(number);
		}
		res = !res;
	}
	else if (g[x].name == "OR")
	{
		res = false;
		for (int i = 1; i <= g[x].k; i++)
		{
			string tmp = g[x].input[i];
			tmp.erase(tmp.begin());
			int number = stoi(tmp);
			if (g[x].input[i][0] == 'I')
				res |= input[cnt][number];
			if (g[x].input[i][0] == 'O')
				res |= dfs(number);
		}
	}
	else if (g[x].name == "NOR")
	{
		res = false;
		for (int i = 1; i <= g[x].k; i++)
		{
			string tmp = g[x].input[i];
			tmp.erase(tmp.begin());
			int number = stoi(tmp);
			if (g[x].input[i][0] == 'I')
				res |= input[cnt][number];
			if (g[x].input[i][0] == 'O')
				res |= dfs(number);
		}
		res = !res;
	}
	else if (g[x].name == "XOR")
	{
		res = false;
		for (int i = 1; i <= g[x].k; i++)
		{
			string tmp = g[x].input[i];
			tmp.erase(tmp.begin());
			int number = stoi(tmp);
			if (g[x].input[i][0] == 'I')
				res ^= input[cnt][number];
			if (g[x].input[i][0] == 'O')
				res ^= dfs(number);
		}
	}
	vis[x] = false;
	ind[x] = true;
	ans[x] = res;
	return res;
}
void check(){
	for (int i=1;i<=n;i++){
		memset(ind,0,sizeof(ind)); //删掉这句会错，原因不明 
		dfs(i);
	}
}
void work()
{
	flag=true;
	check();
	if(!flag){
		cout<<"LOOP"<<endl;
		return;
	}
	for (cnt = 1; cnt <= s; cnt++){
		memset(ind,0,sizeof(ind));
		for (int i = 1; i <= ques[cnt][0]; i++){
			cout << dfs(ques[cnt][i]) << (i < ques[cnt][0] ? ' ' : '\n');
		}
	}
}
void inp()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i].name;
		cin >> g[i].k;
		for (int j = 1; j <= g[i].k; j++)
			cin >> g[i].input[j];
	}
	cin >> s;
	for (int i = 1; i <= s; i++)
		for (int j = 1; j <= m; j++)
			cin >> input[i][j];
	for (int i = 1; i <= s; i++)
	{
		cin >> ques[i][0];
		for (int j = 1; j <= ques[i][0]; j++)
		{
			cin >> ques[i][j];
		}
	}
}
int main()
{
	cin >> q;
	while (q--)
	{
		inp();
		work();
	}
}
