#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n,a,b;
int t[105];
int ans[105];
int main(){
	queue<int> q;
	cin >> n >> a >> b;
	for(int i = 1;i <= n;i++){
		scanf("%d",&t[i]);
	}
	int front = 1;
	int id = 0;
	for(int T = 1;T <= 2000;T++){
		while(front <= n && t[front] <= T){
			q.push(t[front++]);
		}
		if(T - q.front() >= b || q.size() >= a){
			int k = q.size();
			while(q.size() > k / 2){
				id++;
				q.pop();
				ans[id] = T;
			}
		}
	}	
	for(int i = 1;i <= id;i++){
		printf("%d%c",ans[i],i == n ? '\n' : ' ');
	}
	return 0;
}
