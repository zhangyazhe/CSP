#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 算法思想：
 * 用一个变量round表示现在是先手回合还是后手回合
 * 每次检查到随从死亡时，调用重新编号函数
 * 把每一次操作读到一个字符串中，根据字符串首字符判断操作类型
 * 创建随从结构体，创建随从数组，这其中也要包含英雄
 *
 * 实际上，character结构体中不需要num。直接利用输入的编号插入到vector对应的位置中
 * vector会自动将后面的元素向后移动的
 */

typedef struct characters{
    int num;//编号
    int health;
    int attack;
}chara;

int round_change(int round);
bool cmp(chara *c1, chara *c2);
int main() {
    int n, i, j, round=1, hero_alive=1, adjust=0;//当英雄死后，hero_alive置零，就不再有后续操作
    string temp;
    chara *p, *q;
    vector<string> action;
    vector<chara*> p1;//先手玩家手牌
    vector<chara*> p2;//后手玩家手牌
    cin >> n;
    cin.get();
    for(i=0; i<n; i++){
        getline(cin, temp);
        action.push_back(temp);
    }
    //添加双方英雄
    p = (chara*)malloc(sizeof(chara));
    p->attack = 0;
    p->health = 30;
    p->num = 0;
    q = (chara*)malloc(sizeof(chara));
    q->attack = 0;
    q->health = 30;
    q->num = 0;
    p1.push_back(p);
    p2.push_back(q);
    for(i=0; i<n && hero_alive; i++){
        adjust = 0;
        if(action[i][0] == 's'){
            //召唤随从
            p = (chara*)malloc(sizeof(chara));
            p->num = action[i][7] - '0';
            if(action[i][10] == ' ')
                p->attack = action[i][9]-'0';
            else{
                adjust = 1;
                p->attack = (action[i][9]-'0')*10 +action[i][10]-'0';
            }
            if(action[i][12+adjust] == '\0')
                p->health = action[i][11+adjust]-'0';
            else{
                p->health = (action[i][11+adjust]-'0')*10 +action[i][12+adjust]-'0';
            }
            if(round == 1){
                sort(p1.begin(), p1.end(), cmp);
                if(p1.size() > p->num){
                    //需要整体移动
                    for(j=p->num; j<p1.size(); j++){
                        (p1[j]->num)++;
                    }
                } else{
                    p->num = (int)p1.size();
                }
                p1.push_back(p);
                sort(p1.begin(), p1.end(), cmp);
            } else{
                sort(p2.begin(), p2.end(), cmp);
                if(p2.size() > p->num){
                    //需要整体移动
                    for(j=p->num; j<p2.size(); j++){
                        p2[j]->num++;
                    }
                } else{
                    p->num = (int)p2.size();
                }
                p2.push_back(p);
                sort(p2.begin(), p2.end(), cmp);
            }
        } else if(action[i][0] == 'a'){
            //攻击
            if(round == 1){
                p = p1[action[i][7] - '0'];//attacker
                q = p2[action[i][9] - '0'];//defender
                p->health -= q->attack;
                q->health -= p->attack;
                if(p->health <= 0){
                    if(p->num!=0)
                        p1.erase(p1.begin() + p->num);
                    else
                        hero_alive = 0;
                    if(p->num != p1.size() && p->num!=0){
                        for(j=p->num; j<p1.size(); j++){
                            p1[j]->num--;
                        }
                    }
                }
                if(q->health <= 0){
                    if(q->num!=0)
                        p2.erase(p2.begin() + q->num);
                    else
                        hero_alive = 0;
                    if(q->num != p2.size() && q->num!=0){
                        for(j=q->num; j<p2.size(); j++){
                            p2[j]->num--;
                        }
                    }
                }
            } else{
                p = p2[action[i][7] - '0'];//attacker
                q = p1[action[i][9] - '0'];//defender
                p->health -= q->attack;
                q->health -= p->attack;
                if(p->health <= 0){
                    if(p->num!=0)
                        p2.erase(p2.begin() + p->num);
                    else
                        hero_alive = 0;
                    if(p->num != p2.size() && p->num!=0){
                        for(j=p->num; j<p2.size(); j++){
                            p2[j]->num--;
                        }
                    }
                }
                if(q->health <= 0){
                    if(q->num!=0)
                        p1.erase(p1.begin() + q->num);
                    else
                        hero_alive = 0;
                    if(q->num != p1.size() && q->num!=0){
                        for(j=q->num; j<p1.size(); j++){
                            p1[j]->num--;
                        }
                    }
                }
            }
        } else{
            //结束
            round = round_change(round);
        }
    }
    //判定结果
    if(p1[0]->health<=0){
        cout << -1 << endl;
    } else if(p2[0]->health<=0){
        cout << 1 << endl;
    } else{
        cout << 0 << endl;
    }
    cout << p1[0]->health << endl;
    cout << p1.size()-1;
    for(i=1; i<p1.size(); i++){
        cout << ' ' << p1[i]->health;
    }
    cout << endl;
    cout << p2[0]->health << endl;
    cout << p2.size()-1;
    for(i=1; i<p2.size(); i++){
        cout << ' ' << p2[i]->health;
    }
    return 0;
}

int round_change(int round){
    if(round == 1) return -1;
    else return 1;
}

bool cmp(chara *c1, chara *c2){
    return c1->num < c2->num;
}