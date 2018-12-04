#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 2005;

int c[maxn];

int q;
queue<int> ans;
int main(){
	int n;
	cin >> n;
	q = 0;
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		int m;
		scanf("%d",&m);
		if(m > 0){
			c[m + 1000]++;
		}else if(m < 0){
			if(c[-m + 1000] > 0){
				c[-m + 1000]--;
			}else{
				if(q > 0){
					q--;
					ans.push(-m);
				}else flag = 0;
			}
		}else{
			q++;	
		}
	}
	if(flag){
		printf("Yes\n");
		int l = ans.size();
		for(int i = 1;i <= l;i++){
			printf("%d ",ans.front());
			ans.pop();
		}
		for(int i = 1;i <= q;i++){
			printf("%d ",1);
		}
	}else{
		printf("No\n");
	}
	return 0;
}
