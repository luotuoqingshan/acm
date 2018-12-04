#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c) != EOF){
		a += b;
		int ans = 0;
		while(a >= c){
			int tmp = a / c;
			ans += tmp;
			a = a % c;
			a += tmp;
		}
		cout << ans << endl;
	}
	return 0;
}
