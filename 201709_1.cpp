#include <iostream>
using namespace std;
int main(){
	int n, b=0, i;
	cin >> n;
	cin.get();
	n/=10;
	i = n/5;
	b+=7*i;
	n-=5*i;
	i=n/3;
	b+=i*4;
	n-=i*3;
	b+=n;
	cout << b;
}
