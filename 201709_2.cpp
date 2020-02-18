#include <bits/stdc++.h>
using namespace std;
//#define LOCAL

struct Node{
	int type;//1表示取，0表示放回
	int time;
	int num; 
	Node(){}
};

bool cmp(Node a, Node b){
	if(a.time == b.time){
		if(a.type != b.type){
			return a.type < b.type;
		}
		if(a.type == b.type){
			return a.num < b.num;
		}
	}
	return a.time < b.time;
}

int main(){
	#ifdef LOCAL
	freopen("data_201709_2.txt", "r", stdin);
	#endif
	int N, K;
	vector<Node> vec;
	vector<int> key;//0表示已经被取走 
	cin >> N >> K;
	cin.get();
	for(int i=0; i<N; i++){
		//初始化key
		key.push_back(i+1); 
	}
	for(int i=0; i<K; i++){
		Node n1;
		Node n2;
		cin >> n1.num >> n1.time >> n2.time;
		cin.get();
		n2.num = n1.num;
		n2.time += n1.time;
		n1.type = 1;
		n2.type = 0;
		vec.push_back(n1);
		vec.push_back(n2);
	}
	sort(vec.begin(), vec.end(), cmp);
	for(int i=0; i<vec.size(); i++){
		if(vec[i].type == 1){
			for(int j=0; j< key.size(); j++){
				if(key[j] == vec[i].num){
					key[j] = 0;
					break;
				}
			}
		}
		else if(vec[i].type == 0){
			for(int j=0; j<key.size(); j++){
				if(key[j] == 0){
					key[j] = vec[i].num;
					break;
				}
			}
		}
	}
	for(int i=0; i<N; i++){
		cout << key[i];
		if(i != N-1){
			cout << ' ';
		}
	}
}
