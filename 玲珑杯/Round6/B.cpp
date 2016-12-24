#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

long long a,b,p;

long long p10[100];
int n[100];
int tot;
long long ans;
long long num[100];

void init(){
	p10[0] = 1;
	for(int i = 1;i <= 15;i++){
		p10[i] = p10[i - 1] * 10LL;
	}
}

long long cal(long long x){
	tot = 0;
	long long ret = 0;
	while(x > 0){
		n[++tot] = x % 10;
		x /= 10;
	}
	num[0] = 0;
	for(int i = 1;i <= tot;i++){
		num[i] = num[i - 1] + (long long)n[i] * p10[i - 1];
	}
	for(int i = tot;i >= 1;i--){
		if(i > 1)ret += (long long)n[i] * (i - 1) *  p10[i - 2];
		//cout << ret << endl;
		if(p < n[i]) ret += (long long) p10[i - 1];
		//cout << ret << endl;
		else if(p == n[i]) ret += (long long) (num[i - 1] + 1);
		//cout << ret << endl;
	}
	return ret;
}

long long solve(long long x){
	long long ret = 0;
	for(int i = 1;i <= x;i++){
		int tmp = i;
		tot = 0;
		while(tmp > 0){
			n[++tot] = tmp % 10;
			if(n[tot] == p) ret++;
			tmp /= 10;
		}
	}
	return ret;
}




int main(){
	int T;
	cin >> T;init();
	//p = 2;
	//cout << solve(200) << " " << cal(200) << endl;
	//cout << cal(201) << endl;
	/*for(int i = 1;i <= 1000;i++){
		if(solve(i) != cal(i)) cout << i << endl,cout << solve(i) << " "<< cal(i) << endl;
	}*/
	while(T--){
		cin >> a >> b >> p;
		ans = 0;
		
		ans = cal(b) - ((a > 0) ? cal(a - 1) : 0);
		cout << ans << endl;
	}
	return 0;
}
