//孩子兄弟表示法的二叉树 
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#define LOCAL
using namespace std;

struct Line{
	int line_num;//行号 
	int blank;//空格数 
	string lable;
	string chara;//属性 
	Line* left;
	Line* right;
};

int n, m;

Line* create_tree(){
	stringstream ss;
	string str, str_lable, str_chara;
	queue<Line*> queue;
	vector<Line*> v;
	Line* q;
	int dot_num;
	cin >> n >> m;
	cin.get();
	for(int i=0; i<n; i++){
		//Line *p = (Line*)malloc(sizeof(Line));
		Line *p = new Line;
		getline(cin, str);
		p->blank = count(str.begin(), str.end(), '.');
		p->line_num = i+1;
		p->left = nullptr;
		p->right = nullptr;
		str.erase(0,p->blank);//将句号删除
		if(count(str.begin(), str.end(), '#')!=0){
			//存在标签属性
			ss << str;
			ss >> str_lable >> str_chara;
			p->lable = str_lable;
			p->chara = str_chara;
		} else{
			//不存在标签属性
			p->lable = str;
			p->chara = "0";
		}
		queue.push(p);
	}
	Line *root = queue.front();
	dot_num = 0;
	v.push_back(root);
	queue.pop();
	Line *p;
	for(int i=0; i<n-1; i++){
		p = queue.front();
		queue.pop();
		if(p->blank > dot_num){
			//是孩子
			root->left = p;
			dot_num = p->blank;
			root = p;
		}else if(p->blank == dot_num){
			//是兄弟
			q=root;
			while(q->right != NULL){
				q = q->right;
			}
			q->right = p;
			root = q->right;
		}else{
			//是新的子树
			dot_num = p->blank;
			root = p;
			v.push_back(p); 
		}
	}
	for(int i=v.size()-1; i>0; i--){
		dot_num = v[i]->blank;
		p = v[i-1];
		while(p->blank != dot_num){
			p = p->left;
		}
		while(p->right!=NULL){
			p=p->right;
		}
		p->right = v[i];
	}
	return v[0];
}

void find(Line* root){
	string str;
//	for(int i=0; i<m; i++){
//		getline(cin, str);
//		
//	}
	//先根遍历
	cout << "mid: " << root->lable << endl;
	if(root->left != nullptr)
		cout << "left: " << root->left->lable <<endl;
	else
		cout << "left: "<< endl;
	if(root->right!= nullptr)
		cout << "right: " << root->right->lable <<endl << endl;
	else
		cout << "right: "<< endl << endl;
	if(root->left != nullptr)
		find(root->left);
	if(root->right!= nullptr)
		find(root->right); 
}

int main(){
	#ifdef LOCAL
	freopen("data_201809_3.txt", "r", stdin);
	#endif
	Line *root = create_tree();
	find(root);
	return 0;
}
