#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
int n;
int main(){
	freopen("test10.in","r",stdin);
	freopen("test10.out","w",stdout);
	cin >> n;
	long long sum = 0;
	for(int i = 1;i <= n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		sum += x;
		a[i] = y - x; 
	}
	sort(a + 1,a + 1 + n);
	for(int i = n / 2 + 1;i <= n;i++){
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}
