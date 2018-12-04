
const int INF = INT_MAX;
int n,m;
vector<pair<int,int> > e;
struct Dinic {
    const int MAXN = 10005,MAXM = 20100;
    struct Edge{
        int from,to,cap,flow;
    };
    int n, m, s, t;
    vector < Edge > edges;
    vector < int > G[MAXN];
    bool vis[MAXN];
    int d[MAXN];
    int cur[MAXN];
    
    void init(int n){
        for(int i = 0;i < n;i++){
            G[i].clear();
        }
        edges.clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.push_back((Edge) {
                from, to, cap, 0
        });
        edges.push_back((Edge) {
                to, from, 0, 0
        });
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS() {
        memset(vis, 0, sizeof vis);
        queue < int > Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;

        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();

            for(int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];

                if(!vis[e.to] && e.cap > e.flow) { //如果未曾访问过，而且这一条边处于残量网络中，那么计算层次
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }

        return vis[t];
    }

    int DFS(int x, int a) {
        if(x == t || a == 0) { // 如果找到一条增广的路或无法继续增广，返回当前流量
            return a;
        }

        int flow = 0, f;

        for(int& i = cur[x]; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];

            if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) { // 如果处于同一个层次且这一条路径还能增广
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;//增广 注意当前流量a要减f

                if(a == 0) {//如果a=0，那么不能继续增广，返回上一条路
                    break;
                }
            }
        }

        return flow;
    }

    int Maxflow(int s, int t) {
        this -> s = s;
        this -> t = t;

        int flow = 0;

        while(BFS()) { // 计算层次图 如果s-t不连通那么退出
            memset(cur, 0, sizeof cur); // 初始化当前弧
            flow += DFS(s, INF); // 计算最大流
        }

        return flow;
    }
} dinic;
