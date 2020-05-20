#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
    int s, t;
    int len;
};

int father[100005] = {0};
Edge edges[200005];

int findFather(int a){
    int x = a;
    int old_father;
    while(father[a] != a){
        a = father[a];
    }
    //路径压缩
    old_father = father[x];
    while(old_father != a){
        father[x] = a;
        x = old_father;
        old_father = father[x];
    }
    return a;
}

//将两个集合合并
void unionSet(int a, int b){
    int a_father = findFather(a);
    int b_father = findFather(b);
    if(a_father != b_father){
        father[a_father] = b_father;
    }
}

bool cmp(Edge e1, Edge e2){
    return e1.len < e2.len;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        father[i] = i;
    }
    for(int i=1; i<=m; i++){
        Edge e;
        cin >> e.s >> e.t >> e.len;
        edges[i] = e;
    }
    sort(&edges[1], &edges[m+1], cmp);//注意第二个参数应该是m+1而不是m
    for(int i=1; i<=m; i++){
        unionSet(edges[i].s, edges[i].t);
        if(findFather(1) == findFather(n)){
            cout << edges[i].len;
            return 0;
        }
    }
}