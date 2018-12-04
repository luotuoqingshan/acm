#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;


int n,m;

vector<pair<int,int> > ans;

int main(){
	cin >> n >> m;
	for(int i = 2;i <= m;i += 2){
		ans.push_back(make_pair(1,i));
		ans.push_back(make_pair(n,i));
	}
	for(int i = 2;i <= n;i += 2){
		ans.push_back(make_pair(i,1));
		ans.push_back(make_pair(i,n));
	}
	cout << ans.size() / 2 << endl;
	for(int i = 0;i < ans.size();i += 2){
		cout << ans[i].first << " " << ans[i].second << " " << ans[i + 1].first << " " << ans[i + 1].second << endl;
	}
	return 0;
}
