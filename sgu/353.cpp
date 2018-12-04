#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


int n,k1,k2,p1,p2,p3;

int main(){
	cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;
	int ans = 0;
	if(n >= p1){
		n -= p1;
		ans += k1;
	if(n >=1LL *  p2 * k2){
		n -= p2 * k2;
		ans += k2;
		ans += (n + p3 - 1) / p3;
	}else{
		ans += (n + p2 - 1) / p2;
	}
	}
	cout << ans << endl;
	return 0;
}
