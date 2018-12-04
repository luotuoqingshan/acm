#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;
typedef double db;
db f[maxn];

int n,m;



int main(){
	cin >> n >> m;
	swap(n,m);
	f[1] = 1;
	for(int i = 2;i <= n;i++){
		f[i] = (f[i - 1]) / m * f[i - 1] + (m - f[i - 1]) / m * (f[i - 1] + 1);
	}
	printf("%.10lf\n",f[n]);
	return 0;
}
