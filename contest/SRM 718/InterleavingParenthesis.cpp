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
#include <string>
using namespace std;

long long dp[2505][2505];
long long mod = 1e9 + 7;
int sum[2505],sum1[2505];
class InterleavingParenthesis {
    public:
    int countWays(string s1, string s2) {
	    int n1 = s1.length();
	    int n2 = s2.length();
	    for(int i = 0;i <= n1;i++) for(int j = 0;j <= n2;j++) dp[i][j] = 0;
	    sum[0] = 0;
	    sum1[0] = 0;
	    for(int i = 0;i < n1;i++){
		    if(s1[i] == '(') sum[i + 1] = sum[i] + 1;
		    else sum[i + 1] = sum[i] - 1;
	    }
	    for(int i = 0;i < n2;i++){
		    if(s2[i] == '(') sum1[i + 1] = sum1[i] + 1;
		    else sum1[i + 1] = sum1[i] - 1;
		}
	   if(sum1[n2] + sum[n1] != 0) return 0;
	  dp[0][0] = 1;
	 for(int i = 0;i <= n1;i++){
		for(int j = 0;j <= n2;j++){
			if(i < n1){
				if(sum[i + 1] + sum1[j] >= 0){
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
				}
			}
			if(j < n2){
				if(sum[i] + sum1[j + 1] >= 0){
					dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
				}
			}
		}
	 }
	 
        return dp[n1][n2];
    }
};

// CUT begin
ifstream data("InterleavingParenthesis.sample");

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

bool do_test(string s1, string s2, int __expected) {
    time_t startClock = clock();
    InterleavingParenthesis *instance = new InterleavingParenthesis();
    int __result = instance->countWays(s1, s2);
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
        string s1;
        from_stream(s1);
        string s2;
        from_stream(s2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s1, s2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500691572;
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
        cout << "InterleavingParenthesis (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
