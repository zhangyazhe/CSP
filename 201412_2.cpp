#include <iostream>

using namespace std;

int n;

bool inRange(int x, int y){
    if(x>=0 && x<n && y>=0 && y<n){
        return true;
    }else
    {
        return false;
    }
    
}

int main(){
    freopen("201412_2.txt", "r", stdin);
    int G[505][505];
    int flag = 0;
    int x=0, y=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> G[j][i];
        }
    }
    if(x == n-1 && y == n-1){
        cout << G[x][y]<< ' ';
        return 0;
    }
    cout << G[x][y];
    while(1){
        x++;
        if(!inRange(x, y)){
            flag = 0;
            x--;
            break;
        }
        cout << G[x][y]<< ' ';
        while(1){
            x--;
            y++;
            if(inRange(x, y)){
                cout << G[x][y]<< ' ';
            }else
            {
                x++;
                y--;
                break;
            }
        }
        y++;
        if(!inRange(x, y)){
            flag = 1;
            y--;
            break;
        }
        cout << G[x][y]<< ' ';
        while(1){
            x++;
            y--;
            if(inRange(x, y)){
                cout << G[x][y] << ' ';
            }else
            {
                x--;
                y++;
                break;
            }
        }
    }
    return 0;
    if(flag == 1){
        while(1){
            x++;
            if(x == n-1 && y == n-1){
                cout << G[x][y]<< ' ';
                break;
            }
            cout << G[x][y]<< ' ';
            while(1){
                x++;
                y--;
                if(inRange(x, y)){
                cout << G[x][y]<< ' ';
                }else{
                    x--;
                    y++;
                    break;
                }
            }
            y++;
            cout << G[x][y]<< ' ';
            while(1){
                x--;
                y++;
                if(inRange(x, y)){
                    cout << G[x][y]<< ' ';
                }else{  
                    x++;
                    y--;
                    break;
                }
            }
        }   
    }else if(flag == 0){
        while(1){
            y++;
            cout << G[x][y]<< ' ';
            while(1){
                x--;
                y++;
                if(inRange(x, y)){
                cout << G[x][y]<< ' ';
                }else{
                    x++;
                    y--;
                    break;
                }
            }
            x++;
            if(x == n-1 && y == n-1){
                cout << G[x][y]<< ' ';
                break;
            }
            cout << G[x][y]<< ' ';
            while(1){
                x++;
                y--;
                if(inRange(x, y)){
                    cout << G[x][y]<< ' ';
                }else{  
                    x--;
                    y++;
                    break;
                }
            }
        } 
    }
    return 0;
}