#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include<set>
using namespace std;

int k,n;
const int maxn = 1e5 + 5;
pair<int,pair<int,int> > p[maxn * 2];

set<pair<int,pair<int,int> > > s;
int main(){
	cin >> k >> n;
	int m = n + k - 1;
	for(int i = 1;i <= n + k - 1;i++){
		scanf("%d%d",&p[i].first,&p[i].second.first);
		p[i].second.second = i;
		p[i].second.first = -p[i].second.first;
	}
	sort(p + 1,p + 1 + m);
	for(int i = 1;i <= k;i++){
		s.insert(make_pair(p[i].second.first,make_pair(p[i].first,p[i].second.second)));
	}
	int ans = -1;
	for(int i = k + 1;i <= n + k;i++){
		if((*s.begin()).second.second == 1){
			ans = p[i - 1].first;
			break;
		}	
		s.erase(s.begin());
		if(i < n + k)s.insert(make_pair(p[i].second.first,make_pair(p[i].first,p[i].second.second)));
	}
	if(ans != -1)cout << ans << endl;
	else cout << "unknown" << endl;
	return 0;
}
