/*第一行输入n,v为节点个数和边的数目。 之后输入v行，每一行三个数字，分别为边的起点、边的终点、变得狰狞高度边的长度。 
求从0号节点到其他各节点的最短路径*/
#include <iostream>
#include <vector>
#define LOCAL
#define maxnum 1000
using namespace std;

const int INF = 1000000;
int n, v, s;
struct Node{
	int end;//边的目标节点编号
	int dis;//边的长度 
};
vector<Node> adj[maxnum];//每一个vector存放的是第i个节点指向的节点 

void create_graph(){
	#ifdef LOCAL
	freopen("data_Dijkstra.txt","r",stdin);
	#endif
	int temp;
	Node node;
	cin >> n >> v >> s;
	cin.get();
	for(int i=0; i<v; i++){
		cin >> temp;
		cin.get();
		cin >> node.end >> node.dis;
		cin.get();
		adj[temp].push_back(node);
	}
	cout << adj[0].size() << endl;
}

void Dijkstra(int s){
	int dis2s[maxnum];
	for(int i=0; i<maxnum; i++){
		dis2s[i] = INF;
	}
	dis2s[s] = 0;
	int min = INF;
	int u = -1;
	int cnt=n;
	bool select[maxnum];
	for(int i=0; i<maxnum; i++){
		select[i] = false;
	}
	while((cnt--)!=0){
		for(int i=0; i<n; i++){
			if(dis2s[i] < min && select[i] == false){
				u = i;
				min = dis2s[i];
			}
		}
		select[u] = true;
		cout << "u = " << u <<' ' << "min =" << min << endl;
		min = INF;
		for(int j=0; j<adj[u].size(); j++){
			cout << dis2s[adj[u][j].end] << ' ' << dis2s[u]+adj[u][j].dis << endl;
			if(dis2s[adj[u][j].end]> dis2s[u]+adj[u][j].dis){
				dis2s[adj[u][j].end] = dis2s[u]+adj[u][j].dis;
			}
		}
	}
	for(int i=0; i<n; i++){
		cout << dis2s[i] << ' ';
	}	
}

int main(){
	create_graph();
	Dijkstra(s);
	return 0; 
} 
