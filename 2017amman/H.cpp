#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


int T;

int n;
int S;
const int maxn = 1e6 + 5;

char s[maxn];
int main(){
	cin >> T;
	while(T--){
		cin >> n >> S;
		for(int i = 1;i <= n / 2;i++){
			int digit = min(9,S / 2);	
			s[i] = '0' + digit;
			s[n - i + 1] = '0' + digit;
			S -= 2 * digit;
		}
		if(n & 1){
			int digit = min(9,S);
			s[n / 2 + 1] = '0' + digit;
			S -= digit;
		}
		if(S != 0){
			printf("-1\n");
		}else{
			if(s[1] == '0'){
				printf("-1\n");
			}else{
				s[n + 1] = 0;
				printf("%s\n",s + 1);
			}
		}
	}	
	return 0;
}
