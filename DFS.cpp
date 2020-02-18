#include <iostream>
#define LOCAL
using namespace std;
const int maxn = 100;

int n, v;
int maxvalue = 0;
int w[maxn];
int c[maxn];
void DFS(int index, int sumw, int sumc){
	if(index == n){
		if(sumw <= v && sumc > maxvalue){
			maxvalue = sumc;
		}
		return;
	}
	DFS(index+1, sumw, sumc);
	DFS(index+1, sumw+w[index], sumc+c[index]);
}

int main(){
	#ifdef LOCAL
	freopen("data_DFS.txt", "r", stdin);
	#endif
	cin >> n >> v;
	cin.get();
	for(int i=0; i<n; i++){
		cin >> w[i];
		cin.get();
	}
	for(int i=0; i<n; i++){
		cin >> c[i];
		cin.get();
	}
	DFS(0, 0, 0);
	cout << maxvalue;
	return 0;
}
