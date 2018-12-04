#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a % b);
}

int main(){
	int n;
	cin >> n;
	if(n & 1){
		if(n == 1){
			printf("Yes\n");
			printf("1\n");
		}
		else{
			bool flag = false;
			int ans = 0;
			for(int i = 2;i <= n - 1;i += 2){
				if(gcd(i - 1,n) == 1 && gcd(i + 1,n) == 1 && gcd(i,n) == 1){
					flag = true;
					ans = i;
					break;
				}
			}
			if(!flag){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			for(int i = 1;i <= n;i++){
				int j = ans * (i - 1) % n + 1;
				for(int k = j;k < j + n;k++){
					printf("%d",(k - 1) % n + 1);
					if(k == j + n - 1){
						printf("\n");
					}else{
						printf(" ");
					}
				}
			}
			}
		}
	}else{
		printf("No\n");	
	}
	return 0;
}
