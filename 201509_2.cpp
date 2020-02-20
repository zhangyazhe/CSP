#include <iostream>

using namespace std;

int y, d;

bool isLeapyear(int y){
    if((y % 4 == 0 && y % 100 !=0) || (y % 400 == 0)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cin >> y >> d;
    int leapday[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int unleapday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = 1;
    if(isLeapyear(y)){
        for(int i=0; i<12; i++){
            if(d > leapday[i]){
                month++;
                d -= leapday[i];
            }else{
                cout << month << endl << d;
                break;
            }
        }
    }
    if(!isLeapyear(y)){
        for(int i=0; i<12; i++){
            if(d > unleapday[i]){
                month++;
                d -= unleapday[i];
            }else{
                cout << month << endl << d;
                break;
            }
        }
    }
    return 0;
}