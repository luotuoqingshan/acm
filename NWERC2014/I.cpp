#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int n;
LL L;
LL d[20][20];

#include <unordered_set> 

typedef unsigned long long ull;
unordered_set<LL> mp[14][(1<<14) + 5];
int a[20];
int m;
bool flag;
void dfs(int k,int st,LL sum,int type){
	if(flag) return;
	if(k == m){
		if(type == 1){
				int j = a[m];	
				mp[j][st].insert(sum);
		}
		else{
				int j = a[m];
				int s = (1 << n) - 1;
				st = s ^ st;
				st += 1;
				st |= (1 << j);
				sum = L - sum;
				if(mp[j][st].count(sum)){
					flag = true;
				}
		}
		return;
	}
	for(int i = 1;i < n;i++){
		if((st & (1 << i)) == 0){
			a[k + 1] = i;
			dfs(k + 1,st | (1 << i),sum + d[a[k]][a[k + 1]],type);
		}
	}
}
int main(){
	cin >> n >> L;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			scanf("%lld",&d[i][j]);
		}
	}
	flag = 0;
	a[0] = 0;
	if(n == 2) m = 1;
	else m = n / 2 - 1;
	dfs(0,1,0,1);
	m = n - m;
	dfs(0,1,0,2);
	if(flag) cout << "possible" << endl;
	else cout << "impossible" << endl;
	return 0;
}
