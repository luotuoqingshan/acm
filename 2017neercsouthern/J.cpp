#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

int n,m;

int a[maxn],b[maxn],p[maxn];
int t[maxn];
pair<int,int> s[maxn],top;

typedef long long LL;

LL sum[maxn];
LL c[maxn];


void add(int x,LL d){
	for(int i = x;i < maxn;i += i & -i){
		c[i] += d;
	}
}

LL Sum(int x){
	LL ret = 0;
	for(int i = x;i > 0;i -= i & -i){
		ret += c[i];
	}
	return ret;
}

pair<int,int> d[maxn];
int main(){
	cin >> n >> m;
	sum[0] = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	top = 0;
	for(int i = 1;i <= n;i++){
		while(top > 0 && s[top].first <= a[i]) top--;
		s[++top] = make_pair(a[i],i);
	}
	reverse(s + 1,s + 1 + top);
	for(int i = 1;i <= m;i++){
		scanf("%d",&b[i]);
		int id = lower_bound(s + 1,s + 1 + top,make_pair(b[i],0));
		t[i] = s[id].second;
	}
	for(int i = 1;i <= m;i++){
		scanf("%d",&p[i]);
		d[i] = make_pair(p[i],t[i]);
	}
	int ans = 0;
	for(int i = 1;i <= m;i++){
		if(Sum(d[i].second) + d[i].first <= sum[d[i].second]){
			ans++;
			add(d[i].second,d[i].first);
		}	
	}
	cout << ans << endl;
	return 0;
}
