#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int n;
const int maxn = 55;
int a[maxn];

int main(){
	cin >> n;
	int id = 0,ans = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(abs(a[i]) > ans){
			ans = abs(a[i]);
			id = i;
		}
	}
	if(a[id] == 0){
		puts("0");
	}else if(a[id] > 0){
		printf("%d\n",2 * (n - 1));
		for(int i = 2;i <= n;i++){
			printf("%d %d\n",id,i);	
			printf("%d %d\n",id,i);	
			id = i;
		}	
	}else{
		printf("%d\n",2 * (n - 1));
		for(int i = n - 1;i >= 1;i--){
			printf("%d %d\n",id,i);	
			printf("%d %d\n",id,i);	
			id = i;
		}	
	}
	return 0;
}
