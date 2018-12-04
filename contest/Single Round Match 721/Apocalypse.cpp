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

using namespace std;

#define INFINITE 1 << 26
#define MAX_NODE 1005
#define MAX_EDGE_NUM 40005
struct Edge{
    int to;
    int vol;
    int cost;
    int next;
};
Edge gEdges[MAX_EDGE_NUM];

int gHead[MAX_NODE];
int gPre[MAX_NODE];
int gPath[MAX_NODE];
int gDist[MAX_NODE];

int gEdgeCount;
void InsertEdge(int u, int v, int vol, int cost){
    gEdges[gEdgeCount].to = v;
    gEdges[gEdgeCount].vol = vol;
    gEdges[gEdgeCount].cost = cost;
    gEdges[gEdgeCount].next = gHead[u];
    gHead[u] = gEdgeCount++;
    
    gEdges[gEdgeCount].to = u;
    gEdges[gEdgeCount].vol = 0;         //vol为0，表示开始时候，该边的反向不通
    gEdges[gEdgeCount].cost = -cost;    //cost 为正向边的cost相反数，这是为了
    gEdges[gEdgeCount].next = gHead[v];
    gHead[v] = gEdgeCount++;
}

//假设图中不存在负权和环,SPFA算法找到最短路径/从源点s到终点t所经过边的cost之和最小的路径
bool Spfa(int s, int t){
    memset(gPre, -1, sizeof(gPre));
    memset(gDist, 0x7F, sizeof(gDist));
    gDist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()){//由于不存在负权和环，因此一定会结束
        int u = Q.front();
        Q.pop();
        
        for (int e = gHead[u]; e != -1; e = gEdges[e].next){
            int v = gEdges[e].to;
            if (gEdges[e].vol > 0 && gDist[u] + gEdges[e].cost < gDist[v]){
                gDist[v] = gDist[u] + gEdges[e].cost;
                gPre[v] = u; //前一个点
                gPath[v] = e;//该点连接的前一个边
                Q.push(v);
            }
        }
    }
    
    if (gPre[t] == -1)  //若终点t没有设置pre，说明不存在到达终点t的路径
        return false;
    return true;
}

int MinCostFlow(int s, int t){
    int cost = 0;
    int flow = 0;
    while (Spfa(s, t)){
        int f = INFINITE;
        for (int u = t; u != s; u = gPre[u]){
            if (gEdges[gPath[u]].vol < f)
                f = gEdges[gPath[u]].vol;
        }
        flow += f;
        cost += gDist[t] * f;
        for (int u = t; u != s; u = gPre[u]){
            gEdges[gPath[u]].vol -= f;   //正向边容量减少
            gEdges[gPath[u]^1].vol += f; //反向边容量增加
        }
    }
    return cost;
}

vector<int> G[100];


class Apocalypse {
    public:
    int maximalSurvival(vector<int> p, vector<int> position, int t) {
        for(int i = 0;i < p.size();i++){
            G[p[i]].push_back(i + 1);
        }
        return 0;
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
        int T = time(NULL) - 1506440670;
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
