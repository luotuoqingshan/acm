#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int maxn = 1e5 + 5;
int vis[maxn];
int n;
char s[100];
int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= n;i++){
			int a;
			scanf("%s",s);
			scanf("%d",&a);
			vis[a]++;
		}
		int ans = -1,id = -1;
		for(int i = 11111;i <= 99999;i++){
			if(vis[i] > ans){
				ans = vis[i];
				id = i;
			}
		}
		cout << id << endl;
	}

	return 0;
}
