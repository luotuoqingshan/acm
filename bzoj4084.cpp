#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

const int maxn = 4e6 + 5;

string s[maxn],t[maxn];
typedef unsigned long long ull;

const ull seed = 1331;
ull power[maxn];
void init(){
	power[0] = 1;
	for(int i = 1;i < maxn;i++){
		power[i] = power[i - 1] * seed;
	}
}
ull Hash[maxn];
ull cal(int l,int r){
	return Hash[r] - Hash[l - 1] * power[r - l + 1];	
}

map<ull,int> mp;
char str[maxn];


int main(){
	init();
	int n,m;
	int len1,len2;
	scanf("%d%d%d%d",&n,&m,&len1,&len2);
	for(int i = 1;i <= n;i++){
		scanf("%s",str);
		int len = strlen(str);
		s[i] = "";
		for(int j = 0;j < len;j++){
			s[i] += str[j];
		}
	}
	for(int i = 1;i <= m;i++){
		scanf("%s",str);
		int len = strlen(str);
		t[i] = "";
		for(int j = 0;j < len;j++){
			t[i] += str[j];
		}
		ull ret = 0;
		for(int j = 0;j < t[i].length();j++){
			ret = ret * seed + t[i][j] - 'a';
		}
		mp[ret]++;
	}
	int mid = (len1 + len2) / 2;
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		ull ret = 0;
		for(int j = 0;j < 2 * mid - 1;j++){
			ret = ret * seed + s[i][j % mid] - 'a';
			Hash[j] = ret;
		}
		ull tmp = 0;
		for(int j = mid;j < len1;j++){
			tmp = tmp * seed + s[i][j] - 'a';
		}	
		for(int j = 0;j < mid;j++){
			if(cal(j,j + len1 - mid - 1) == tmp) ans += mp[cal(j + len1 - mid,j + mid - 1)];
		}
	}
	cout << ans << endl;
	return 0;
}
/*
   4 4 7 3
vijosvi
josvivi
vijosos
ijosvsv
jos
vij
ijo
jos 
*/
