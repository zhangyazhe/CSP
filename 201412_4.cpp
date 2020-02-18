#include <iostream>
#include <algorithm>
#define MAXN 1010
#define INF 1000000

using namespace std;

int G[MAXN][MAXN];
int d[MAXN];    //借调到集合S的最短距离
bool vis[MAXN] = {false};   //  记录是否被访问

int prim(int n){ //默认以第一个节点作为起点
    int ans = 0;
    fill(d, d+MAXN, INF);   //注意：fill的第一个和第二个参数应该是指针，所以不要写成了d[0]
    d[0] = 0;
    for(int i=0; i<n; i++){
        int min_n = -1, min = INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < min){
                min = d[j];
                min_n = j;
            }
        }
        if(min_n == -1){    //注意:这个判断在这道题中似乎是不需要的，但是规范的prim算法应该需要这个判断，当给出的图不是一个连通分量的时候应该返回-1
            return -1;
        }
        ans += min;
        vis[min_n] = true;
        for(int j=0; j<MAXN; j++){
            if(G[min_n][j] < d[j] && vis[j] == false){
                d[j] = G[min_n][j];
            }
        }
    }
    return ans;
}

int main(){
    int n, m, a, b, c;
    cin >> n >> m;
    fill(G[0], G[0]+MAXN*MAXN, INF);
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        //注意：题目给出的节点的序号是从1开始的，而我们的数组是从0开始，所以需要减一
        //注意：给G[a-1][b-1]赋值后不要忘记给G[b-1][a-1]赋值，我一开始就忘了=_=
        G[a-1][b-1] = c;
        G[b-1][a-1] = c;
    }
    cout << prim(n);
    return 0;
}