#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

const int maxn = 10005;

vector<int> G[maxn];
int deg[maxn];
int n,m;
queue<int> q;
int dp[maxn];
int main(){
	int T;
	cin >> T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++){
			deg[i] = 0;
			G[i].clear();
		}
		for(int i = 1;i <= m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			deg[v]++;
		}	
		for(int i = 1;i <= n;i++){
			dp[i] = 0;
			if(deg[i] == 0){
				dp[i] = 1;
				q.push(i);
			}
		}	
		while(!q.empty()){
			int p = q.front();
			q.pop();
			for(int i = 0;i < G[p].size();i++){
				int v = G[p][i];
				dp[v] = max(dp[v],dp[p] + 1);
				deg[v]--;
				if(deg[v] == 0){
					q.push(v);
				}
			}	
		}	
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans = max(ans,dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

