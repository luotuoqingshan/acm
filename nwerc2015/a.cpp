#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 300000 + 5;

typedef pair<int,int> pii;

pii a[maxn];
int n,m;
priority_queue<int,vector<int>,greater<int> > pq;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	sort(a + 1,a + 1 + n);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		while(!pq.empty()){
			int t = pq.top();
			if(t < a[i].first - m){
				pq.pop();
			}else break;
		}
		if(!pq.empty()){
			if(pq.top() <= a[i].first){
				pq.pop();
				ans++;
				pq.push(a[i].first + a[i].second);
			}else{
				pq.push(a[i].first + a[i].second);
			}
		}else{
			pq.push(a[i].first + a[i].second);		
		}
	}
	cout << ans << endl;
	return 0;
}
