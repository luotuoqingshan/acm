#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int R,C;
const int maxn = 1005;

int a[maxn][maxn];
int read(){
    int x=0;
    char ch;
    while ((ch=getchar()) && ch!='?' && (ch<'0' || ch>'9'));
    if (ch=='?') return 0;
    x=ch-'0';
    while ((ch=getchar()) && (ch>='0' && ch<='9')) x=(x<<1)+(x<<3)+ch-'0';
    return x;
}

void get_a(){

    for (int i=1;i<=R;i++){
        for (int j=1;j<=C;j++){
            a[i][j]=read();
        }
    }
    /*for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++) printf("%d%c",a[i][j],j==c?'\n':' ');
    }*/
}
int main(){
	cin >> T;
	int cas = 0;
	while(T--){
		cin >> R >> C;
		get_a();
		int cnt = 0;
		int tmpx,tmpy,tmp;
		int tmpx1,tmpy1,tmp1;
		for(int i = 1;i <= R;i++){
			for(int j = 1;j <= C;j++){
				if(a[i][j] != 0){
					cnt++;
					if(cnt == 1) {
						tmpx = i;
						tmpy = j;
						tmp = a[i][j];
					}else if(cnt == 2){
						tmpx1 = i;
						tmpy1 = j;
						tmp1 = a[i][j];
					}
				}
			}
		}
		printf("Case #%d: ",++cas);
		if(cnt == 0) puts("Yes");
		else if(cnt == 1){
			bool flag = false;
			for(int d1 = 1;d1  * d1 <=  tmp;d1++){
				if(tmp % d1 == 0){
			int 		d2 = tmp / d1;
					if(d1 >= min(tmpx,tmpy) && d2 >= max(tmpx,tmpy)){
						flag = true;
						break;
					}
				}
			}
			if(flag) puts("Yes");
			else puts("No");
		}else{
			bool flag = false;
			int i = tmpx1 - tmpx;
			int j = tmpy1 - tmpy;
			int d1,d2;
			for(d1 = 1;d1 * d1 <= tmp;d1++){
				if(tmp % d1 == 0){
			 		d2 = tmp / d1;
					if(1LL * (d1 + i) * (d2 + j) == tmp1) {flag = true; break;}
					if(1LL * (d1 + j) * (d2 + i) == tmp1) {flag = true;swap(d1,d2);break;}
				}
			}
			if(flag){
				if(d1 < tmpx || d2 < tmpy) puts("No");
				else{
					for(int i = 1;i <= R;i++){
						for(int j = 1;j <= C;j++){
							if(a[i][j] == 0) continue;
							if(1LL * (d1 + (i - tmpx)) * (d2 + (j - tmpy)) != a[i][j]) flag = false;
						}
					}
					if(flag) puts("Yes");
					else puts("No");
				}
			}
			else puts("No");
		}
	}
	return 0;
}
