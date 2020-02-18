/*��һ������n,vΪ�ڵ�����ͱߵ���Ŀ�� ֮������v�У�ÿһ���������֣��ֱ�Ϊ�ߵ���㡢�ߵ��յ㡢��������߶ȱߵĳ��ȡ� 
���0�Žڵ㵽�������ڵ�����·��*/
#include <iostream>
#include <vector>
#define LOCAL
#define maxnum 1000
using namespace std;

const int INF = 1000000;
int n, v, s;
struct Node{
	int end;//�ߵ�Ŀ��ڵ���
	int dis;//�ߵĳ��� 
};
vector<Node> adj[maxnum];//ÿһ��vector��ŵ��ǵ�i���ڵ�ָ��Ľڵ� 

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
