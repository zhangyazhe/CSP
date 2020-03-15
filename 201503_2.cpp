#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<int, int> mp;

int main(){
    freopen("201503_2.txt", "r", stdin);
    int n, temp;
    map<int, int>::iterator it, it_max;
    vector<pair<int, int> > vec;
    cin >> n;
    int max = 0;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(mp.find(temp) == mp.end()){
            //新来的数字不存在
            mp[temp] = 1;
        }else{
            mp[temp]++;
        }
    }
    while(mp.size() != 0){
        for(it = mp.begin(); it != mp.end(); it++){
            if(it->second > max){
                max = it->second;
                it_max = it;
            }else if(it->second == max){
                if(it_max->first > it->first){
                    it_max = it;
                }
            }
        }
        vec.push_back(make_pair(it_max->first, it_max->second));
        mp.erase(it_max);
        max = 0;
    }
        
    //map中的内容可以按照自定规则排序吗？
    for(int i=0; i<vec.size(); i++){
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    return 0;
}