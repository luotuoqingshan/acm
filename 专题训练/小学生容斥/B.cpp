#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

bool vis[25];

long long gcd(long long a,long long b){
    return b == 0 ? a : gcd(b,a % b);
}

int m;
long long n;

long long p[25];
typedef long long ll;
long  long solve(int c){
    ll ans = 0;
    for(int i = 1;i < (1 << c);i++){
        ll ret = 1;
        int num = 0;
        for(int j = 1;j <= c;j++) if(i & (1 << (j - 1))){
            ret = ret / gcd(ret,p[j]) * p[j];
            num++;
        }
        if(num & 1) ans += n / ret;
        else ans -= n / ret;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    while(cin >> n >> m){
        n--;
        memset(vis,false,sizeof(vis));
        int cnt = 0;
        for(int i = 1;i <= m;i++){
            int x;
            scanf("%d",&x);
            if(!vis[x] && x != 0) p[++cnt] = (long long)x;
            vis[x] = true;
        }
        cout << solve(cnt) << endl;
    }
    return 0;
}
