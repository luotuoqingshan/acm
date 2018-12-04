#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

map<int,int> ID;

int T;
int n,k;
const int maxn = 1e5 + 5;
int a[maxn];
set<pair<int,int> > s;

queue<int> q[maxn];
int tot;
int main(){
	cin >> T;
	while(T--){
		cin >> n >> k;
		tot = 0;
		for(int i = 1;i <= n;i++){
			while(!q[i].empty()){
				q[i].pop();
			}
		}
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			if(!ID.count(a[i])){
				ID[a[i]] = ++tot;
			}
			q[ID[a[i]]].push(i);
		}
		s.clear();
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(s.find(make_pair(-q[ID[a[i]]].front(),ID[a[i]])) != s.end()){
				cout << "!" << i << endl;
				s.erase(make_pair(-q[ID[a[i]]].front(),ID[a[i]]));
				int nxt;
				if(q[ID[a[i]]].empty()) nxt = n + 1;
				else nxt = q[ID[a[i]]].front();
				s.insert(make_pair(-nxt,ID[a[i]]));
			}else{
				cout << "%" << i << endl;
				if(s.size() == k){
					s.erase(s.begin());
				}
				int nxt;
				if(q[ID[a[i]]].empty()) nxt = n + 1;
				else nxt = q[ID[a[i]]].front();
				s.insert(make_pair(-nxt,ID[a[i]]));
				ans++;
			}
			q[ID[a[i]]].pop();
		}	
		cout << ans << endl;
	}

	return 0;
}
