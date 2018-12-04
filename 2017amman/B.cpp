#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

char a[maxn],b[maxn];
int T;
int cnt[30];

int main(){
	cin >> T;
	while(T--){
		scanf("%s",a);
		scanf("%s",b);
		memset(cnt,0,sizeof(cnt));
		int len = strlen(b);
		for(int i = 0;i < len;i++){
			cnt[b[i] - 'a']++;
		}
		len = strlen(a);
		for(int i = 0;i < len;i++){
			if(cnt[a[i] - 'a'] == 0){
				cout << i << endl;
				break;
			}
			cnt[a[i] - 'a']--;
			if(i == len - 1){
				cout << len << endl;
			}
		}
	}
	return 0;
}
