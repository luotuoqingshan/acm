#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a,b,c;

int main(){
	cin >> a >> b >> c;
	if(a >= b && a >= c){
		if(a > b * c){
			printf("-1\n");
			return 0;
		}else{
			if(a >= b + c - 1){
				printf("%d\n",a);
				for(int i = 1;i <= b;i++){
					printf("%d 0 0\n",i - 1);
				}
				for(int i = 1;i <= c - 1;i++){
					printf("0 %d 0\n",i);
				}
				a -= (b + c - 1);
				for(int i = 1;i <= b - 1 && a > 0;i++){
					for(int j = 1;j <= c - 1 && a > 0;j++,a--){
						printf("%d %d 0\n",i,j);
					}
				}
				return 0;
			}
		}
	}
	else if(b > a && b >= c){

		if(b > a * c){
			printf("-1\n");
			return 0;
		}else{
			if(b >= a + c - 1){
				printf("%d\n",b);
				for(int i = 1;i <= a;i++){
					printf("%d 0 0\n",i - 1);
				}
				for(int i = 1;i <= c - 1;i++){
					printf("0 0 %d\n",i);
				}
				b -= (a + c - 1);
				for(int i = 1;i <= a - 1 && b > 0;i++){
					for(int j = 1;j <= c - 1 && b > 0;j++,b--){
						printf("%d 0 %d\n",i,j);
					}
				}
				return 0;
			}
		}
	}else{
		if(c > a * b){
			printf("-1\n");
			return 0;
		}else{
			if(c >= b + a - 1){
				printf("%d\n",c);
				for(int i = 1;i <= b;i++){
					printf("0 0 %d\n",i - 1);
				}
				for(int i = 1;i <= a - 1;i++){
					printf("0 %d 0\n",i);
				}
				c -= (b + a - 1);
				for(int i = 1;i <= a - 1 && c > 0;i++){
					for(int j = 1;j <= b - 1 && c > 0;j++,c--){
						printf("0 %d %d\n",i,j);
					}
				}
			    return 0;
			}
		}
	}	
	int d = (a + b - c);
	if(d % 2 == 0){
		a--,b--,c--;
	}
 					int x = (a + b - c + 1) / 2;
					int y = (a + c - b + 1) / 2;	
					int z = (b + c - a + 1) / 2;
					if(d % 2 == 1)printf("%d\n",x + y + z - 2);
					else printf("%d\n",x + y + z - 1);
					for(int i = 1;i < x;i++){
						printf("%d 0 0\n",i);
					}
					for(int i = 1;i < y;i++){
						printf("0 %d 0\n",i);
					}
					for(int i = 1;i < z;i++){
						printf("0 0 %d\n",i);
					}
					printf("0 0 0\n");
					if(d % 2 == 0) printf("-100 -100 -100\n");
	return 0;
}
