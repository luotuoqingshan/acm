#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int n,s,w;
int Q;
const int maxn = 1e5 + 5;

int a[maxn];
int cnt[maxn];
void init(){
	int g = s;
	for(int i = 0;i < n;i++){
		a[i] = (g / 7) % 10;
		if(g % 2 == 0) {g = (g / 2);}
		else 		{g = (g / 2) ^ w;}
	}
}
unordered_map<int,int> mp;
int sum[maxn];
int main(){
	while(cin >> n >> s >> w >> Q){
		memset(cnt,0,sizeof(cnt));
		memset(sum,0,sizeof(sum));
		mp.clear();
		if(n == 0) break;
		init();	
			cnt[n - 1] = 1;
			for(int i = n - 2;i >= 0;i--){
				cnt[i] = (cnt[i + 1] * 10) % Q;
			}
			long long ans = 0;
		if(Q != 2 && Q != 5){
			mp[0]++;
			int now = 0;
			for(int i = n - 1;i >= 0;i--){
				now = (now + cnt[i] * a[i]) % Q;
				if(a[i] != 0)ans += mp[now];
				mp[now]++;
			}			
		}else{
			if(a[0] != 0) sum[0] = 1;
			for(int i = 1;i < n;i++){
				sum[i] = sum[i - 1] + (a[i] != 0);
			}
			for(int i = 0;i < n;i++){
				if(Q == 2){
					if(a[i] % 2 == 0){
						ans += sum[i];
					}
				}else{
					if(a[i] % 5 == 0){
						ans += sum[i];
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

