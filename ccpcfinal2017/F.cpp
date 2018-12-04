# include <cstdio>
# include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
# define FOR(i, a, b) for (int i = a; i <= b; ++ i)
# define REP(i, n) FOR (i, 1, n)
# define REP_0N(i, n) FOR (i, 0, n)
# define NR 4005
typedef double ld;
const ld eps = 1e-8, inf = 1e9;
int n, m, type, id[NR], tp[NR]; ld a[50][1200];
void pivot (int r, int c) {
	swap (id[r + n], id[c]);
	ld t = -a[r][c]; a[r][c] = -1; REP_0N (i, n) a[r][i] /= t;
	REP_0N (i, m) if (a[i][c] && r != i) { t = a[i][c]; a[i][c] = 0; REP_0N (j, n) a[i][j] += t * a[r][j]; }
}
void solve () {
	ld t; REP (i, n) id[i] = i;
	while (true) {
		int i = 0, j = 0; ld _w = -eps;
		REP (k, m) if (a[k][0] < _w) _w = a[i = k][0]; if (!i) break;
		REP (k, n) if (a[i][k] > eps) { j = k; break; } if (!j) { printf ("Infeasible"); return; }
		pivot (i, j);
	}
	while (true) {
		int i = 0, j = 0; ld _w = eps;
		REP (k, n) if (a[0][k] > _w) _w = a[0][j = k]; if (!j) break; _w = inf;
		REP (k, m) if (a[k][j] < -eps && (t = -a[k][0] / a[k][j]) < _w) _w = t, i = k; if (!i) { printf ("Unbounded"); return; }
		pivot (i, j);
	}
	printf ("%.0f\n", a[0][0]);
	FOR (i, n + 1, n + m) tp[id[i]] = i - n;
//	if (type) REP (i, n) printf ("%.9f ", tp[i] ? a[tp[i]][0] : 0);
}
vector<int> d[50];
int N,M;
int A[50];
int main(){
	int T;
	cin >> T;
	for(int cas = 1;cas <= T;cas++){
		printf("Case #%d: ",cas);
		memset(a,0,sizeof(a));
		cin >> N >> M;
		for(int i = 0;i < N;i++) d[i].clear();
		int sum = 0;
		for(int i = 0;i < N;i++) scanf("%d",&A[i]);
		for(int mask = 1;mask < (1 << N);mask++){
			sum = 0;
			for(int i = 0;i < N;i++){
				if((mask >> i) & 1)
					sum += A[i];
			}
			if(sum <= M){
				for(int i = 0;i < N;i++){
					if((mask >> i) & 1)
						d[i].push_back(mask);
				}	
			}
		}
		n = (1 << N);	
		m = 0;
		for(int i = 0;i < N;i++){
			m++;
			for(auto x : d[i]){
				a[m][x] = 1;
			}
			a[m][(1 << N)] = -1;
			m++;
			for(auto x : d[i]){
				a[m][x] = -1;
			}
			a[m][(1 << N)] = 1;
		}
		++m;
		a[m][(1 << N)] = -1;
		a[m][0] = 1;
		++m;
		for(int i = 1;i <= (1 << N);i++){
			a[m][i] = -1;
		}
		a[m][0] = 1;
		a[0][(1 << N)] = 1;
		solve();
	}	
	return 0;
}

