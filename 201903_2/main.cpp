#include <stdio.h>
#include <stack>
using namespace std;
char cmp(char a, char b);
int cal(int opn1, int opn2, char op);
int main(){
    int n, i, j, opn1, opn2, ret;
    char w, op0;
    char str[200][8];//列数为8，包含了字符串末尾的\0
    scanf("%d",&n);
    getchar();
    for(i=0; i<n; i++){
        for(j=0; j<8; j++){
            scanf("%c", &str[i][j]);
        }
    }

    for(i=0; i<n; i++){
        str[i][7]='#';
    }
    //判断是否是24点
    //构造运算符栈
    stack<char> op;
    //构造运算数栈
    stack<int> opn;
    op.push('#');
    for(i=0; i<n; i++){
        j=0;
        w = str[i][j++];
        while(w!='#' || op.top()!='#'){
            if(w>='0'&&w<='9'){
                opn.push((w-'0'));
                w = str[i][j++];
            }else{
                if(cmp(w, op.top())=='<' || cmp(w, op.top())=='='){
                    opn2 = opn.top();
                    opn.pop();
                    opn1 = opn.top();
                    opn.pop();
                    op0 = op.top();
                    op.pop();
                    ret = cal(opn1, opn2, op0);
                    opn.push(ret);
                }else{
                    op.push(w);
                    w = str[i][j++];
                }
            }
        }
        if(opn.top()==24){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}
char cmp(char a, char b){
    if(a=='#'){
        if(b=='#'){
            return '=';
        }else{
            return '<';
        }
    }
    if(a=='+'||a=='-'){
        if(b=='#'){
            return '>';
        }else if(b=='+'||b=='-'){
            return '=';
        }else{
            return '<';
        }
    }
    if(a=='x'||a=='/'){
        if(b=='x'||b=='/'){
            return '=';
        }else{
            return '>';
        }
    }
    return '\0';
}
int cal(int opn1, int opn2, char op){
    if(op=='+'){
        return opn1+opn2;
    }else if(op=='-'){
        return opn1-opn2;
    }else if(op=='x'){
        return opn1*opn2;
    }else if(op=='/'){
        return opn1/opn2;
    }
    return 0;
}
