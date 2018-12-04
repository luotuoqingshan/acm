#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 10000 + 100;

int prime[maxn];
bool vis[maxn];int tot;

void init(){
	vis[1] = true;
	tot = 0;
	for(int i = 1;i < maxn;i++){
		if(!vis[i]){
			prime[++tot] = i;
		}
		for(int j = 1;j <= tot && prime[j] * i < maxn;j++){
			vis[prime[j] * i] = true;
			if(i % prime[j] == 0)
				break;
		}
	}
}

bool check(int x){
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0) return false;
	}
	return true;
}
const int INF = 0x3f3f3f3f;

struct p{
	int i,j;
	int a,b,c;
	p(int _a = 0,int _b = 0,int _c = 0,int _i = 0,int _j = 0):a(_a),b(_b),c(_c),i(_i),j(_j){}
	bool operator < (const p & rhs) const{
		int x,y;
		if(a == INF) x = i;
		else x = a;
		if(rhs.a == INF) y = rhs.i;
		else y = rhs.a;
		if(x != y) return x < y;
		return j < rhs.j;
	}
};

p dp[maxn];
bool inq[maxn];

int ans[3];


int main(){
	init();
	dp[1] = p(INF,INF,INF,1,1);
	for(int i = 2;i <= 10007;i++){
		dp[i] = p(INF + 5,INF + 5,INF + 5,i,1);
	}
	queue<int> q;
	q.push(1);
	inq[1] = 1;
	while(!q.empty()){
		int i = q.front();q.pop();
		inq[i] = 0;
		if(i > 1){
			p tmp = p(dp[i].c == INF ? i: dp[i].c ,dp[i].a,dp[i].b,i - 1,i);
			if(tmp < dp[i - 1]){
				dp[i - 1] = tmp;
				if(!inq[i - 1]){
					q.push(i - 1);
				}
			}
		}
		for(int j = 1;j <= tot && i * prime[j] <= 10007;j++){
			p tmp = p(dp[i].c == INF ? i : dp[i].c,dp[i].a,dp[i].b,i * prime[j],i);
			//cout << tmp.a << " " << tmp.b << " " << tmp.c << endl;
			//cout << dp[i * prime[j]].a << " " << dp[i * prime[j]].b << " " << dp[i * prime[j]].c << endl;
			if(tmp < dp[i * prime[j]]){
				dp[i * prime[j]] = tmp;
				if(!inq[i * prime[j]]){
					q.push(i * prime[j]);
				}
			}
		}
	}
	
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		char str[3];
		scanf("%s",str);
		int m;
		scanf("%d",&m);
		int j;
		if(str[0] == 'O')j = 0;
		else if(str[0] == 'E') j = 1;
		else j = 2;
		for(int k = 0;k < 3;k++){
			int now;
			if(k == 0) now = dp[m].a;
			else if(k == 1) now = dp[m].b;
			else now = dp[m].c;
			if(now == INF) now = m;
			ans[(k + j) % 3] += now;
		}
	}
	for(int i = 0;i < 3;i++){
		cout << ans[i];
		if(i == 2) cout << endl;
		else cout << " ";
	}
	return 0;
}
