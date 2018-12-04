struct Ac{
    int ch[maxn * 50][26];
    int fail[maxn * 50];
    int val[maxn * 50];
    int q[maxn * 50];
    int tot;
    Ac(){}
    int id(char c){
        return c - 'a';
    }
    void init(){
        tot = 0;
        fail[0] = -1;memset(ch,0,sizeof(ch));val[0] = 0;
    }
    void insert(char *s,int len){
        int now = 0;
        for(int i = 0;i < len;i++){
            int tr = id(s[i]);
            if(ch[now][tr] == 0){
                ch[now][tr] = ++tot;
                memset(ch[tot],0,sizeof(ch[tot]));
                val[tot] = 0;
                fail[tot] = 0;
            }
            now = ch[now][tr];
        }
        val[now]++;
    }

    void make(){
        int h = 1,t = 0;
        for(int i = 0;i < 26;i++) if(ch[0][i] != 0) q[++t] = ch[0][i];
        while(h <= t){
            int now = q[h++];

            for(int i = 0;i < 26;i++){
                if(ch[now][i] == 0){
                    ch[now][i] = ch[fail[now]][i];
                }else{
                    fail[ch[now][i]] = ch[fail[now]][i];
                    q[++t] = ch[now][i];
                }
            }
        }
    }
    int search(char *s,int len){
        int now = 0;int ret = 0;
        for(int i = 0;i < len;i++){
            int tr = id(s[i]);
            now = ch[now][tr];
            int tmp = now;
            while(tmp && val[tmp] != -1){
                ret += val[tmp];
                val[tmp] = -1;
                tmp = fail[tmp];
            }
        }
        return ret;
    }

}ac;
