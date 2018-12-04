#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s;
		int m = s.length();
		bool flag = false;	
		if((s[m - 2] == 'c' && s[m - 1] == 'h') || (s[m - 1] == 'x') || (s[m - 1] == 's') || (s[m - 1] == 'o')){
			cout << s << "es" << endl;
			flag = true;
		}
		if(s[m - 1] == 'f'){
			s[m - 1] = 'v';
			s += "es";
			cout << s << endl;
			flag = true;
		}
		if(s[m - 1] == 'e' && s[m - 2] == 'f'){
			s[m - 2] = 'v';
			s[m - 1] = 'e';
			s += "s";
			cout << s << endl;
			flag = true;
		}
		if(s[m - 1] == 'y'){
			s[m - 1] = 'i';
			s += "es";
			cout << s << endl;
			flag = true;
		}
		if(!flag){
			cout << s << "s" << endl;
		}
	}
	return 0;
}
