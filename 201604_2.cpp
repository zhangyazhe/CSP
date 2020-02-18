#include <iostream>
#include <vector>
//#define LOCAL

using namespace std;

int map[15][10];
int block[4][4];
vector<int> line;//四个方块的坐标
vector<int> col;
int icol;

int main(){
    #ifdef LOCAL
        freopen("201604_2.txt", "r", stdin);
    #endif
    int dline=0;
    for(int i=0; i<15; i++){
        for(int j=0; j<10; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> block[i][j];
            if(block[i][j] == 1){
                line.push_back(i);
                col.push_back(j);
            }
        }
    }
    cin >> icol;
    while(map[dline+line[0]+1][col[0]+icol-1]^block[line[0]][col[0]] && map[dline+line[1]+1][col[1]+icol-1]^block[line[1]][col[1]] && map[dline+line[2]+1][col[2]+icol-1]^block[line[2]][col[2]] && map[dline+line[3]+1][col[3]+icol-1]^block[line[3]][col[3]]){
        dline++;
        if(dline+line[0]==14 || dline+line[1]==14 || dline+line[2]==14 || dline+line[3]==14) break;
    }
    for(int i=0; i<4; i++){
        map[dline+line[i]][col[i]+icol-1] = 1;
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<10; j++){
            cout << map[i][j] << ' ';
            if(j == 9) cout << endl;
        }
    }
    return 0;
}