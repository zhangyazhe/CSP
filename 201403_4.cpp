#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#define MAXN 210
using namespace std;

struct node
{
    int num;    //序号
    int new_router_num; //新增路由器数量
    int length; //路径长度
    node(int a, int b, int c):num(a), new_router_num(b), length(c){}    //构造函数
};


int N, M, K, R;
bool graph[MAXN][MAXN];	//graph[i][j]的值代表着第i个点和第j个点之间是否有边，即第i个点与第j个点之间的距离是否小于r 
int pos[MAXN][2];	//每行代表一个元素，两列分别是x坐标和y坐标 

bool inRange(int a, int b, int R) {
    return sqrt(pow(pos[a][0]-pos[b][0],2)+pow(pos[a][1]-pos[b][1],2))<=R;
}

int bfs(int s, int t) {
    vector<bool> visited(M+N);	//记录某结点是否被访问过 
    queue<node > q;
    node start(s, 0, 1);
    q.push(start);
    while(!q.empty()) {
        node f = q.front();
        if(f.num == t) return f.length-2;	//到达了终点 
        q.pop();
        for(int i=0; i<N; i++) {	//不考虑新增路由器的情况下选择路径的下一个结点 
            if(graph[f.num][i] && !visited[i]) {
                node temp(i, f.new_router_num, f.length + 1);   //因为不考虑新增路由器，所以f.new_router_num不变 
                q.push(temp);
                visited[i] = true;
            }
        }
        for(int i=N; i<N+M; i++) {	//仅考虑新增路由器的情况下选择路径的下一个结点
            if(graph[f.num][i] && !visited[i] && f.new_router_num<K) {
                node temp(i, f.new_router_num + 1, f.length + 1);
                q.push(temp);
                visited[i] = true;
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d%d%d", &N, &M, &K, &R);
    for(int i=0; i<N+M; i++) {
        scanf("%d%d", &pos[i][0], &pos[i][1]);
    }
    for(int i=0; i<N+M; i++) {
        for(int j=i+1; j<N+M; j++) {
            graph[i][j] = graph[j][i] = inRange(i, j, R);
        }
    }
    printf("%d", bfs(0, 1));
}
