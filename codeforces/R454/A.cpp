#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5 + 5;


int n;
bool vis[maxn][26];
bool temp[26];
string s[maxn],opt[maxn];


bool check(char c,string s,int type){
	for(int i = 0;i < s.length();i++){
		if(s[i] == c){
			if(type == 1) return 1;
			else return 0;
		}
	}
	return type == 2;
}
int main(){
	cin >> n;
	ios::sync_with_stdio(false);
	for(int i = 1;i <= n;i++){
		cin >> opt[i];
		cin >> s[i];
	}
	int mx = 0;
	for(char c = 'a';c <= 'z';c++){
		if(c == s[n][0]) continue;
		int i;
		for(i = 1;i < n;i++){
			if(opt[i][0] == '!'){
				if(check(c,s[i],1)) break;	
			}else if(opt[i][0] == '.'){
				if(check(c,s[i],2)) break;
			}
		}	
		mx = max(mx,i - 1);
	}
	int ans = 0;
	for(int i = mx + 1;i < n;i++){
		if(opt[i][0] == '!' || opt[i][0] == '?') ans++;
	}
	cout << ans << endl;
	return 0;
}
