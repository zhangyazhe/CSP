#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define LOCAL

using namespace std;

struct ROLE{
    int health;
    int attack;
    ROLE(){health = 0; attack = -1;}
};

struct PLAYER{
    //ROLE hero;
    //ROLE servant[8];
    vector<ROLE> servant;
    //int num;
    //PLAYER():num(0){servant[0].attack = 0;servant[0].health = 30;}
};

PLAYER player[2];
//vector<ROLE> player[2];
int n;

void run(){
    string s;
    int op = 0;
    ROLE hero;
    hero.attack = 0;
    hero.health = 30;
    player[0].servant.push_back(hero);
    player[1].servant.push_back(hero);
    cin >> n;
    getchar();
    while(n--){
        getline(cin,s);
        if(s[0] == 'e')
            op ^= 1;
        else if(s[0] == 's'){
            stringstream ss(s);
            int p,a,h;
            ss >> s >>p >>a>>h;
            ROLE temp;
            temp.attack = a;
            temp.health = h;
            player[op].servant.insert(player[op].servant.begin()+p,temp);
            /*for(int i = 7;i > p;--i ){
                player[op].servant[i] = player[op].servant[i-1];
            }
            player[op].servant[p].attack = a;
            player[op].servant[p].health = h;
            player[op].num++;*/
        }
        else if(s[0] == 'a'){
            stringstream ss(s);
            int a,d;
            ss >> s >> a >> d;
            player[op].servant[a].health -= player[op^1].servant[d].attack;
            if(player[op].servant[a].health <= 0){
                /*for(int i = a;i < 7; ++i){
                    player[op].servant[i] = player[op].servant[i+1];
                }
                player[op].num--;*/
                player[op].servant.erase(player[op].servant.begin()+a);
            }
            player[op^1].servant[d].health -= player[op].servant[a].attack;
             //第一个坑
            if( player[op^1].servant[d].health <= 0){
                if(d == 0)
                    return;
                player[op^1].servant.erase(player[op^1].servant.begin()+d);
                /*for(int i = d;i < 7; ++i){
                    player[op^1].servant[i] = player[op^1].servant[i+1];
                }
                player[op^1].num--;*/
            }
        }
    }
}

void ans(){
    if(player[0].servant[0].health <= 0 && player[1].servant[0].health > 0)
        cout << -1<<endl;
    else if(player[1].servant[0].health <=0 && player[0].servant[0].health >0)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    for(int j = 0;j < 2;++j){
        cout<<player[j].servant[0].health<<endl;
        //cout<<player[j].num;
        cout<<player[j].servant.size()-1;
        //for(int i = 1;i <= player[j].num;++i){
        for(int i = 1;i<player[j].servant.size();++i){
            cout<<" " <<player[j].servant[i].health;
        }
        cout <<endl;
    }
}

int main()
{
#ifdef LOCAL
    freopen("datain.txt","r",stdin);
#endif // LOCAL
    run();
    ans();
    return 0;
}
