#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int a[15];

char s[105];
int d[105];
int main(){
	scanf("%s",s);
	for(int i = 0;i < 10;i++){
		a[i] = i;
	}
	int ans = 0;
	do{
		int len = strlen(s);
		for(int i = 0;i < len;i++){
			d[i] = a[s[i] - '0'];
		}	
		int now = 0;
		for(int i = 0;i < 10 && now < len;i++){
			while(now < len && d[now] != i){
				now++;
			}
		}	
		if(now < len) ans++;
	}while(next_permutation(a,a + 10));
	cout << ans << endl;
	return 0;
}
