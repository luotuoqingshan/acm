#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 55;

int a[maxn][maxn];

vector<pair<int, pair<int,int> > >ans;


bool work(vector<int> v){
	if(v.size() == 1) return true;
	int ui,vi,mi = 1e9;
	for(int i = 0;i < v.size();i++){
		for(int j = i + 1;j < v.size();j++){
			if(a[v[i]][v[j]] < mi){
				mi = min(mi,a[v[i]][v[j]]);
				ui = v[i],vi = v[j];
			}
		}
	}
	vector<int> v1,v2;
	v1.push_back(ui),v2.push_back(vi);
	ans.push_back(make_pair(mi,make_pair(ui,vi)));
	for(int i = 0;i < v.size();i++){
		int node = v[i];
		if(node == ui || node == vi) continue;
		if(a[node][ui] == mi) v2.push_back(node);
		else v1.push_back(node);	
	}
	for(int i = 0;i < v1.size();i++){
		for(int j = 0;j < v2.size();j++){
			if(a[v1[i]][v2[j]] != mi) return false;
		}
	}
	return work(v1) && work(v2);
}
int n;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	vector<int> v;
	for(int i = 1;i <= n;i++) v.push_back(i);
	if(!work(v)){
		puts("NO");
	}else{
		printf("%d\n",(int)ans.size());
		for(int i = 0;i < ans.size();i++){
			printf("%d %d %d\n",ans[i].second.first,ans[i].second.second,ans[i].first);
		}
	}
	return 0;
}
