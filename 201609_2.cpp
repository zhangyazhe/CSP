#include <iostream>

using namespace std;

bool vis[20][5] = {false};    //标志座位是否已经有人
int isfree[20];
int n, p;

void find(int p){
    for(int i=0; i<20; i++){
        if(isfree[i] >= p){
            isfree[i] -= p;
            for(int j=0; j<5; j++){
                if(vis[i][j] == true)continue;
                for(int k=0; k<p; k++){
                    cout << i*5+j+k+1 << ' ';
                    vis[i][j+k] = true;
                }
                cout << endl;
                return;
            }
        }
    }
    //未找到连续的
    int cnt = 0;
    for(int i=0; i<20; i++){
        for(int j=0; j<5; j++){
            if(vis[i][j] == false){
                cout << i*5+j+1 << ' ';
                vis[i][j] = true;
                cnt++;
                if(cnt == p){
                    cout << endl;
                    return;
                }
            }
        }
    }
}

int main(){
    for(int i=0; i<20; i++){
        isfree[i] = 5;
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p;
        find(p);
    }
    return 0;
}