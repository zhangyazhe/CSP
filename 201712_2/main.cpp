#include <iostream>
#include <vector>
using namespace std;

int isQuitNum(int i, int k);
int main() {
    int n, k, i, j = 0;
    vector<int> alive;//alive中是还没有被淘汰的小朋友的编号
    cin >> n >> k;
    for(i=1; i<=n; i++){
        alive.push_back(i);
    }
    for(i=1; ;i++){//i在此处表示小朋友报的数
        if(isQuitNum(i, k)){
            alive.erase(alive.begin()+j);
        } else{
            j++;
        }
        if(alive.size() == 1){
            break;
        }
        if(j == alive.size()){
            j = 0;
        }
    }
    cout << alive[0];
    return 0;
}
int isQuitNum(int i, int k){
    int ret;
    if(!(i % k) || (i % 10)==k){
        ret = 1;
    } else{
        ret = 0;
    }
    return ret;
}