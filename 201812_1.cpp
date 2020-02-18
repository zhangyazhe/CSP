#include <bits/stdc++.h>
//#define LOCAL
using namespace std;

int main(){
	#ifdef LOCAL
	freopen("data_201812_1.txt", "r", stdin);
	#endif
	int r, y, g, n, type, wait;
	int time = 0;
	cin >> r >> y >> g;
	cin.get();
	cin >> n;
	cin.get();
	for(int i=0; i<n; i++){
		cin >> type >> wait;
		cin.get();
		if(type == 0 || type == 1){
			time +=wait;
		}else if(type == 2){
			time +=wait;
			time +=r;
		}
	}
	cout << time;
}

