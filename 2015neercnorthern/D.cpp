#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int n;
const int maxn = 1000000;
int num[maxn];
long long sum[maxn];

int a[10],tot;

int main(){
	cin >> n;
	for(int i = 1;i <= 10000000;i++){
		tot = 0;
		int tmp = i;
		int s = 0;
		while(tmp > 0){
			s += tmp % 10;
			tmp /= 10;
		}	
		if(num[s] < n){
			num[s]++;
			sum[s] += i;	
		}
	}
	long long ans = 1e18;
	for(int i = 1;i < maxn;i++){
		if(num[i] == n){
			ans = min(ans,sum[i]);
		}		
	}
	cout << ans << endl;
	return 0;
}
