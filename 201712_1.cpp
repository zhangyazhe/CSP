#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
	int n, temp, min=20000;
	vector<int> num;
	cin >> n;
	cin.get();
	for(int i=0; i<n; i++){
		cin >> temp;
		cin.get();
		num.push_back(temp);
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(abs(num[i]-num[j]) < min){
				min = abs(num[i]-num[j]);
			}
		}
	}
	cout << min;
}
