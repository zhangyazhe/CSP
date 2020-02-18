#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
//ʵ���������С����������С�ı�Ȩ
//����Kruskal�㷨
 
struct Edge{
	//����ṹ�壬���а���һ���ߵ����������Լ���Ȩ 
	int u, v, t;
};

vector<Edge> edges;//�������еı�
vector<int> father;//���鼯��������� 

void inputEdge(int n, int m, int root){
	//��ȡ����ıߵ���Ϣ
	for(int i=0; i<m; i++){
		Edge edge;
		cin >> edge.v >> edge.u >> edge.t;
		cin.get();
		edges.push_back(edge);
	}
}

int cmp(Edge a, Edge b){
	//�Խṹ��������ձ�Ȩ��С��������
	return a.t < b.t;
}

int findFather(int a){
	//���鼯Ѱ�Ҹ��ڵ�
	while(father[a] != a){
		a = father[a];
	}
	return a;
}

void Kruskal(int n){
	int T = 0;//�������ṹ��ˮ�ߺ�ʱ 
	int edge_num=0;
	sort(edges.begin(), edges.end(), cmp);//���߰��ձ�Ȩ��С��������
	for(int i=0; i<edges.size(); i++){
		int faV = findFather(edges[i].v);
		int faU = findFather(edges[i].u);
		if(faV != faU){
			father[edges[i].v] = edges[i].u;//���߼��벢�鼯 
			edge_num++;
			if(edges[i].t > T)
				T = edges[i].t; 
			if(edge_num == n-1)//����Ѿ����������ͽ��� 
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
	//��ʼ�����ڲ��鼯�ĸ��ڵ�����
	for(int i=0; i<=n; i++){
		father.push_back(i);
	} 
	inputEdge(n, m, root);
	Kruskal(n);
	return 0;
}
