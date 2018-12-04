#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int cas = 1;cas <= T;cas++){
		int n;
		scanf("%d",&n);
		printf("Case #%d: %d\n",cas,n / 3);
	}
	return 0;
}
