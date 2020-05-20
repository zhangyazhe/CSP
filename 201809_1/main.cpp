#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i, temp;
    vector<int> price;
    cin >> n;
    cin.get();
    for(i=0; i<n; i++){
        cin >> temp;
        cin.get();
        price.push_back(temp);
    }
    for(i=0; i<n; i++){
        if(i == 0){
            cout << (price[0]+price[1])/2;
            cout << ' ';
        } else if(i == (n - 1)){
            cout << (price[n-1]+price[n-2])/2;
        } else{
            cout << (price[i]+price[i-1]+price[i+1])/3;
            cout << ' ';
        }
    }
    return 0;
}