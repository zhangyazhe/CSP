#include <iostream>

using namespace std;

int m, n;
int map[30][30] = {0};
int eliminate[30][30] = {0};

int main(){
    int combo = 1, last, now;
    //freopen("201512_2.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            last = map[i][j-1];
            now = map[i][j];
            if(now == last){
                combo++;
                if(combo >= 3 && j == m-1){
                    for(int k=0; k<combo; k++){
                        eliminate[i][j-k] = 1;
                    }
                }
            }else{
                if(combo >= 3){
                    for(int k=1; k<=combo; k++){
                        eliminate[i][j-k] = 1;
                    }
                }
                combo = 1;
            }
        }
        combo = 1;
    }
    for(int j=0; j<m; j++){
        for(int i=1; i<n; i++){
            last = map[i-1][j];
            now = map[i][j];
            if(now == last){
                combo++;
                if(combo >= 3 && i == n-1){
                    for(int k=0; k<combo; k++){
                        eliminate[i-k][j] = 1;
                    }
                }
            }else{
                if(combo >= 3){
                    for(int k=1; k<=combo; k++){
                        eliminate[i-k][j] = 1;
                    }
                }
                combo = 1;
            }
        }
        combo = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(eliminate[i][j] == 1) cout << 0 << ' ';
            else cout << map[i][j] << ' ';
            if(j == m-1) cout << endl;
        }
    }
    return 0;
}