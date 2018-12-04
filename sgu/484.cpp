#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

char s[105][105];

int main(){
	int n,m;
	cin >> n >> m;
	int sx,sy;
	for(int i = 1;i <= n;i++){
		scanf("%s",s[i] + 1);
		for(int j = 1;j <= m;j++){
			if(s[i][j] == 'P'){
				sx = i,sy = j;
				s[i][j] = '.';
			}
		}	
	}
	while(sx <= n){
		if(s[sx][sy] == '.'){
			sx++;
		}else if(s[sx][sy] == '/'){
			if(sy == 1) break;
			if(s[sx][sy - 1] == '\\'){
				break;
			}
			sy--;
		}else if(s[sx][sy] == '\\'){
			if(sy == m) break;
			if(s[sx][sy + 1] == '/'){
				break;
			}
			sy++;
		}
	}
	if(sx <= n){
		printf("-1\n");
	}else{
		printf("%d\n",sy);
	}
	return 0;
}
