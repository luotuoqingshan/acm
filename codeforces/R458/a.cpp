#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[233333];
int pos;
int f[233333];
int judge(int x){
	int i;
	if(f[x] != -1) return f[x];
	if(!a[x]) return f[x] = 0;
	for(i = x;i >= 1;i--){
		if(a[i]){
			a[i]--;
			if(judge(i) == 0){
				return f[x] = 1;
			}
			a[i]++;
		}
	}
	return f[x] = 0;
}
int main(){
	cin >> n;
	int pos = -1e6;
	for(int i = 1;i <= n;i++){
		int tmp;
		scanf("%d",&tmp);
		a[tmp]++;
		pos = max(tmp,pos);
	}
	memset(f,-1,sizeof(f));
	printf("%s",judge(pos) > 0 ? "c" : "a");
	return 0;
}
