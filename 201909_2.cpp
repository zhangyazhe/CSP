#include <iostream>
#include <vector>
//#define LOCAL

using namespace std;

int main(){
    #ifdef LOCAL
        freopen("201909_2.txt", "r", stdin);
    #endif
    int N;
    int sum = 0;
    int num = 0;//当前树上的苹果数量
    int opnum = 0;//对某一棵树的操作次数
    int op;
    int dropnum = 0;
    int triple = 0;
    vector<bool> hasDropped;
    cin >> N;
    for(int i=0; i<N; i++){
        hasDropped.push_back(false);
    }
    for(int i=0; i<N; i++){
        cin >> opnum >> num;
        for(int j=1; j<opnum; j++){
            cin >> op;
            if(op > 0){
                if(op != num){
                    hasDropped[i] = true;
                    num = op;
                }
            }else if(op <= 0){
                num += op;
            }
        }
        sum += num;
    }
    cout << sum << ' ';
    for(int i=0; i<hasDropped.size(); i++){
        if(hasDropped[i] == true){
            dropnum++;
        }
    }
    cout << dropnum << ' ';
    for(int i=0; i<N; i++){
        if(hasDropped[i] == false) continue;
        if(hasDropped[(i+1)%N] == true && hasDropped[(i+N-1)%N] == true) triple++;
    }
    cout <<triple;
}