#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, n, i, j, k, flag, end, local_match;
    char temp1, temp2;
    int ptr[70000];
    vector<string> str;
    string temp;
    cin >> T >> n;
    cin.get();
    //初始化ptr
    for(i=0; i<n*T; i++){
        ptr[i] = 0;
    }
    //输入字符串
    for(i=0; i<T; i++){
        for(j=0; j<n; j++){
            getline(cin, temp);
            str.push_back(temp);
        }
    }

    for (k=0; k<T; k++) {
        flag = 1;
        end = 1;
        while (end !=0 && flag !=0) {
            end = 0;
            local_match = 0;
            for(i=0+k*n; i<n*(k+1) && end == 0; i++){
                for(j=0+k*n; j<n*(k+1); j++){
                    if(j == i){
                        continue;
                    } else{
                        if(str[i][ptr[i]] == str[j][ptr[j]]){
                            continue;
                        } else{
                            temp1 = str[i][ptr[i]+1];
                            temp2 = str[j][ptr[j]+1];
                            if((temp1-'0') == j - k * n && (temp2-'0') == i - k * n){
                                //匹配成功
                                //cout << "匹配成功" << endl;
                                ptr[i]+=3;
                                ptr[j]+=3;
                                if((str[i].size()<ptr[i])&&(str[j].size()<ptr[j])){
                                    local_match = 1;
                                }
                                end = 1;
                                break;
                            }
                        }
                    }
                }
            }
            //若结束上面的两重for循环时，end为0，表示已经死锁
            //判断是否已经完全匹配,若flag为0，则完全匹配
            if (local_match == 1) {
                for(i=0+k*n; i<n*(k+1); i++){
                    if(str[i].size()>ptr[i]){
                        flag = 1;
                        break;
                    }
                    flag = 0;
                }
            }
        }
        //cout << "end = " << end << endl;
        if(flag == 0){
            cout << 0 << endl;
        } else if(end == 0){
            cout << 1 << endl;
        }
    }
    return 0;
}