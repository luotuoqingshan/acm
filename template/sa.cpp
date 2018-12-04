struct SuffixArray{
public:
    const static int MAXN = 100000 + 10;
    int cnt[MAXN],tr[2][MAXN],ts[MAXN];
    int sa[MAXN],rk[MAXN],ht[MAXN],len;
    void construct(const char * s,int n,int m = 256){
        int i,j,k,*x = tr[0],*y = tr[1];
        this->len = n;
        memset(cnt,0,sizeof(cnt[0]) * m);
        for(i = 0;i < n;i++) cnt[s[i]]++;
        partial_sum(cnt,cnt + m,cnt);
        for(i = 0;i < n;i++) rk[i] = cnt[s[i]] - 1;
        for(k = 1;k <= n;k <<= 1){
            for(i = 0;i < n;i++) x[i] = rk[i],y[i] = i + k < n ? rk[i + k] + 1:0;
            fill(cnt,cnt + n + 1,0);
            for(i = 0;i < n;i++) cnt[y[i]]++;
            partial_sum(cnt,cnt + n + 1,cnt);
            for(i = n - 1;i >= 0;i--) ts[--cnt[y[i]]] = i;
            fill(cnt,cnt + n + 1,0);
            for(i = 0;i < n;i++) cnt[x[i]]++;
            partial_sum(cnt,cnt + n + 1,cnt);
            for(i = n - 1;i >= 0;i--) sa[--cnt[x[ts[i]]]] = ts[i];
            for(i = rk[sa[0]] = 0;i + 1 < n;++i){
                rk[sa[i + 1]] = rk[sa[i]] + (x[sa[i]] != x[sa[i + 1]] || (y[sa[i]] != y[sa[i + 1]]));
            }
        }
        for(i = 0,k = 0;i < n;++i){
            if(!rk[i]) continue;
            for(j = sa[rk[i] - 1];i + k < n && j + k < n && s[i + k] == s[j + k];)k++;
            ht[rk[i]] = k;
            if(k) k--;
        }
        rmq_init(n);
    }
    inline int lcp(int a,int b){
        a = rk[a],b = rk[b];
        if(a == b) return len - a + 1;
        if(a > b) swap(a,b);
        return rmq(a + 1,b);
    }
private:
    int mx[MAXN][20],LOG[MAXN];
    void rmq_init(int n){
        for(int i = -(LOG[0]=-1);i < n;i++) LOG[i] = LOG[i >> 1] + 1;
        for(int i = 0;i < n;i++) mx[i][0] = ht[i];
        for(int i,j = 1;(1 << j) < n;++j){
            for(i = 0;i + (1 << j) <= n;++i){
                mx[i][j] = min(mx[i][j - 1],mx[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    inline int rmq(int a,int b){
        int k = LOG[b - a + 1];
        return min(mx[a][k],mx[b - (1 << k) + 1][k]);
    }
};
