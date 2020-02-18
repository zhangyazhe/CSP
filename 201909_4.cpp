#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#define LOCAL

using namespace std;
int hasSelected[51][30001] = {0};
int main(){
    #ifdef LOCAL
        freopen("201909_4.txt", "r", stdin);
    #endif
    int m, n, opnum, commodity, score, op, type, K, k_num;
    int max_st_no, max_commodity, max_score = -1;
    int all_vec_zero_flag = 1;
    cin >> m >> n;
//    int hasSelected[51][30001] = {0};
    set<pair<int, int> > st[51];
    set<pair<int, int> >::iterator st_it;
    set<int> st_result[51];
    set<int>::iterator st_it2;
    for(int i=0; i<n; i++){
        cin >> commodity >> score;
        for(int j=0; j<m; j++){
            //将pair加入到每一类商品的集合中
            st[j].insert(make_pair(commodity, score));
        }
    }
    cin >> opnum;
    for(int i=0; i<opnum; i++){
        cin >>op;
        switch (op)
        {
        case 1:
            cin >> type >> commodity >> score;
            st[type].insert(make_pair(commodity, score));
            break;
        case 2:
            cin >> type >> commodity;
            st[type].erase(st[type].lower_bound(make_pair(commodity, 0)));
            break;
        case 3:
            vector<int> vec;
            cin >>K;
            for(int j=0; j<m; j++){
                cin >> k_num;
                vec.push_back(k_num);
            }
            while(K){
                K--;
                all_vec_zero_flag = 1;
                for(int j=0; j<m; j++){
                    if(vec[j] != 0){
                        all_vec_zero_flag = 0;
                        for(st_it=st[j].begin(); st_it != st[j].end(); st_it++){
                            if(st_it->second > max_score && hasSelected[j][st_it->first] == 0){
                                max_score = st_it->second;
                                max_st_no = j;
                                max_commodity = st_it->first;
                            }
                        }
                    }
                }
                if(all_vec_zero_flag == 0){
                    hasSelected[max_st_no][max_commodity] = 1; 
                }
                max_score = -1;
                vec[max_st_no]--;
                st_result[max_st_no].insert(max_commodity);
                if(all_vec_zero_flag == 1) break;
            }
            //将hasSelected复原
           memset(hasSelected, 0, sizeof(hasSelected));
            //输出结果
            for(int j=0; j<m; j++){
                if(st_result[j].size() == 0){
                    cout << -1 << endl;
                }else{
                    for(st_it2 = st_result[j].begin(); st_it2 != st_result[j].end(); st_it2++){
                        cout << *st_it2 << ' ';
                    }
                    cout << endl;
                }
            }
            //st_result复原
            for(int j=0; j<m; j++){
                st_result[j].clear();
            }
            vec.clear();
            break;
        }
    }
    return 0;
}
