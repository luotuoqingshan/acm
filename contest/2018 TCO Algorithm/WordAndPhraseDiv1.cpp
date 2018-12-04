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
long long mod = 1e9 + 7;
long long dp[1005];

void init(){
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3;
	for(int i = 3;i <= 1000;i++){
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
}

class WordAndPhraseDiv1 {
    public:
    int findNumberOfPhrases(string w) {
		init();
		int n = w.length();
		if(w[0] == '_') w[0] = 'a';
		if(w[n - 1] == '_') w[n - 1] = 'a';
		long long ans = 1;
		for(int i = 0;i < n;i++){
			if(w[i] != '_') continue;
			else{
				int j = i;
				while(j + 1 < n && w[j + 1] == '_'){
					j++;
				}
				if(j + 1 < n && ('0' <= w[j + 1] && '9' >= w[j + 1]))ans = ans * dp[j - i] % mod;
				else ans = ans * dp[j - i + 1] % mod;
				i = j;
			}
		}
        return (int) ans;
    }
};

// CUT begin
ifstream data("WordAndPhraseDiv1.sample");

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

bool do_test(string w, int __expected) {
    time_t startClock = clock();
    WordAndPhraseDiv1 *instance = new WordAndPhraseDiv1();
    int __result = instance->findNumberOfPhrases(w);
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
        string w;
        from_stream(w);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(w, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1527318167;
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
        cout << "WordAndPhraseDiv1 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
