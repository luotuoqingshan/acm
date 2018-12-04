#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n;

const int maxn = 5000;
int a[maxn];
int c[maxn];
int power[15];
long double p[15][maxn];
int main(){
	cin >> n;	
	power[0] = 1;
	for(int i = 1;i <= 12;i++){
		power[i] = power[i - 1] * 2;
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	int id = lower_bound(power + 1,power + 1 + 12,n) - power;
	int m = power[id];
	sort(a + 2,a + 1 + n);
	int left = m - n;
	for(int i = 1;i <= n;i++){
		c[i] = a[i];
	}
	int pid = 0;
	for(int i = 1;i <= n;i++){
		a[++pid] = c[i];
		if(left){
			a[++pid] = 0;
			left--;
		}
	}
	for(int i = 1;i <= m;i++){
		p[0][i] = 1;
	}
	for(int i = 1;(1 << i) <= m;i++){
		int step = (1 << i);
		for(int j = 1;j <= m;j += step){
			for(int k = j;k < j + step / 2;k++){
				for(int l = j + step / 2;l < j + step;l++){
					p[i][k] += p[i - 1][k] * p[i - 1][l] * a[k] / (a[k] + a[l]);
					p[i][l] += p[i - 1][k] * p[i - 1][l] * a[l] / (a[k] + a[l]);
				}
			}	
		}
	}
	printf("%.18Lf\n",p[id][1]);
	return 0;
}
