#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int lowbit(int x){
	return x & -x;
}

const int N = 1005;

int n;
int mat[N][N];

void add(int x, int y, int d) {
    int i, j;
    for(i = x; i < N; i += lowbit(i))
        for(j = y; j < N; j += lowbit(j))
            mat[i][j] += d;
}

int sum(int x, int y) {
    int res = 0;
    int i, j;
    for(i = x; i > 0; i -= lowbit(i))
        for(j = y; j > 0; j -= lowbit(j))
            res += mat[i][j];
    return res;
}

int q;

int main(){
	int T;
	cin >> T;
	bool first = false;
	while(T--){
		if(!first) first = true;
		else cout << endl;
		cin >> n >> q;
		memset(mat,0,sizeof(mat));
		for(int i = 1;i <= q;i++){
			char str[3];
			scanf("%s",str);
			if(str[0] == 'Q'){
				int x,y;
				scanf("%d%d",&x,&y);
				int ans = sum(x,y);
				printf("%d\n",ans);
			}else{
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				add(x1,y1,1);
				add(x2 + 1,y2 + 1,1);
				add(x1,y2 + 1,-1);
				add(x2 + 1,y1,-1);
			}
		}
		//cout << endl;
	}
	return 0;
}
