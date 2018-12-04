#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 3100;
const int INF = 1550;
const int INF1 = 3100;
int g[2 * maxn][2 * maxn];
int g1[maxn * 2][maxn * 2];
int a[maxn * 2];
int b[maxn * 2];
int m,l;
const int N = 200005;

struct event{
	int l,r,y;
	int type;
	event(int l = 0,int r = 0,int y = 0,int type = 0):l(l),r(r),y(y),type(type){}
	bool operator < (const event & rhs) const{
		return y < rhs.y;
	}
}e[N * 2],d[N * 2];

int main(){
	memset(g,0,sizeof(g));
	memset(g1,0,sizeof(g1));
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		char s[3];
		scanf("%s",s);
			int x,y,a;
			scanf("%d%d%d",&x,&y,&a);
		if(s[0] == 'A'){
			e[++m] = event(y - a / 2,y + a / 2,x - a / 2,1);
			e[++m] = event(y - a / 2,y + a / 2,x + a / 2,-1);	
		}	
		else{
			d[++l] = event(x + y - a / 2,x + y + a / 2,y - x - a / 2,1);
			d[++l] = event(x + y - a / 2,x + y + a / 2,y - x + a / 2,-1);	
		}
	}
	sort(e + 1,e + 1 + m);
	sort(d + 1,d + 1 + l);
	int S1 = 0,S2 = 0;
	for(int i = -1525,r = 0;i <= 1525;i++){
		memset(a,0,sizeof(a));
		int tmp = r;
		while(r < m && e[r + 1].y <= i){
			r++;	
		}	
		for(int j = tmp + 1;j <= r;j++){
			a[e[j].l + INF] += e[j].type;
			a[e[j].r + INF] -= e[j].type;	
		}
		int now = 0;
		for(int j = -1525;j <= 1525;j++){
			now += a[j + INF];
			g[i + INF][j + INF]  = g[i - 1 + INF][j + INF] + now;
			if(g[i + INF][j + INF] > 0){
				S1++;
			}
		}
	}
	for(int i = -3025,r = 0;i <= 3025;i++){
		memset(b,0,sizeof(b));
		int tmp = r;
		while(r < l && d[r + 1].y <= i){
			r++;
		}
		for(int j = tmp + 1;j <= r;j++){
			b[d[j].l + INF1] += d[j].type;
			b[d[j].r + INF1] -= d[j].type;
		}
		int now = 0;
		for(int j = -3025;j <= 3025;j++){
			now += b[j + INF1];
			g1[i + INF1][j + INF1] = g1[i - 1 + INF1][j + INF1] + now;
			if(g1[i + INF1][j + INF1] > 0) {S2++;}
		}
	}
//	cout << S1 << " " << S2 << endl;
	S2 /= 2;
	double ans = S1 + S2 * 1.0;
	for(int i = -1525;i <= 1525;i++){
		for(int j = -1525;j <= 1525;j++){
			if(g[i + INF][j + INF] > 0){
				if(g1[j - i + INF1][i + j + INF1] > 0){
					ans -= 0.25;
				}		
				if(g1[j - i + INF1][i + j + 1 + INF1] > 0){
					ans -= 0.25;
				}
				if(g1[j - i - 1 + INF1][i + j + 1 + INF1] > 0){
					ans -= 0.25;
				}
				if(g1[j - i - 1 + INF1][i + j + INF1] > 0){
					ans -= 0.25;
				}
			}		
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
