#include <iostream>
using namespace std;
int main() {
    int arr[] = {3500, 3500+1500, 3500+4500, 3500+9000, 3500+35000, 3500+55000, 3500+80000};
    int fq[] = {3, 10, 20, 25, 30, 35, 45};
    int n = sizeof(arr)/ sizeof(int);
    int price[n];
    int i, p, s;
    price[0] = arr[0];
    for(i=1; i<n; i++){
        price[i] = price[i-1]+(arr[i]-arr[i-1])-(arr[i]-arr[i-1])*fq[i-1]/100;
    }
    cin >> s;
    for(i=0; i<n; i++){
        if(s<=price[i]) break;
    }
    if(i == 0){
        p = s;
    } else{
        p=arr[i-1]+(s-price[i-1])*100/(100-fq[i-1]);
    }
    cout << p;
    return 0;
}