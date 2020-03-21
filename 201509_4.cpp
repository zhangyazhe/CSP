#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int dfn[10005],low[10005];
bool vis[10005],ins[10005];
vector<int>E[10005];
int sum,tot;
stack<int>s;
void tarjan(int v)
{
	dfn[v]=low[v]=++tot;
	s.push(v);
	ins[v]=1;
	vis[v]=1;
	for(int i=0;i<E[v].size();i++)
	{
		int vv=E[v][i];
		if(!dfn[vv]){
			tarjan(vv);
			low[v]=min(low[v],low[vv]);
		}
		else if(ins[vv])
		{
			low[v]=min(low[v],dfn[vv]);
		}
	}
	if(dfn[v]==low[v])
	{
		int cnt=0;
		while(1)
		{
			int now=s.top();
			s.pop();
			ins[now]=0;
			vis[v]=0;
			cnt++;
			if(now==v)break;
		}
		if(cnt>1){
			sum+=cnt*(cnt-1)/2;
		}
	}
}
int main()
{
	//memset(ins,0,sizeof(ins));
	//memset(vis,0,sizeof(vis));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		E[a].push_back(b);
	}
	sum=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])tarjan(i);
	}
	cout<<sum<<endl;
	return 0;
}