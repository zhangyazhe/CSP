#include<bits/stdc++.h>
#define UP(x) for(uint32_t i=0;i<x;i++)
typedef unsigned int uint32_t;
using namespace std;
uint32_t len = 0;
//异或操作
//16进制 数字与字符之间的转换
char getc(char c){
    if(c<10)
        return c+'0';
    else if(c<=16)
        return c+'A'-10;
    else if(c<='9')
        return c-'0';
    else if(c<='F')
        return c-'A'+10;
}
void yh(string &a,string b){
    UP(8){
        a[i]=getc(getc(a[i])^getc(b[i]));
    }
}
void getdata(string dskd[],uint32_t n,uint32_t s,uint32_t l,uint32_t r){
    uint32_t level=r/((n-1)*s);				//获取读取的数据层数
    uint32_t curp=(n-level%n)-1;			//获取读取的数据层数P块所在位置
    uint32_t blk=level*s+r%s;				//获取数据所在硬盘的块索引
    uint32_t disk=r%((n-1)*s)/s+curp+1;		//获取读取的数据所在硬盘索引
    disk=disk%n;
    if(len<blk*8+8||len==0){				//如果获取的长度超过了硬盘数据长度，直接输出减号退出
        cout<<"-"<<endl;
        return;
    }
    if(dskd[disk].length()!=0)				 //如果当前盘存在，直接输出
        cout<<dskd[disk].substr(blk*8,8)<<endl;
    else if(dskd[disk].length()==0&&n-l==1){ //如果当前盘缺失，且可以恢复，则通过异或读取对应的数据
        string str="00000000";
        UP(n){
            if(i!=disk)
                yh(str,dskd[i].substr(blk*8,8));
        }
        cout<<str<<endl;
    }else
        cout<<"-"<<endl;					 //如果当前盘缺失且不可以恢复，输出减号。
}
int main(){
    ios::sync_with_stdio(false);
    uint32_t n,s,l;
    cin>>n>>s>>l;
    string dskd[1010];
    uint32_t dpos;
    UP(l){
        cin>>dpos;
        cin>>dskd[dpos];
    }
    uint32_t m;
    cin>>m;
    uint32_t a[1000];
    UP(m){
        cin>>a[i];
    }
    UP(n){
        if(dskd[i].length()!=0){
            len = dskd[i].length();
            break;
        }
    }
    UP(m){
        getdata(dskd,n,s,l,a[i]);
    }
    return 0;
}