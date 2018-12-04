#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 2006;

int main(){

	int n;
	int a[maxn];
	while(cin >> n){
		bool flag = true;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		for(int i = 1;i < n;i++){
			if(a[i + 1] < a[i]) flag = false;
		}
		if(flag) puts("yes");
		else puts("no");
	}
	return 0;
}
