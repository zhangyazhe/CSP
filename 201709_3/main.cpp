/*
 * author: CSDN
 * url: https://blog.csdn.net/qq_15046309/article/details/82715234
 */

/*
 * 算法思想：
 * 读取字符串时，只记录引号的位置，然后利用引号的索引提取字符串。
 * 初始值count为0，每拿到一个字符串（或大括号中的大括号），就让count加一，
 * 这样一来，在处理字符串时，根据count是奇数还是偶数就可以判断字符串应该是
 * key还是value。
 * 如果是key，就先保存着（本代码中利用栈来保存）,如果是value,就将之前保存的
 * key取出来，和value一起存入map中。
 * 每当读取到‘{’时，就让他入栈，同时判断栈中之前是否还有‘{’。如果没有，说明这个大括号
 * 是整个对象的起始大括号。如果有，说明这个大括号是value的起始大括号。
 * 对于第二种情况，直接将此时的value设置为“OBJECT0”,这样一来，最后在查询的时候
 * 如果查询到某个key的value是OBJECT0，就直接输出OBJECT即可。同时，需要将
 * 此时对应的key值保存起来（本例中利用qianzhui栈来保存)
 * 在每次处理key字符串前，都要判断一下qianzhui栈是否为空，若不为空，意味着
 * 此时的key需要加上前缀，然后再进行保存。
 */

#include <iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;
/*
对于'{'的判断，很明显利用栈的性质来做.
字符串是由双引号 " 括起来的一组字符（可以为空）。
如果字符串的内容中出现双引号 "，在双引号前面加反斜杠，也就是用 \" 表示；
如果出现反斜杠 \，则用两个反斜杠 \\ 表示。反斜杠后面不能出现 " 和 \ 以外的字符。
*/
map<string, string>key;
map<string, string>::iterator it;
stack<string>linshi;
stack<string>qianzhui;
void change(string a, int num)//分析字符串
{
    string b;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '\\')
        {
            if (i - 1 > -1 && a[i - 1] == '\\')
            {
                a[i] = 'a';
            }
            else if (i + 1 < a.length() && a[i + 1] == '\"')
            {

            }
            else {
                b += a[i];
            }
        }
        else {
            b += a[i];
        }
    }

    if (num % 2 == 0)
    {
        key[linshi.top()] = b;
        linshi.pop();
    }
    else
    {
        if (qianzhui.size() != 0)
        {
            b = qianzhui.top() + "." + b;
        }
        linshi.push(b);
    }

}
map<string, string>ramdisk;
int main()
{
    stack<char>bigkuo;
    int n, m;
    cin >> n >> m;
    string *context = new string[n];
    string *yu = new string[m];
    string Queryfy, information;
    cin.ignore();//这里要注意，因为cin输入后，还有残留，如果没有这句，getline就把残留给收走了。
    for (int i = 0; i < n; i++)
    {
        getline(cin, context[i]);
        information += context[i];
    }
    for (int i = 0; i < m; i++)
        cin >> yu[i];
    int qian, hou; bool you = true; int conut = 0;//通过这个count来确认到底这个是key还是value
    for (int i = 0; i < information.length(); i++)
    {
        if (information[i] == '{') {
            bigkuo.push('{');
            if (bigkuo.size() > 1)
            {
                string u = "OBJECT0";
                qianzhui.push(linshi.top());
                change(u, conut += 1);
            }

        }
        if (information[i] == '}') {
            bigkuo.pop();
            if (bigkuo.size() > 0) {
                qianzhui.pop();

            }

        }
        if (information[i] == '"'&&information[i - 1] != '\\')//第一种字符串的终止情况判断， 例如"iosa\"dsa"
        {

            if (you) {
                qian = i;
                you = false;
            }
            else {
                hou = i; you = true;
                change(information.substr(qian + 1, hou - qian - 1), conut += 1);
            }
        }
        if (i-2>-1&&information[i] == '"'&&information[i - 1] == '\\'&&information[i-2]=='\\')//第二种字符串的终止情况判断，例如"\"\"\\\\"
        {
            hou = i;
            you = true;
            change(information.substr(qian + 1, hou - qian - 1), conut += 1);
        }
    }

    for (int i = 0; i < m; i++)
    {
        it = key.find(yu[i]);
        if (it != key.end())
        {
            if (it->second != "OBJECT0")
            {
                cout << "STRING" << " " << it->second << endl;
            }
            else {
                cout << "OBJECT" << endl;
            }
        }
        else
        {
            cout << "NOTEXIST" << endl;
        }

    }
}