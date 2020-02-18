#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
//#define LOCAL
using namespace std;

struct Node{
	int time;
	int isend;
	char person;
};

int cmp(Node a, Node b){
	return a.time < b.time;
}

int main(){
	#ifdef LOCAL
	freopen("data_201809_2.txt", "r", stdin);
	#endif
	int n;
	int chat = 0;
	bool h_loading = false, w_loading = false;
	stack<Node> s;
	vector<Node> v;
	cin >> n;
	cin.get();
	Node node1,node2;
	for(int i=0; i<n; i++){
		node1.isend = 0;
		node2.isend = 1;
		node1.person = 'h';
		node2.person = 'h';
		cin >> node1.time >>node2.time;
		cin.get();
		v.push_back(node1);
		v.push_back(node2);
	}
	for(int i=0; i<n; i++){
		node1.isend = 0;
		node2.isend = 1;
		node1.person = 'w';
		node2.person = 'w';
		cin >> node1.time >>node2.time;
		cin.get();
		v.push_back(node1);
		v.push_back(node2);
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i<n*4; i++){
		if(v[i].isend == 0){
			if(v[i].person == 'h'){
				h_loading = true;
			}else{
				w_loading = true;
			}
			//cout << v[i].time << endl;
			s.push(v[i]);
		}else{
			if(h_loading && w_loading){
				chat+=v[i].time - s.top().time;
				s.pop();
			}else{
				s.pop();
			}
			if(v[i].person == 'h'){
				h_loading = false;
			}else{
				w_loading = false;
			}
		}
	}
	cout << chat;
}
