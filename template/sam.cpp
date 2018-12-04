struct Sam{
    int fail[maxn * 2];
    int ch[maxn * 2][256];int tot,last;
    int mx[maxn * 2];
    int ans;
    void clear(int i){
        memset(ch[i],0,sizeof(ch[i]));
    }
    void clear(){
        tot = last = 1;
        ans = 0;
        clear(0);clear(1);
    }
    Sam(){
        tot = last = 1;
        ans = 0;
        clear(0);clear(1);
    }
    int cal(int x){
        return mx[x] - mx[fail[x]];
    }
    void add(int c){
        int p = last,np = last = ++tot;clear(tot);
        mx[np] = mx[p] + 1;
        while(p && ch[p][c] == 0) ch[p][c] = np,p = fail[p];
        if(!p) fail[np] = 1,ans += cal(np);
        else{
            int q = ch[p][c];
            if(mx[q] == mx[p] + 1) fail[np] = q,ans += cal(np);
            else{
                int nq = ++tot;clear(tot);mx[nq] = mx[p] + 1;
                memcpy(ch[nq],ch[q],sizeof(ch[nq]));
                fail[nq] = fail[q];ans+=cal(nq)-cal(q);
                fail[q] = fail[np] = nq;ans+=cal(np)+cal(q);
                while(p && ch[p][c] == q) ch[p][c] = nq,p = fail[p];
            }
        }
    }
}sam;

