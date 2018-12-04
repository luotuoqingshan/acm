#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 600000;

long long ans[maxn];
long long p10[25];
int d[20],tot;
int d1[20],tot1;

bool check(int x){
	tot = 0;
	int tmp = x;
	while(tmp > 0){
		d[++tot] = tmp % 2;
		tmp /= 2;
	}	
	long long t = 0;
	tot1 = 0;
	for(int i = 1;i <= tot;i++){
		t = t + d[i] * p10[i - 1];
		d1[++tot1] = t % 2;
		t /= 2;
		if(d1[tot1] != d[tot1]) return false;
	}	
	return true;
}

void duipai(){
	tot = 0;
	int tmp = x;
	while(tmp > 0){
		d[++tot] = tmp % 2;
		tmp /= 2;
	}	
	long long t = 0;
	tot1 = 0;
	for(int i = 1;i <= tot;i++){
		t = t + d[i] * p10[i - 1];
		d1[++tot1] = t % 2;
		t /= 2;
	}	
	reverse(d + 1,d + 1 + tot);
	reverse(d1 + 1,d1 + 1 + tot);
	for(int i = 1;i <= tot;i++){
		printf("%d",d[i]);
	}
	cout << endl;
	for(int i = 1;i <= tot;i++){
		printf("%d",d1[i]);
	}
	cout << endl;
}


void print(int x){
	tot = 0;
	int tmp = x;
	while(tmp > 0){
		d[tot++] = tmp % 2;
		tmp /= 2;
	}
	reverse(d ,d  + tot);
	for(int i = 0;i < tot;i++){
		printf("%d",d[i]);
	}
	cout << endl;
}

void init(){
	int num = 0;
	p10[0] = 1;
	for(int i = 1;i <= 24;i++){
		p10[i] = p10[i - 1] * 5;
	}
	for(int i = 1;i < maxn;i++){
		if(check(i)){
			ans[++num] = i;
		}
	}
	
}


int main(){
	init();	
	int n;
	cin >> n;
	print(ans[n]);
	return 0;
}
