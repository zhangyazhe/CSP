#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#define MAXN 210
using namespace std;

struct node
{
    int num;    //���
    int new_router_num; //����·��������
    int length; //·������
    node(int a, int b, int c):num(a), new_router_num(b), length(c){}    //���캯��
};


int N, M, K, R;
bool graph[MAXN][MAXN];	//graph[i][j]��ֵ�����ŵ�i����͵�j����֮���Ƿ��бߣ�����i�������j����֮��ľ����Ƿ�С��r 
int pos[MAXN][2];	//ÿ�д���һ��Ԫ�أ����зֱ���x�����y���� 

bool inRange(int a, int b, int R) {
    return sqrt(pow(pos[a][0]-pos[b][0],2)+pow(pos[a][1]-pos[b][1],2))<=R;
}

int bfs(int s, int t) {
    vector<bool> visited(M+N);	//��¼ĳ����Ƿ񱻷��ʹ� 
    queue<node > q;
    node start(s, 0, 1);
    q.push(start);
    while(!q.empty()) {
        node f = q.front();
        if(f.num == t) return f.length-2;	//�������յ� 
        q.pop();
        for(int i=0; i<N; i++) {	//����������·�����������ѡ��·������һ����� 
            if(graph[f.num][i] && !visited[i]) {
                node temp(i, f.new_router_num, f.length + 1);   //��Ϊ����������·����������f.new_router_num���� 
                q.push(temp);
                visited[i] = true;
            }
        }
        for(int i=N; i<N+M; i++) {	//����������·�����������ѡ��·������һ�����
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
