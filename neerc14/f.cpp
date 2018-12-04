#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int maxn = 1005;
int m,f,n;
int a[maxn];
char s[maxn][maxn];

bitset<1000> b[maxn];

int id(char c){
	if(c >= '0' && c <= '9') return c - 0;
	return c - 'a' + 10;
}
int num[maxn];
vector<int> ans;
int main(){
	scanf("%d%d",&m,&f);
	for(int i = 1;i <= f;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%s",s[i] + 1);
		int len = strlen(s[i] + 1);
		for(int j = 1;j <= len;j++){
			int tmp = id(s[i][j]);
			if(j * 4 - 3 <= m && tmp & 1){
				b[i].set(j * 4 - 4);
			}
			tmp /= 2;
			if(j * 4 - 2 <= m && tmp & 1){
				b[i].set(j * 4 - 3);
			}	
			tmp /= 2;
			if(j * 4 - 1 <= m && tmp & 1){
				b[i].set(j * 4 - 2);
			}
			tmp /= 2;
			if(j * 4 <= m && tmp & 1){
				b[i].set(j * 4 - 1);
			}
			tmp /= 2;
		}
	}	
	int q;
	scanf("%d",&q);
	for(int i = 1;i <= q;i++){
		int u;
		scanf("%d",&u);
		bitset<1000> tmp(0);
		for(int j = 1;j <= f;j++){
			tmp.set(a[j] * 1LL * u % m);	
		}
		for(int j = 1;j <= n;j++){
			if((tmp & b[j]).count() == tmp.count()){
				num[j]++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(num[i] > 0){
			ans.push_back(i - 1);
		}
	}
	cout << ans.size();
	for(int i = 0;i < ans.size();i++){
		cout << " " << ans[i];	
	}
	cout << endl;
	return 0;
}
