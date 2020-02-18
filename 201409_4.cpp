#include<cstdio>
#include<queue>
using namespace std;
 
const int MAX_SIZE = 1000;
 
struct point_info{
	int x,y;
	long long step;
};
 
bool Legal(int x,int y,int n){
	if(x<1||x>n||y<1||y>n)
		return false;
	return true;
}
 
long long customer_need[MAX_SIZE+1][MAX_SIZE+1] = {0LL};//记录一个点所有顾客的总需求 
int customers[MAX_SIZE+1][MAX_SIZE+1] = {0};//记录同一点有几个顾客 
 
int main(){
	int n,m,k,d,x,y;
	long long ans = 0,value;
	queue<point_info> q;
	bool ban[MAX_SIZE+1][MAX_SIZE+1] = {false}; //  不能走的位置
	point_info front,t;
	const int move[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	
	scanf("%d %d %d %d",&n,&m,&k,&d);
	
	while(m--){
        //初始化时，将所有的起点全部入队列
		point_info start;
		start.step = 0LL;
		scanf("%d %d",&start.x,&start.y);
		ban[start.x][start.y] = true;   //餐厅的位置不能走
		q.push(start);
	}
	
	for(int i=0;i<k;i++){
        //同一个位置不论有多少客户或者多少需求，都一定是由距离最近的那个餐厅进行配送，所以直接将需求加在一起就行
		scanf("%d %d %lld",&x,&y,&value);
		customer_need[x][y] += value;
		customers[x][y]++; 
	}
	
	while(d--){
		scanf("%d %d",&x,&y);
		ban[x][y] = true;
	}
	
	while(!q.empty()){
		front = q.front();
		q.pop();
		
		if(customer_need[front.x][front.y]!=0LL){
			k -= customers[front.x][front.y];
			ans += front.step * customer_need[front.x][front.y];
			if(k==0)
				break;
		}
		
		for(int i=0;i<4;i++){
			x = front.x+move[i][0];
			y = front.y+move[i][1];
			if(Legal(x,y,n)&&!ban[x][y]){
				t.x = x;
				t.y = y;
				t.step = front.step + 1;
				ban[x][y] = true;
				q.push(t);
			}
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
}