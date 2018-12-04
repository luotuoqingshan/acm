#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 10005;

char s[maxn];

int vis[30][30];

int main(){
	int n;
	while(scanf("%s",s) != EOF){
		n = strlen(s);
		for(int i = n;i < 2 * n;i++){
			s[i] = s[i - n];
		}
		double ans = 0.0;
		for(int i = 1;i < n;i++){
			memset(vis,0,sizeof(vis));
			int temp = 0;
			for(int j = 0;j < n;j++){
				vis[s[j] - 'a'][s[j + i] - 'a']++;
			}
			for(int j = 0;j < n;j++){
				if(vis[s[j] - 'a'][s[j + i] - 'a'] == 1){
					temp++;
				}	
			}
			ans = max(ans,1.0 * temp / n);
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}
