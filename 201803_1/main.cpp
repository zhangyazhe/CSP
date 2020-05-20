#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i, score = 0, combo = 0;
    vector<int> jump;
    do{
        cin >> i;
        cin.get();
        jump.push_back(i);
    }while (jump[jump.size() - 1]!=0);
    if(jump[0]==0){
        cout << 0;
        return 0;
    }else if(jump[0] == 1){
        score += 1;
    } else if(jump[0] == 2){
        score += 2;
        combo++;
    }
    for(i = 1; i < jump.size(); i++){
        if(jump[i] == 0){
            break;
        } else if(jump[i] == 1){
            score += 1;
            combo = 0;
        } else if(jump[i] == 2){
            if(combo == 0){
                score +=2;
            } else{
                score = score + 2 * (combo + 1);
            }
            combo++;
        }
    }
    cout << score;
    return 0;
}