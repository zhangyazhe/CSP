#include <iostream>
#include <vector>
//#define LOCAL
using namespace std;

const int maxn = 550;
const int inf = 200000;

int n, m, c;
struct Node{
	int t;
	int v;//所链接的节点的编号
	int c;
};
vector<vector<Node>> adj;
bool vis[maxn] = {false};

int pow(int a){
	return a*a;
}

void create_graph(){
	#ifdef LOCAL
	freopen("data_201712_4.txt", "r", stdin);
	#endif
	int t, c, v, v1;
	cin >> n >> m;
	cin.get();
	for(int i=0; i<n; i++){
		vector<Node> nd;
		adj.push_back(nd);
	}
	Node node,node1;
	for(int i=0; i<m; i++){
		//双向道路 
		cin >> t >> v1 >> v >> c;
		cin.get();
		node1.t = node.t = t;
		node1.c = node.c = c;
		node1.v = v1-1;
		node.v = v-1;
		adj[v1-1].push_back(node);
		adj[v-1].push_back(node1);
	}
}

void Dijkstra(){
	int u = -1;
	int min = inf;
	vector<int> pre_trail;
	vector<int> tired;
	for(int i=0; i<n; i++){
		tired.push_back(inf);
		pre_trail.push_back(0);
	}
	tired[0] = 0;
	pre_trail[0] = 0;
	int cnt = n;
	while((cnt--)!=0){
	for(int i=0; i<n; i++){
		if(tired[i] < min && vis[i] == false){
			u = i;
			min = tired[i];
		}
	}
	vis[u] = true;
	min = inf;
	for(int i=0; i<adj[u].size(); i++){
		if(adj[u][i].t == 0){
			//大道
			pre_trail[adj[u][i].v] = 0;
			if(tired[u] + adj[u][i].c < tired[adj[u][i].v])
				tired[adj[u][i].v] = tired[u] + adj[u][i].c;
			} else{
				//小道
				pre_trail[adj[u][i].v] = pre_trail[u] + adj[u][i].c;
				if(tired[u] + pow(pre_trail[adj[u][i].v]) - pow(pre_trail[u]) < tired[adj[u][i].v]) {
					tired[adj[u][i].v] = tired[u] + pow(pre_trail[adj[u][i].v]) - pow(pre_trail[u]);
				}
			}
		}
}
		cout << tired[n-1] ;
}

int main(){
	create_graph();
	Dijkstra();
	return 0;
}
