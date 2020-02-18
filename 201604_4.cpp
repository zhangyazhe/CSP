#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//#define LOCAL

struct trap{
    int x, y, begin, end;
    trap(int a, int b, int c, int d):x(a), y(b), begin(c), end(d){}
};

struct pos{
    int x, y, time;
    pos(int a, int b, int c):x(a), y(b), time(c){}
};

int n, m, t;
int move_x[4] = {0, 0, -1, 1};
int move_y[4] = {1, -1, 0, 0};
vector<trap> vec_trap;

bool walkable(int x, int y, int time){
    if(x >= 1 && x <= m && y >= 1 && y <= n){
        for(int i=0; i<vec_trap.size(); i++){
            if(x == vec_trap[i].x){
                if(y == vec_trap[i].y){
                    if(time >= vec_trap[i].begin){
                        if(time <= vec_trap[i].end){
                            return false;
                        }
                    }
                }
            } 
        }
        return true;
    }
    return false;
}

int bfs(){
    pos temp(1, 1, 0);
    queue<pos> q;
    q.push(temp);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp.x == m && temp.y == n){
            return temp.time;
        }
        for(int i=0; i<4; i++){
            int dx = temp.x + move_x[i];
            int dy = temp.y + move_y[i];
            if(walkable(dx, dy, temp.time + 1)){
                pos new_pos(dx, dy, temp.time + 1);
                q.push(new_pos);
            }
        }
    }
    return 0;
}

int main(){
    #ifdef LOCAL
    freopen("201604_4.txt", "r", stdin);
    #endif
    cin >> n >> m >> t;
    int r, c, a, b;
    for(int i=0; i<t; i++){
        cin >> c >> r >> a >> b;
        trap temp(r, c, a, b);
        vec_trap.push_back(temp);
    }
    cout << bfs();
    return 0;
}