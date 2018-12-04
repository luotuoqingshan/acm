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

char g[14][14];
int n,m;
long long dp[20][(1 << 14) + 5];
int forbid[20];

void dfs(int now,int S,long long val,int dep){
    if(now >= m){
        dp[dep][S] += val;
        return;
    }
    if(forbid[now]) dfs(now + 1,S,val,dep);
    else{
        if(now + 1 < m && !forbid[now + 1]){
            dfs(now + 2,S,val,dep);
        }
        if(dep < n && g[dep][now] != 'X'){
            dfs(now + 1,S | (1 << now),val,dep);
        }
    }
}
class DominoTiling {
public:
    long long count(vector<string> grid) {
        n = grid.size();
        m = grid[0].length();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                g[i][j] = grid[i][j];
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < (1 << m);j++){
                if(dp[i][j] == 0) continue;
                memset(forbid,0,sizeof(forbid));
                for(int k = 0;k < m;k++){
                    if(j & (1 << k)){
                        forbid[k] = 1;
                    }	
                    if(g[i][k] == 'X')
                        forbid[k] = 1;
                }
                dfs(0,0,dp[i][j],i + 1);
            }
        }
        return dp[n][0];
    }
};


// CUT begin
ifstream data("DominoTiling.sample");

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

bool do_test(vector<string> grid, long long __expected) {
    time_t startClock = clock();
    DominoTiling *instance = new DominoTiling();
    long long __result = instance->count(grid);
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
        vector<string> grid;
        from_stream(grid);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(grid, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507817935;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "DominoTiling (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
