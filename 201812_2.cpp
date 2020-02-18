#include <iostream>
#include <vector>
#include <stdlib.h>
#define LOCAL
//���׳���ĵ�
//1.������������t��Ҫ�����long longl����
//2.�Ƶƽ����󣬻���Ҫ�����ŵȺ��
//3.С�ĳ�ʱ
using namespace std;
//����ṹ�壬���а������ͺ�ʱ��������Ϣ��
// ���⹹��һ�����������ڼ���ĳһ�����̵ƾ���tʱ�����ʲô���͵ĵ��Լ�ʣ�����ʱ��
typedef struct sig{
    long long type;
    long long time_left;
}sig;
sig next_state(int r, int y, int g, sig p, long long t);
int main() {
#ifdef LOCAL
    freopen("data_201812_2.txt", "r", stdin);
#endif
    int r, y, g, n, i;
    long long t = 0;
    sig p, ret_sig;
    vector<sig> state;
    cin >> r >> y >> g;
    cin.get();
    cin >> n;
    cin.get();
    for(i=0; i<n; i++){
        cin >> p.type >> p.time_left;
        cin.get();
        state.push_back(p);
    }
    for(i=0; i<n; i++){
        p = state[i];
        if(p.type == 0){
            t+=p.time_left;
        } else{
            ret_sig = next_state(r, y, g, state[i], t);
            if(ret_sig.type == 1){
                t+=ret_sig.time_left;
            }else if(ret_sig.type == 2){
            	t+=ret_sig.time_left;
            	t+=r;
			}
        }
    }
    cout << t;
    return 0;
}
sig next_state(int r, int y, int g, sig p, long long t){
    sig ret_sig;
    int time[4];
    time[1]=r;
    time[2]=y;
    time[3]=g;
    ret_sig.type = p.type;
    ret_sig.time_left = p.time_left;
    if(t>r+g+y){
    	t=t%(r+g+y);//important point to optimize the time cost
	}
    ret_sig.time_left-=t;
    if(ret_sig.time_left<0){
        do{
            ret_sig.type--;
            if(ret_sig.type == 0) ret_sig.type=3;
            ret_sig.time_left+=time[ret_sig.type];
        }while (ret_sig.time_left<0);
    }
    return ret_sig;
}

