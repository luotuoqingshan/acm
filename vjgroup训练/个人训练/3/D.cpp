#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 200000 + 5;
const int maxm = 1000006;

bool vis[maxm * 2];
int a[maxn];
int n,m;
int ans[maxn];
int A[maxn][22];

void rmq_init(){
	for(int i = 0;i < n;i++) A[i][0] = ans[i];
	for(int j = 1;(1 << j) <= n;j++){
		for(int i = 0;i + (1 << j) - 1 < n;i++){
			A[i][j] = max(A[i][j - 1],A[i + (1<<(j-1))][j - 1]);
		}
	}
}

int rmq(int l,int r){
	int k = 31 - __builtin_clz(r - l + 1);
	return max(A[l][k],A[r - (1 << k) + 1][k]);
}

bool check(int x,int l,int r){
	if(l + x - 1 > r) return false;
	return rmq(l + x - 1,r) >= x;
}

//map<int,bool> mp;

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		scanf("%d",a + i);
		a[i] += maxm;
	}
	//mp.clear();
	memset(vis,false,sizeof(vis));
	int l = 0;
	for(int i = 0;i < n;i++){
		if(vis[a[i]]){
			for(;l < n;l++){
				vis[a[l]] = false;
				if(a[l] == a[i]) break;
			}
			l++;
		}
		vis[a[i]] = true;
		ans[i] = i - l + 1;
	}
	/*for(int i = 0;i < n;i++){
		printf("%d ",ans[i]);
	}*/
	rmq_init();
	for(int i = 1;i <= m;i++){
		int ql,qr;
		scanf("%d%d",&ql,&qr);
		int l = 0,r = qr - ql + 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			//cout << mid << endl;
			if(check(mid,ql,qr)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n",r);
	}
	return 0;
}
