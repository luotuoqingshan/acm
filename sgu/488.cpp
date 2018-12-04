#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int T;

int n;
const int maxn = 1e6 + 5;

int a[maxn];

int l[maxn],r[maxn];
int st[maxn],tot;
int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		l[1] = 1;
		for(int i = 2;i <= n;i++){
			if(a[i] <= a[i - 1]){
				l[i] = 1;
			}else{
				l[i] = l[i - 1] + 1;
			}
		}
		r[n] = 1;
		for(int i = n - 1;i >= 1;i--){
			if(a[i] <= a[i + 1]){
				r[i] = 1;
			}else{
				r[i] = r[i + 1] + 1;
			}
		}
		int height = 0;
		for(int i = 1;i <= n;i++){
			height = max(height,min(l[i] - 1,r[i] - 1));
		}
		l[1] = 1;
		for(int i = 2;i <= n;i++){
			if(a[i] >= a[i - 1]){
				l[i] = 1;
			}else{
				l[i] = l[i - 1] + 1;
			}
		}
		r[n] = 1;
		for(int i = n - 1;i >= 1;i--){
			if(a[i] >= a[i + 1]){
				r[i] = 1;
			}else{
				r[i] = r[i + 1] + 1;
			}
		}
		int depth = 0;
		for(int i = 1;i <= n;i++){
			depth = max(depth,min(l[i] - 1,r[i] - 1));
		}
		printf("%d %d\n",height,depth);
	}
	return 0;
}
