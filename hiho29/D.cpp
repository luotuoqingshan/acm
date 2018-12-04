#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

multiset<int> s;
int n;
const int maxn = 5e5 + 5;
int a[maxn];
int opt[maxn];
long long f[maxn];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		a[i] = 1e9 - a[i];
	}	
	f[0] = 0,opt[0] = 0;
	for(int i = 1;i <= n;i++){
		cout << i << endl;
		if(a[i] >= opt[i - 1]){
			f[i] = f[i - 1];
			opt[i] = a[i];
			s.insert(a[i]);
		}else{
			f[i] = opt[i - 1] - a[i] + f[i - 1];
			s.insert(a[i]);
			s.insert(a[i]);
			s.erase(s.end());
			opt[i] = *s.end();
		}
	}
	cout << f[n] << endl;
	return 0;
}
