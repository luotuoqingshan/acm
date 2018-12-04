#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 50005;
int a[maxn];
long long d[maxn];
const long long INF = 1e18;
bool inq[maxn];
int n;
queue<int> q;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}	
	sort(a + 1,a + 1 + n);
	n = unique(a + 1,a + 1 + n) - a - 1;
	for(int i = 0;i < a[1];i++){
		d[i] = INF;
	}	
	d[0] = 0;
	q.push(0);
	inq[0] = 1;
	while(!q.empty()){
		int p = q.front();q.pop();
		inq[p] = 0;
		if(d[p] > 1e9) continue;
		for(int i = 2;i <= n;i++){
			if(d[(p + a[i]) % a[1]] > d[p] + a[i]){
				d[(p + a[i]) % a[1]] = d[p] + a[i];
				if(!inq[(p + a[i]) % a[1]]){
					inq[(p + a[i]) % a[1]] = 1;
					q.push((p + a[i]) % a[1]);
				}
			}
		}
	}
	int q;
	cin >> q;
	for(int i = 1;i <= q;i++){
		int b;
		scanf("%d",&b);
		if(b < d[b % a[1]]){
			puts("NIE");
		}else{
			puts("TAK");
		}
	}
	return 0;
}
