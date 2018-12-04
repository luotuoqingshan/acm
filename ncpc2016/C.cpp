#include <cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 1005;

int n;

char str[maxn];

int main(){
	cin >> n;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		scanf("%s",str + 1);
		int len = strlen(str + 1);
		bool flag = true;
		for(int j = 1;j < len;j++){
			if(str[j] == 'C' && str[j + 1] == 'D')
				flag = false;
		}
		ans += flag;
	}
	cout << ans << endl;
	return 0;
}
