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

int dp[105];
bool ok[105][105];
class LineOff {
    public:
    int movesToDo(string points) {
		memset(dp,0,sizeof(dp));
		memset(ok,0,sizeof(ok));
		int n = points.length();
		for(int i = 0;i < n;i++){
			ok[i][i - 1] = true;
		}	
		for(int len = 0;len <= n;len++){
			for(int j = 0;j < n;j++){
				int l = j,r = j + len - 1;
				if(!ok[l][r]) continue;
				if(r >= n) continue;
				if(l - 2 >= 0){
					if(points[l - 1] == points[l - 2]){
						ok[l - 2][r] = true;
					}
				}
				if(r + 2 < n){
					if(points[r + 1] == points[r + 2]){
						ok[l][r + 2] = true;
					}
				}
				if(l - 1 >= 0 && r + 1 < n){
					if(points[l - 1] == points[r + 1]){
						ok[l - 1][r + 1] = true;
					}
				}
			}
		}
		dp[0] = 0;
		for(int i = 1;i <= n;i++){
			dp[i] = dp[i - 1];
			int r = i - 1;
			for(int l = 0;l <= r;l++) if(ok[l][r]){
				dp[i] = max(dp[i],dp[l] + (r - l + 1) / 2);
			}	
		}
        return dp[n];
    }
};

// CUT begin
ifstream data("LineOff.sample");

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

bool do_test(string points, int __expected) {
    time_t startClock = clock();
    LineOff *instance = new LineOff();
    int __result = instance->movesToDo(points);
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
        string points;
        from_stream(points);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(points, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1525345276;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "LineOff (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
