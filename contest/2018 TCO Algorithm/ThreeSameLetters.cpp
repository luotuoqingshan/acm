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

typedef long long LL;

const LL mod = 1e9 + 7;

const int maxn = 50;
LL dp[maxn][maxn][maxn];

void upd(LL &a,LL b){
	a += b;
	if(a >= mod)
		a -= mod;
}

class ThreeSameLetters {
    public:
    int countStrings(int L, int S) {
		memset(dp,0,sizeof(dp));
		dp[1][1][0] = S;
		for(int i = 1;i <= L;i++){
			for(int j = 0;j <= L;j++){
				for(int k = 0;k <= L;k++) if(dp[i][j][k]){
					LL val = dp[i][j][k];
					if(j + 1 >= 3){
						upd(dp[i + 1][j + 1][k + 1],val); 
					}else{
						upd(dp[i + 1][j + 1][k],val);
					}
					upd(dp[i + 1][1][k],1LL * val * (S - 1) % mod);
				}
			}
		}
		LL ans = 0;
		for(int i = 0;i <= L;i++){
			upd(ans,dp[L][i][1]);
		}
        return ans;
    }
};

// CUT begin
ifstream data("ThreeSameLetters.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int L, int S, int __expected) {
    time_t startClock = clock();
    ThreeSameLetters *instance = new ThreeSameLetters();
    int __result = instance->countStrings(L, S);
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
        int L;
        from_stream(L);
        int S;
        from_stream(S);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(L, S, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1525346436;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ThreeSameLetters (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
