#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 52;

long long C[maxn][maxn];
int prime[50] = {2,3,5,7,11,13,17,19,23};

void init(){
	memset(C,0,sizeof(C));
	for(int i = 0;i < maxn;i++) C[i][0] = 1;
	for(int i = 1;i < maxn;i++){
		for(int j = 1;j <= i;j++){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
}

int K,S;

long long ans;

void dfs(int i,int zheng,long long now){
	if(i == 9) return;
	dfs(i + 1,zheng,now);
	long long tmp = now * prime[i];
	if(S / tmp < K) return;
	ans += zheng * C[S / tmp][K];
	dfs(i + 1,-1 * zheng,tmp);
}

int main(){
	init();
	//cout << C[50][25] << endl;
	while(cin >> K >> S){
			ans = 0;
			dfs(0,1,1);
			cout << min(ans,10000LL) << endl;
	}
	return 0;
}
