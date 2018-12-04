#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

unordered_map<int,int> dp,pre;

int main(){
	 int n;
	cin >> n;
	queue<int> q;
	if(n % 2 == 0){
		cout << "No solution" << endl;
		return 0;
	}
	dp[n] = 0;
	pre[n] = 0;
	q.push(n);
	while(!q.empty()){
		int p = q.front();q.pop();
		if(p % 2 == 0) continue;
		if((p - 1) / 2 >= 1){
			if(dp.count((p - 1) / 2)){
				if(dp[(p - 1) / 2] > dp[p] + 1){
					dp[(p - 1) / 2] = dp[p] + 1;
					pre[(p - 1) / 2] = 2;
					q.push((p - 1) / 2);
				}
			}else{
					dp[(p - 1) / 2] = dp[p] + 1;
					pre[(p - 1) / 2] = 2;
					q.push((p - 1) / 2);
			}
		}
		if((p + 1) / 2 >= 1){
			if(dp.count((p + 1) / 2)){
				if(dp[(p + 1) / 2] > dp[p] + 1){
					dp[(p + 1) / 2] = dp[p] + 1;
					pre[(p + 1) / 2] = 1;
					q.push((p + 1) / 2);
				}
			}else{
					dp[(p + 1) / 2] = dp[p] + 1;
					pre[(p + 1) / 2] = 1;
					q.push((p + 1) / 2);
			}
		}
	}
	if(!dp.count(n)){
		cout << "No solution" << endl;
	}else{
		vector<int> ans(0);
		int now = 1;
		while(pre[now] != 0){
			ans.push_back(pre[now]);
			if(pre[now] == 1) now = now * 2 - 1;
			else now = now * 2 + 1;
		}	
		cout << ans.size() << endl;
		for(int i = 0;i < ans.size();i++){
			printf("%d%c",ans[i],i == ans.size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
