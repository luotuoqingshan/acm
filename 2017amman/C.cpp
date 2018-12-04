#include <cstdio>
#include <iostream>

using namespace std;
int main(){
	int a,b,c;
	int T;
	cin >> T;
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		if(a < b && a < c){
			printf("First\n");
			continue;
		}
		if(b < a && b < c){
			printf("Second\n");
			continue;
		}
		if(c < a && c < b){
			printf("Third\n");
			continue;
		}
	}
	return 0;
}
