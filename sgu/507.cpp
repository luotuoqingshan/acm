#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int n,m;

const int maxn = 50000 + 5;
vector<int> G[maxn];

int val[maxn];
set<int> s[maxn];
int ans[maxn];
void dfs(int u){
	if(u > n - m){
		s[u].insert(val[u]);
		ans[u] = INT_MAX;
	}else{
		ans[u] = INT_MAX;
			int mx = 0;
			int id = 0;
			for(auto x : G[u]){
				dfs(x);
				if(s[x].size() > mx){
					mx = s[x].size();
					id = x;
				}
				ans[u] = min(ans[u],ans[x]);
			}	
			s[u] = s[id];
			s[id].clear();
			for(auto x : G[u]){
				if(x == id) continue;
				for(auto v : s[x]){
					set<int>::iterator it = s[u].lower_bound(v);
					if(it != s[u].end()){
						ans[u] = min(ans[u],*it - v);
					}	
					it = s[u].upper_bound(v);
					if(it == s[u].begin()) continue;
					it--;
					ans[u] = min(ans[u],v - *it);
					s[u].insert(v);
				}
				s[x].clear();
			}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1;i < n;i++){
		int fa;
		scanf("%d",&fa);
		G[fa].push_back(i + 1);
	}

	for(int i = 1;i <= m;i++){
		scanf("%d",&val[n - m + i]);
	}
	dfs(1);
	for(int i = 1;i <= n - m;i++){
		printf("%d%c",ans[i],i == n - m ? '\n' : ' ');
	}
	return 0;
}
