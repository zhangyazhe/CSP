#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
//实质是求出最小生成树的最小的边权
//采用Kruskal算法
 
struct Edge{
	//定义结构体，其中包含一条边的两个顶点以及边权 
	int u, v, t;
};

vector<Edge> edges;//储存所有的边
vector<int> father;//并查集父结点数组 

void inputEdge(int n, int m, int root){
	//读取输入的边的信息
	for(int i=0; i<m; i++){
		Edge edge;
		cin >> edge.v >> edge.u >> edge.t;
		cin.get();
		edges.push_back(edge);
	}
}

int cmp(Edge a, Edge b){
	//对结构体变量按照边权从小到大排序
	return a.t < b.t;
}

int findFather(int a){
	//并查集寻找父节点
	while(father[a] != a){
		a = father[a];
	}
	return a;
}

void Kruskal(int n){
	int T = 0;//最优树结构流水线耗时 
	int edge_num=0;
	sort(edges.begin(), edges.end(), cmp);//将边按照边权从小到大排序
	for(int i=0; i<edges.size(); i++){
		int faV = findFather(edges[i].v);
		int faU = findFather(edges[i].u);
		if(faV != faU){
			father[edges[i].v] = edges[i].u;//将边加入并查集 
			edge_num++;
			if(edges[i].t > T)
				T = edges[i].t; 
			if(edge_num == n-1)//如果已经构成了树就结束 
				break;
		}
	}
	cout << T; 
}

int main(){
	int n, m, root;
	cin >> n;
	cin.get(); 
	cin >> m;
	cin.get(); 
	cin >> root;
	cin.get();
	//初始化用于并查集的父节点数组
	for(int i=0; i<=n; i++){
		father.push_back(i);
	} 
	inputEdge(n, m, root);
	Kruskal(n);
	return 0;
}
