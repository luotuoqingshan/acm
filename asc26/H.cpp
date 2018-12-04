#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n,m;

const int maxn = 1005;
vector< pair<int, pair<int,int> > > edge;
int d[maxn];
int main(){
	cin >> n >> m;
	memset(d,0x3f3f3f3f,sizeof(d));

	d[1] = 0;
	int delta = 1000;
	int now = 1;
	while(m > 0){
		for(int j = now + 1;j <= min(n,now + m);j++){
			edge.push_back(make_pair((j - now) * delta,make_pair(now,j)));
		}
		m -= min(n - now,m);
		now++;
		delta--;
	}
	for(int i = 0;i < edge.size();i++){
		printf("%d %d %d\n",edge[i].second.first,edge[i].second.second,edge[i].first);
	}
	return 0;
}
