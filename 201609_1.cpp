#include <iostream>

using namespace std;
int main(){
    int n;
    int a, b;
    int cha;
    int max = 0;
    cin >> n;
    cin >> a;
    for(int i=0; i<n-1; i++){
        cin >> b;
        cha = abs(b-a);
        if(max < cha){
            max = cha;
        }
        a=b;
    }
    cout << max;
    return 0;
}