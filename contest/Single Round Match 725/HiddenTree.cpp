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
LL dp[15][(1 << 14) + 5];
void upd(LL & a,LL b){
	a += b;
	if(a >= mod) a -= mod;
}
class HiddenTree {
    public:
    int count(vector<int> b) {
		sort(b.begin(),b.end());
		int n = b.size();
		dp[0][0] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < (1 << (i - 1));j++){
				upd(dp[i][j],dp[i - 1][j]);
				int S = ((1 << (i - 1)) - 1) ^ j;
				for(int x = S;x;x = (x - 1) & S){
					LL sum = 0;
					for(int k = 0;k < n;k++){
						if(x & (1 << k)) sum += b[k];
					}
					if(sum < b[i - 1]) upd(dp[i][j | x],dp[i - 1][j]);
				}
			}
		}
		LL ans = 0;
		/*for(int i = 1;i <= n;i++){
			for(int j = 0;j < (1 << n);j++){
				printf("dp[%d][%d] = %lld\n",i,j,dp[i][j]);
			}
		}*/
		for(int j = 0;j < (1 << n);j++){
			upd(ans,dp[n][j]);
		}
        return ans;
    }
};

// CUT begin
ifstream data("HiddenTree.sample");

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

bool do_test(vector<int> b, int __expected) {
    time_t startClock = clock();
    HiddenTree *instance = new HiddenTree();
    int __result = instance->count(b);
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
        vector<int> b;
        from_stream(b);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(b, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1512839455;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "HiddenTree (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end