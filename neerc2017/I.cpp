#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <vector>
using namespace std;

char ask(int x,int y){
	cout << "?" << " " << x << " " << y << endl;
	fflush(stdout);
	string s;
	cin >> s;
	return s[0];
}

const int maxn = 10005;

vector<int> v[5005];
vector<int> Ans;
int cnt[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int k = n / 2;//用偶数去分奇数
	for(int i = 1;i <= n - k;i++){
		v[1].push_back(i);
	}
	int m = 1;
	cnt[0] = 0;cnt[1] = n - k;
	for(int i = 1;i <= k;i++){
		int l = 1,r = m,ans = -1;
		vector<int> v0,v1;
		int now = 0;
		while(l <= r){
			v0.clear(),v1.clear();
			now = 0;
			int mid = (l + r) / 2;
			int tmp = 0;
			for(int j = 0;j < v[mid].size();j++){
				int x = v[mid][j];
				if(ask(i,x) == '>') tmp |= 1,v0.push_back(x),now++;
				else tmp |= 2,v1.push_back(x);
			}
			if(tmp == 3){
				ans = l;
				break;
			}
			if(tmp == 1){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		if(ans == -1 && r == m){
			Ans.push_back(2 * k);
			continue;
		}else if(ans == -1 && l == 1){
			Ans.push_back(2);
			continue;
		}	
		for(int j = m + 1;j >= ans + 2;j--){
			v[j].clear();
			for(int k = 0;k < v[j - 1].size();k++){
				v[j].push_back(v[j - 1][k]);
			}
			cnt[j] = cnt[j - 1];
		}
		Ans.push_back(2 * now + 2 * cnt[ans - 1]);
		v[ans].clear();
		v[ans + 1].clear();
		for(int j = 0;j < v0.size();j++) v[ans].push_back(v0[j]);
		for(int j = 0;j < v1.size();j++) v[ans + 1].push_back(v1[j]);
		cnt[ans] = cnt[ans - 1] + v0.size();
		cnt[ans + 1] = cnt[ans] + v1.size();
		m++;
	}		
	for(int i = 1;i <= m;i++){
		int j = v[i][0];
		Ans.push_back(2 * j - 1);
	}
	cout << "!";
	for(int i = 0;i < Ans.size();i++){
		cout << " " << Ans[i];
	}
	cout << endl;
	return 0;
}
