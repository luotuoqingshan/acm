#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


const int maxn = 1e6 + 5;
bool vis[maxn];

void init(){
	vis[1] = 1;
	for(int i = 2;i < maxn;i++){
		if(vis[i]) continue;
		for(int j = 2 * i;j < maxn ;j += i){
			vis[j] = 1;
		}
	}
}

int main(){
	int N;
	cin >> N;
	init();
	int ans = 0;
	for(int i = 3;i <= N - 2;i++){
		if(!vis[i] && !vis[i + 2]){
			ans++;
		}
	}
	cout << ans << endl;
	for(int i = 3;i <= N - 2;i++){
		if(!vis[i] && !vis[i + 2]){
			printf("%d %d\n",2,i);
		}
	}
	return 0;
}
