#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;

const int maxn = 1000;
const int maxm = 5e6 + 5;

char str[maxm];



int n;

bitset<maxn> b[10];
bitset<maxn> D;



int main(){
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			int num;
			scanf("%d",&num);
			for(int j = 1;j <= num;j++){
				int x;
				scanf("%d",&x);
				b[x].set(i);
			}
		}
		getchar();
		gets(str);
		int len = strlen(str);
		for(int i = 0;i < len;i++){
			int x = str[i] - '0';
			D = D << 1;
			D.set(0);
			D &= b[x];
			if(D[n - 1] != 0){
				char c = str[i + 1];
				str[i + 1] = 0;
				puts(str + i - n + 1);
				str[i + 1] = c;
			}
		}		
	}
	return 0;
}
