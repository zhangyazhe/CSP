#include <iostream>
#include <vector>
//#define LOCAL
using namespace std;

char change(char c){
	if(c == 'l')
		return 'r';
	else
		return 'l';
}
int main(){
	#ifdef LOCAL
	freopen("data_201803_2.txt", "r", stdin);
	#endif
	int n, l, t, temp;
	vector<int> v;
	vector<char> dir;
	cin >> n >> l >> t;
	cin.get();
	for(int i=0; i<n; i++){
		cin >> temp;
		cin.get();
		v.push_back(temp);
	}
	//初始化方向
	for(int i=0; i<n; i++){
		dir.push_back('r');
	} 
	for(int i=0; i<t; i++){
		for(int j=0; j<n; j++){
			if(dir[j] == 'r'){
				v[j]++;
			}else{
				v[j]--;
			}
		}
		for(int j=0; j<n; j++){
			if(v[j] == l || v[j] == 0){
				dir[j] = change(dir[j]);
			}
		}
		for(int k=0; k<n-1; k++){
			for(int m=k+1; m<n; m++){
				if(v[k] == v[m]){
					dir[k] = change(dir[k]);
					dir[m] = change(dir[m]);
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		cout << v[i];
		if(i != n-1)
			cout << ' ';
	}
}
