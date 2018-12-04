#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int maxn = 1005;

int d[maxn];
int n;

void output(){
	for(int i = 1;i <= n;i++){
		printf("%d",d[i]);
	}
	printf("\n");
	fflush(stdout);
}

int part1(){
	for(int i = 1;i <= n;i++){
		d[i] = rand() % 2;
	}
	output();
	int x;
	cin >> x;
	return x;
}

int a[maxn];
int x[maxn];

void part2(){
	for(int i = 1;i <= n;i++){
		a[i] = d[i];
	}
	for(int i = 2;i <= n;i++){
		d[1] ^= 1;
		d[i] ^= 1;
		output();
		int ret = 0;cin >> ret;
		if(ret == n){
			return;
		}
		if(ret == n / 2) x[i] = 1;
		else x[i] = 0;
		d[1] ^= 1;
		d[i] ^= 1;	
	}
	for(int i = 2;i <= n;i++){
		d[i] ^= x[i];	
	}
	output();
	int x;
	cin >> x;
	if(x == n) return;
	for(int i = 1;i <= n;i++){
		d[i] ^= 1;
	}

	output();
	cin >> x;
	if(x == n) return;
}

int main(){
	srand(time(0));
	cin >> n;
	int tmp;
	while((tmp = part1()) == 0){}
	if(tmp == n){
		return 0;
	}	
	if(tmp == n / 2){
		part2();	
	}
	return 0;
}
