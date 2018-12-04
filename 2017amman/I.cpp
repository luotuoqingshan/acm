#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int sg[105][105];
bool vis[5];
int main(){
	/*memset(sg,0,sizeof(sg));
	for(int i = 0;i <= 100;i++){
		for(int j = 0;j <= 100;j++){
			if(i == 0 && j == 0) continue;
			memset(vis,0,sizeof(vis));
			if(i > 0 && j > 0) vis[sg[i - 1][j - 1]] = 1;
			if(i > 0) vis[sg[i - 1][j]] = 1;
			if(j > 0) vis[sg[i][j - 1]] = 1;
			for(int k = 0;k < 5;k++){
				if(vis[k] == 0){
					sg[i][j] = k;
					break;
				}
			}
		}
	}
	for(int i = 0;i <= 5;i++){
		for(int j = 0;j <= 5;j++){
			cout << i << " " << j << " " << sg[i][j] << endl;
		}
	}*/
	int T;
	cin >> T;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		if((n % 2 == 0) && (m % 2 == 0)){
			printf("abdullah\n");
		}else{
			printf("hasan\n");
		}
	}
	return 0;
}
