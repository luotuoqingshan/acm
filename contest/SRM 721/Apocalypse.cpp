#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <queue>

using namespace std;
const int MAXN = 10005,MAXM = 20100;
const int INF = 1e9;
struct Dinic {
    struct Edge{
        int from,to,cap,flow;
    };
    int n, m, s, t;
    vector < Edge > edges;
    vector < int > G[MAXN];
    bool vis[MAXN];
    int d[MAXN];
    int cur[MAXN];

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

int n,m;
vector<int> g[MAXN];
bool vis[MAXN];
class Apocalypse {
    public:
	int id(int t,int x,int c){
		return t * 2 * n + 2 * x + c;
	}
    int maximalSurvival(vector<int> p, vector<int> position, int t) {
		n = (int)p.size() + 1;
		for(int i = 0;i < p.size();i++){
			g[p[i]].push_back(i + 1);
			g[i + 1].push_back(p[i]);
		}
		for(int i = 0;i < n;i++){
			g[i].push_back(i);
		}
		dinic.s = (t + 1) * 4 * n + 1;
		dinic.t = (t + 1) * 4 * n + 2;
		for(auto v : position){
			vis[v] = true;
		}
		for(int i = 0;i < n;i++){
			cout << vis[i] << " ";
		}
		cout << endl;
		for(int i = 0;i < n;i++){
			if(vis[i]){
				dinic.AddEdge(dinic.s,id(0,i,0),1);
			}else{
				dinic.AddEdge(id(t,i,1),dinic.t,1);
			}
		}
		for(int i = 0;i <= t;i++){
			for(int j = 0;j < n;j++){
				dinic.AddEdge(id(i,j,0),id(i,j,1),1);
			}
		}
		for(int i = 0;i < t;i++){
			for(int j = 0;j < n;j++){
				for(auto v : g[j]){
					dinic.AddEdge(id(i,j,1),id(i + 1,v,0),1);
				}
			}
		}
		int ans = dinic.Maxflow(dinic.s,dinic.t);
		cout << ans << endl;
        return ans;
    }
};

// CUT begin
ifstream data("Apocalypse.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> p, vector<int> position, int t, int __expected) {
    time_t startClock = clock();
    Apocalypse *instance = new Apocalypse();
    int __result = instance->maximalSurvival(p, position, t);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> p;
        from_stream(p);
        vector<int> position;
        from_stream(position);
        int t;
        from_stream(t);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, position, t, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1506496329;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 800 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "Apocalypse (800 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
