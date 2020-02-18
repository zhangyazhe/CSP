#include <bits/stdc++.h>
using namespace std;

struct date{
	int year;
	int month;
	int day;
	int h;
	int m;
};

struct item{
	vector<int> m, h, day, month, week;
	string command;
};

date parseDate(long long num){
	date d;
	string str, subs;
	stringstream ss;
	ss << num;
	ss >> str;
	ss.clear();
	subs = str.substr(0,4);
	ss << subs;
	ss >> d.year;
	ss.clear();
	subs = str.substr(4,2);
	ss << subs;
	ss >> d.month;
	ss.clear();
	subs = str.substr(6,2);
	ss << subs;
	ss >> d.day;
	ss.clear();
	subs = str.substr(8,2);
	ss << subs;
	ss >> d.h;
	ss.clear();
	subs = str.substr(10,2);
	ss << subs;
	ss >> d.m;
	ss.clear();
	return d;
}

int getNum(int &i, string str){
	int num = 0;
	while(str[i] >= '0' && str[i]<= '9'){
		num = num * 10 + str [i] - '0';
		i++;
		if((i+1) == str.size()){
			break;
		}
	}
	i--;
	return num;
}

vector<int> parseNum(str){
	vector<int> vec;
	int start, end;
	for(int i=0; i<str.size(); i++){
		if(str[i] == '*'){
			vec.push_back(666);
		}else if(str[i]>='0' && str[i]<= '9'){
			vec.push_back(getNum(&i, str));
		}else if(str[i] == '-'){
			i++;
			end = getNum(&i, str);
			start = vec[vec.size() - 1];
			for(int num=start; num <= end; num++){
				vec.push_back(num);
			}
		}else if(str[i] == ','){
			i++;
			vec.push_back(getNum(&i, str));
		}
	}
	return vec;
}

int getAbbr(str){
	
}

vector<int> parseAbbr(str){
	string subs;
	subs = str.substr(0,3);
	
}

item parseMatter(string str){
	string temp;
	stringstream ss;
	item it;
	ss << str;
	ss >> temp;
	it.m = parseNum(temp);
	ss >> temp;
	it.h = parseNum(temp);
	ss >> temp;
	it.day = parseNum(temp);
	ss >> temp;
	if(temp[0] >= '0' && temp[0] <= '9'){
		//not use abbr
		it.month = parseNum(temp);
	}else{
		//use abbr
		it.month = parseAbbr;
	}
	ss >> temp;
	if(temp[0] >= '0' && temp[0] <= '9'){
		//not use abbr
		it.week = parseNum(temp);
	}else{
		//use abbr
		it.week = parseAbbr;
	}
	ss >> temp;
	it.command = temp;
}

int main(){
	int n; 
	string str;
	long long s, t;
	vector<string> matter;
	vector<item> items;
	cin >> n >> s >> t;
	cin.get();
	date start = parseDate(s);
	date end = parseDate(t);
	for(int i=0; i<n; i++){
		getline(cin,str);
		matter.push_back(str);
	}
	
	
}
