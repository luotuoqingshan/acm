const int maxn = 50005;
const int maxa = maxn * 40;
const int maxv = 100000 + 5;
int root[maxn],data[maxa],ls[maxa],rs[maxa],tot_tree;
void build(int &root,int l,int r){
    root = ++tot_tree;
    data[root] = 0;
    if(l == r){
        return;
    }
    int mid = (l + r) / 2;
    build(ls[root],l,mid);
    build(rs[root],mid + 1,r);
}

void pushup(int root){
    data[root] = data[ls[root]] + data[rs[root]];
}

void update(int last,int &root,int l,int r,int p){
    root = ++tot_tree;
    ls[root] = ls[last];
    rs[root] = rs[last];
    data[root] = data[last];
    if(l == r){
        data[root]++;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid) update(ls[last],ls[root],l,mid,p);
    else update(rs[last],rs[root],mid + 1,r,p);
    pushup(root);
}

int query(int last,int root,int l,int r,int ql,int qr){
    if(ql > qr) return 0;
    if(ql <= l && r <= qr) return data[root] - data[last];
    int mid = (l + r) / 2;
    int ans = 0;
    if(ql <= mid) ans += query(ls[last],ls[root],l,mid,ql,qr);
    if(qr > mid) ans += query(rs[last],rs[root],mid + 1,r,ql,qr);
    return ans;
}
