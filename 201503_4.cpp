#include <bits/stdc++.h>
using namespace std;
const int maxn=20005; //因为n m 相加需要20000
int vis[maxn];
int maxCost,number;

vector <int> G[maxn];
void init()
{
    for(int i=0; i<maxn; i++)
        G[i].clear();
}
void dfs(int u,int cost)
{
    vis[u]=1; //是否通过
    if(maxCost<cost)
    {
        maxCost=cost; //记录最长路径距离 因为有回溯所以需要全局变量
        number=u;  //记录最长距离的最后一个点
    }
    for(int i=0; i<G[u].size(); i++) //对U的每一个邻接点遍历
    {
        if(!vis[G[u][i]])  //若该邻接点未标记，则距离加1，继续递归调用
            dfs(G[u][i],cost+1);
    }
}
int main()
{
    int n,m,x,i;
    cin>>n>>m;
    init();
    for(i=2; i<=n+m; i++)
    {
        cin>>x;
        G[i].push_back(x);//第i个的前一个  机器顺延交换机顺序
        G[x].push_back(i);//无向图
    }
    maxCost=-1;  //每次调用dfs函数时，首先要对最大值初始化为-1，且vis初始化为0
    memset(vis,0,sizeof(vis));//访问变量初始化
    dfs(1,0);
    maxCost=-1;
    memset(vis,0,sizeof(vis));
    dfs(number,0);
    cout<<maxCost<<endl;
    return 0;
}