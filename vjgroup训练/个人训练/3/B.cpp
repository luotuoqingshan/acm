#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;

int n,m,c;
int q;

int g[maxn][maxn];
int ans[maxn];
int L[maxn][maxn];
int R[maxn][maxn];
int U[maxn][maxn];
int D[maxn][maxn];

int cal(int i,int j){
	return min(min(i - U[i][j],D[i][j] - i),min(j - L[i][j],R[i][j] - j));
}

int main(){
	while(cin >> n >> m >> c >> q){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				scanf("%d",&g[i][j]);
			}
		}
		memset(ans,0,sizeof(ans));
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				int k;
				for(k = i;k >= 1;k--){
					if(g[k][j] != g[i][j]) break;
				}
				U[i][j] = k + 1;
				for(k = i;k <= n;k++){
					if(g[k][j] != g[i][j]) break;
				}
				D[i][j] = k - 1;
				for(k = j;k >= 1;k--){
					if(g[i][k] != g[i][j]) break;
				}
				L[i][j] = k + 1;
				for(k = j;k <= m;k++){
					if(g[i][k] != g[i][j]) break;
				}
				R[i][j] = k - 1;
				ans[g[i][j]] += min(min(i - U[i][j],D[i][j] - i),min(j - L[i][j],R[i][j] - j));
			}
		}
						
		for(int i = 1;i <= q;i++){
			char str[3];
			scanf("%s",str);
			if(str[0] == 'Q'){
				int c;
				scanf("%d",&c);
				printf("%d\n",ans[c]);
			}else{
				int x,y,k;
				scanf("%d%d%d",&x,&y,&k);
				int j;
				int tmp = g[x][y];
				g[x][y] = k;
				for(j = x;j >= 1;j--){
					if(g[j][y] != k) break;
				}
				int tu = j + 1;
				for(j = x;j <= n;j++){
					if(g[j][y] != k) break;
				}
				int td = j - 1;
				for(j = y;j >= 1;j--){
					if(g[x][j] != k) break;
				}
				int tl = j + 1;
				for(j = y;j <= m;j++){
					if(g[x][j] != k) break;
				}
				int tr = j - 1;
				ans[tmp] -= min(min(x - U[x][y],D[x][y] - x),min(y - L[x][y],R[x][y] - y));
				ans[k] += min(min(x - tu,td - x),min(y - tl,tr - y));
				//g[x][y] = k;
				L[x][y] = tl;R[x][y] = tr;U[x][y] = tu;D[x][y] = td;
				for(j = x - 1;j >= 1;j--){
					if(g[j][y] != g[x][y]) break;
					ans[g[j][y]] -= cal(j,y);
					D[j][y] = D[x][y];
					ans[g[j][y]] += cal(j,y);
				}
				for(j = x + 1;j <= n;j++){
					if(g[j][y] != g[x][y]) break;
					ans[g[j][y]] -= cal(j,y);
					U[j][y] = U[x][y];
					ans[g[j][y]] += cal(j,y);
				}
				for(j = y - 1;j >= 1;j--){
					if(g[x][j] != g[x][y]) break;
					ans[g[x][j]] -= cal(x,j);
					R[x][j] = R[x][y];
					ans[g[x][j]] += cal(x,j);
				}
				for(j = y + 1;j <= m;j++){
					if(g[x][j] != g[x][y]) break;
					ans[g[x][j]] -= cal(x,j);
					L[x][j] = L[x][y];
					ans[g[x][j]] += cal(x,j);
				}
				for(j = tu - 1;j >= 1;j--){
					if(D[j][y] >= x){
						ans[g[j][y]] -= cal(j,y);
						D[j][y] = tu - 1;
						ans[g[j][y]] += cal(j,y);
					}else break;
				}
				for(j = td + 1;j <= n;j++){
					if(U[j][y] <= x){
						ans[g[j][y]] -= cal(j,y);
						U[j][y] = td + 1;
						ans[g[j][y]] += cal(j,y);
					}else break;
				}
				for(j = tl - 1;j >= 1;j--){
					if(R[x][j] >= y){
						ans[g[x][j]] -= cal(x,j);
						R[x][j] = tl - 1;
						ans[g[x][j]] += cal(x,j);
					}else break;
				}
				for(j = tr + 1;j <= m;j++){
					if(L[x][j] <= y){
						ans[g[x][j]] -= cal(x,j);
						L[x][j] = tr + 1;
						ans[g[x][j]] += cal(x,j);
					}else break;
				}
			}
		}
				
			
	}
	return 0;
}
