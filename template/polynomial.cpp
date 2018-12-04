#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T>inline void read(T &x){
    x=0;char ch;bool flag = false;
    while(ch=getchar(),ch<'!');if(ch == '-') ch=getchar(),flag = true;
    while(x=10*x+ch-'0',ch=getchar(),ch>'!');if(flag) x=-x;
}
const int pri_rt = 3;
const int maxn=600010;
const int mod=998244353;
const int inv_2 = 499122177;
int n,k,N,C,len;
int rev[maxn],w[maxn];
int f[maxn];
int Inv[maxn],Ln[maxn],Exp[maxn],Sqrt[maxn];
inline int qpow(int x,int p){
    int ret = 1;
    for(;p;x=1LL*x*x%mod,p>>=1) if(p&1) ret=1LL*ret*x%mod;
    return ret;
}
inline int check(int &x){
    if(x < 0) x += mod;
    if(x >= mod) x -= mod;
}
void FNT(int n,int *x,int flag){
    for(int i=0,t=0;i<n;++i){
        if(i > t) swap(x[i],x[t]);
        for(int j=n>>1;(t^=j) < j;j>>=1);
    }
    for(int m=2;m<=n;m<<=1){
        int k = m>>1;
        int wn = qpow(pri_rt,flag == 1 ? (mod - 1)/m : (mod-1) - (mod-1)/m);
        w[0] = 1;
        for(int i=1;i<k;++i) w[i] = 1LL*w[i-1]*wn % mod;
        for(int i=0;i<n;i+=m){
            for(int j=0;j<k;++j){
                int u = 1LL*x[i+j+k]*w[j] % mod;
                x[i+j+k] = x[i+j] - u;check(x[i+j+k]);
                x[i+j] = x[i+j] + u;check(x[i+j]);
            }
        }
    }
    if(flag == -1){
        int inv = qpow(n,mod-2);
        for(int i=0;i<n;++i) x[i] = 1LL*x[i]*inv%mod;
    }
}
inline void get_dao(int n,int *f){
    for(int i=0;i<n;++i) f[i] = 1LL*f[i+1]*(i+1) % mod;
    f[n] = 0;
}
inline void get_fen(int n,int *f){
    for(int i=n-1;i>=0;--i) f[i] = 1LL*f[i-1]*qpow(i,mod-2) % mod;
    f[0] = 0;
}
void get_inv(int n,int *f){
    static int g[maxn];
    if(n == 1){
        Inv[0] = qpow(f[0],mod-2);
        return;
    }
    get_inv((n+1)>>1,f);
    int len = n<<1;
    for(int i=0;i<n;++i) g[i] = f[i];
    fill(g+n,g+len,0);
    FNT(len,g,1);FNT(len,Inv,1);
    for(int i=0;i<len;++i){
        Inv[i] = 1LL*Inv[i]*(2LL - 1LL*g[i]*Inv[i]%mod + mod) % mod;
    }FNT(len,Inv,-1);fill(Inv+n,Inv+len,0);
}
void get_ln(int n,int *f){
    int len = n<<1;
    fill(Inv,Inv+(len<<1),0);
    get_inv(n,f);get_dao(n,f);
    FNT(len,f,1);FNT(len,Inv,1);
    for(int i=0;i<len;++i) Ln[i] = 1LL*f[i]*Inv[i] % mod;
    FNT(len,Ln,-1);fill(Ln+n,Ln+len,0);
    get_fen(n,Ln);
}
void get_exp(int n,int *f){
    static int g[maxn];
    if(n == 1){
        Exp[0] = 1;
        return;
    }
    get_exp(n>>1,f);
    int len = n<<1;
    for(int i=0;i<n;++i) g[i] = Exp[i];
    fill(g+n,g+len,0);
    get_ln(n,g);
    for(int i=0;i<n;++i) Ln[i] = ((i == 0) - Ln[i] + f[i] + mod) % mod;
    FNT(len,Ln,1);FNT(len,Exp,1);
    for(int i=0;i<len;++i) Exp[i] = 1LL*Exp[i]*Ln[i] % mod; 
    FNT(len,Exp,-1);fill(Exp+n,Exp+len,0);
}
void get_sqrt(int n,int *f){
    static int g[maxn];
    if(n == 1){
        Sqrt[0] = sqrt(f[0]);
        return;
    }
    get_sqrt(n>>1,f);
    int len = n<<1;
    fill(Inv,Inv+(len<<1),0);get_inv(n,Sqrt);
    for(int i=0;i<n;++i) g[i] = f[i];
    fill(g+n,g+len,0);
    FNT(len,g,1);FNT(len,Inv,1);
    for(int i=0;i<len;++i) g[i] = 1LL*g[i]*Inv[i] % mod;
    FNT(len,g,-1);
    for(int i=0;i<n;++i) Sqrt[i] = 1LL*(Sqrt[i] + g[i])*inv_2%mod;
}
void get_pow(int len,int *f,int p){
    get_ln(len,f);
    for(int i=0;i<len;++i) f[i] = 1LL*p*Ln[i]%mod;
    fill(Exp,Exp+(len<<1),0);
    get_exp(len,f);
}
int main(){
    int n,k;read(n);read(k);
    for(int i=0;i<n;++i) read(f[i]);
    for(len=1;len<=n;len<<=1);
    get_sqrt(len,f);
    
    fill(Inv,Inv+(len<<1),0);get_inv(len,Sqrt);
    for(int i=0;i<len;++i) f[i] = Inv[i];

    get_fen(len,f);fill(f+n,f+len,0);
    
    get_exp(len,f);
    for(int i=0;i<len;++i) f[i] = Exp[i];

    fill(Inv,Inv+(len<<1),0);get_inv(len,f);
    for(int i=0;i<len;++i) f[i] = Inv[i];
    ++f[0];

    get_ln(len,f);
    for(int i=0;i<len;++i) f[i] = Ln[i];
    ++f[0];

    fill(f+len+1,f+(len<<1),0);

    get_pow(len,f,k);

    for(int i=1;i<n;++i) printf("%d ",1LL*Exp[i]*i % mod);
    puts("0");
    getchar();getchar();
    return 0;
}
