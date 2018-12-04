#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 4005;

typedef long long ll;

ll dp[maxn][maxn];
pair<int,int> pre[maxn][maxn];
int n,m;

struct point{
	int val,id;
	point(int val = 0,int id = 0):val(val),id(id){}
	bool operator < (const point & rhs) const{
		return val < rhs.val;
	}
}a[maxn],b[maxn];
int ans[maxn];
int main(){
	freopen("evacuation.in","r",stdin);
	freopen("evacuation.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i].val);
		a[i].id = i;
	}
	sort(a + 1,a + 1 + n);
	cin >> m;
	for(int i = 1;i <= m;i++){
		scanf("%d",&b[i].val);
		b[i].id = i;
	}
	sort(b + 1,b +1 + m);
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= m;j++)
			dp[i][j] = 1e18,pre[i][j] = make_pair(-1,-1);
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(dp[i - 1][j] < dp[i - 1][j - 1]){
				pre[i][j] = make_pair(i - 1,j);
			}else{
				pre[i][j] = make_pair(i - 1,j - 1);
			}
			dp[i][j] = min(dp[i - 1][j],dp[i - 1][j - 1]) + abs(a[i].val - b[j].val);
		}
	}
	cout << dp[n][m] << endl;
	int nowx = n,nowy = m;
	while(nowx != 0 && nowy != 0){
		ans[a[nowx].id] = b[nowy].id;
		pair<int,int> p = pre[nowx][nowy];
		nowx = p.first;
		nowy = p.second;
	}
	for(int i = 1;i <= n;i++){
		printf("%d%c",ans[i],i == n ? '\n' : ' ');
	}
	return 0;
}
