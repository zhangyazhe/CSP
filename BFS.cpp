/*��������:����һ��m*n�ľ��󡣾����е�Ԫ��Ϊ0��1���ƣ�x��y��������������
*�ĸ�λ�� �����ڵġ���������������ɸ�1�����ڵģ������������ڣ�����ô 
*����Щ1������һ���顣����������п�ĸ��� 
*/ 
#include <iostream>
#include <queue>
#define LOCAL
const int maxn = 100;
using namespace std;

int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn];
struct Node{
	int x;
	int y;
};

bool judge(int x, int y){
	if(x>=n || x<0 || y>=m || y<0)
		return false;
	if(matrix[x][y] == 0 || inq[x][y] == true)
		return false;
	return true;
} 

int main(){
	//bool inq[maxn][maxn] = {false};
	#ifdef LOCAL
	freopen("data_BFS.txt", "r", stdin);
	#endif
	int i, j, k, newx, newy, cnt=0;
	Node node;
	queue<Node> q;
	int plusx[4] = {0, 0, 1, -1};
	int plusy[4] = {1, -1, 0, 0};
	cin >> n >> m;
	cin.get();
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cin >> matrix[i][j];
			cin.get();
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(judge(i, j)){
				cnt++;
				node.x = i;
				node.y = j;
				q.push(node);
				while(!q.empty()){
					Node top = q.front();
					q.pop();
					for(k=0; k<4; k++){
						newx = top.x + plusx[k];
						newy = top.y + plusy[k];
						node.x = newx;
						node.y = newy;
						if(judge(newx, newy)){
							q.push(node);
							inq[node.x][node.y] = true;
						}
					}
				}
			}
		}
	}
	cout << cnt;
}
