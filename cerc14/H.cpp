#include<cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
int a[305],tot;

int row[10] = {4,1,1,1,2,2,2,3,3,3};
int col[10] = {2,1,2,3,1,2,3,1,2,3};
bool check(int x){
	int b[10],num;
	num = 0;
	while(x > 0){
		b[++num] = x % 10;
		x /= 10;
	}
	reverse(b + 1,b + 1 + num);
	for(int i = 1;i < num;i++){
		if(row[b[i]] <= row[b[i + 1]] && col[b[i]] <= col[b[i + 1]]) continue;
		return false;
	}
	return true;
}

void init(){
	tot = 0;
	for(int i = 0;i <= 200;i++){
		if(check(i)){
			a[++tot] = i;
		}
	}	
}

int main(){
	int T;
	cin >> T;
	init();
	while(T--){
		int k;
		scanf("%d",&k);
		int id = lower_bound(a + 1,a + 1 + tot,k) - a;
		if(k - a[id - 1] < a[id] - k){
			printf("%d\n",a[id - 1]);
		}else{
			printf("%d\n",a[id]);
		}
	}
	return 0;
}
