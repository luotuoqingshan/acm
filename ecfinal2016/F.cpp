#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;

int T;
int n;
const int maxn = 50005;
string s[maxn];

const int mod = 1e9 + 7;
const int seed = 13331;
unordered_map<int,bool> mp;
int power[maxn * 5];
void upd(int &a,int b){
	a += b;
	if(a < 0) a += mod;
}
string check(int len){
	mp.clear();
	for(int i = 2;i <= n;i++){
		if(len > s[i].length()) continue;
		int val = 0;
		for(int j = 0;j < len;j++){
			val = (1LL * val * seed + (s[i][j] - 'a' + 1)) % mod;	
		}
		mp[val] = 1;
		for(int j = len;j < s[i].length();j++){
			upd(val,-(s[i][j - len] - 'a' + 1) * 1LL *  power[len - 1] % mod);
			val = (1LL * val * seed + (s[i][j] - 'a' + 1)) % mod;
			mp[val] = 1;
		}
	}
	int val = 0;
	string ans = "";
	for(int j = 0;j < len;j++){
		val = (1LL * val * seed + (s[1][j] - 'a' + 1)) % mod;
	}
	if(!mp.count(val)){
		ans = s[1].substr(0,len);
	}
	for(int j = len;j < s[1].length();j++){
		upd(val,-(s[1][j - len] - 'a' + 1) * 1LL * power[len - 1] % mod); 
		val = (1LL * val * seed + (s[1][j] - 'a' + 1)) % mod;
		if(!mp.count(val)){
			if(ans == ""){
				ans = s[1].substr(j - len + 1,len);
			}else{
				string s1 = s[1].substr(j - len + 1,len);
				if(s1 < ans) ans = s1;
			}
		}
	}
	return ans;
}

int main(){
	power[0] = 1;
	for(int i = 1;i <= 250000;i++){
		power[i] = power[i - 1] * 1LL * seed % mod;
	}
	ios::sync_with_stdio(false);
	cin >> T;
	for(int cas = 1;cas <= T;cas++){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> s[i];
		}
		int l = 1,r = s[1].length() + 1;
		while(l < r){
			int mid = (l + r) / 2;
			if(check(mid) != "") r = mid;
			else l = mid + 1;
		}
		cout << "Case #" << cas << ": ";
		if(l == s[1].length() + 1){
			cout << "Impossible" << endl;	
		}else{
			cout << check(l) << endl;
		}
	}
	return 0;
}
