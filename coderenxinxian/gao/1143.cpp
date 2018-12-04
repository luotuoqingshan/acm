#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		scanf("%d",&n);
		if(n % 3 == 1){
			printf("%d\n",(n / 3) * 2);
		}else if(n % 3 == 2){
			printf("%d\n",(n / 3) * 2 + 1);
		}else{
			printf("%d\n",(n / 3) * 2);
		}	
	}
	return 0;
}
