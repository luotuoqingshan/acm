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

string s1 = "Impossible";
string s2 = "Possible";

int a[70],tot;
long long x[100];
class OrAndSum {
    public:
    string isPossible(vector<long long> pairOr, vector<long long> pairSum) {
		int n = pairOr.size();
		vector<long long> pairAnd;
		vector<long long> pairXor;
		for(int i = 0;i < n;i++){
			if(pairSum[i] < pairOr[i]) return s1;
			pairAnd.push_back(pairSum[i] - pairOr[i]);
			if((pairAnd[i] & pairOr[i]) != pairAnd[i]) return s1;
			pairXor.push_back(pairOr[i] ^ pairAnd[i]);
		}	
		x[0] = 0;
		for(int i = 0;i < n;i++){
			x[i + 1] = pairXor[i] ^ x[i];
		}
		memset(a,0,sizeof(a));
		for(int j = 0;j < 60;j++){
			if(pairAnd[0] & (1LL << j)){
				if(x[1] & (1LL << j)){
					a[j] |= 1;
				}else
					a[j] |= 2;
			}
			if((pairOr[0] & (1LL << j)) == 0){
				if(x[1] & (1LL << j)){
					a[j] |= 2;
				}
				else a[j] |= 1;
			}
		}
		for(int i = 1;i < n;i++){
			for(int j = 0;j < 60;j++){
				if(pairAnd[i] & (1LL << j)){
					if(x[i] & (1LL << j)){
						a[j] |= 1;
					}else{
						a[j] |= 2;
					}
					if(x[i + 1] & (1LL << j)){
						a[j] |= 1;
					}else{
						a[j] |= 2;
					}
				}
				if((pairOr[i] & (1LL << j)) == 0){
					if(x[i] & (1LL << j)){
						a[j] |= 2;
					}else{
						a[j] |= 1;
					}
					if(x[i + 1] & (1LL << j)){
						a[j] |= 2;
					}else{
						a[j] |= 1;
					}
				}
			}
		}
		for(int j = 0;j < 60;j++){
			if(a[j] == 3) return s1;
		}
        return s2;
    }
};

// CUT begin
ifstream data("OrAndSum.sample");

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

bool do_test(vector<long long> pairOr, vector<long long> pairSum, string __expected) {
    time_t startClock = clock();
    OrAndSum *instance = new OrAndSum();
    string __result = instance->isPossible(pairOr, pairSum);
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
        vector<long long> pairOr;
        from_stream(pairOr);
        vector<long long> pairSum;
        from_stream(pairSum);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pairOr, pairSum, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1511884851;
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
        cout << "OrAndSum (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
