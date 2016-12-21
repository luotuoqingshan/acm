#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1005;

int p[maxn];

int main(){
	int n;
	while(cin >> n){
		for(int i = 1;i <= n;i++){
			scanf("%d",p + i);
		}
		sort(p + 1,p + 1 + n);
		int now = 0;
		int ans = -1;
		for(int i = 1;i <= n;i++){
			if(p[i] <= now + 1){
				now = now + p[i];
			}else{
				ans = now + 1;
				break;
			}
		}
		if(ans == -1){ ans = now + 1;}
		printf("%d\n",ans);
			
	}
	return 0;
}
