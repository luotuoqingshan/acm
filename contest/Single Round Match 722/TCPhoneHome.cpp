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

const int maxn = 20 * 50;

long long p10[19];

void pre(){
	p10[0] = 1;
	for(int i = 1;i < 19;i++){
		p10[i] = p10[i - 1] * 10LL;
	}
}

struct trie{
	int ch[maxn][26];
	bool ban[maxn];
	int tot;
	int dep[maxn];
	void init(){
		tot = 0;
		ban[0] = 0;
		memset(ch[0],0,sizeof(ch[0]));
		dep[0] = 0;
	}
	void insert(string s){
		int n = s.length();
		int now = 0;
		for(int i = 0;i < n;i++){
			int tr = s[i] - '0';
			if(ch[now][tr] == 0){
				ch[now][tr] = ++tot;
				ban[tot] = 0;
				memset(ch[tot],0,sizeof(ch[tot]));
				dep[tot] = i + 1;
			}		
			now = ch[now][tr];
		}
		ban[now] = 1;
	}
	long long dfs(int root,int d){
		if(ban[root]) return p10[d] / p10[dep[root]];
		long long ans = 0;
		for(int i = 0;i < 10;i++){
			if(ch[root][i] != 0){
				ans += dfs(ch[root][i],d);
			}	
		}
		return ans;
	}
}t;

class TCPhoneHome {
    public:
    long long validNumbers(int digits, vector<string> specialPrefixes) {
		pre();
		t.init();
		for(auto s:specialPrefixes){
			t.insert(s);
		}
        return p10[digits] - t.dfs(0,digits);
    }
};

// CUT begin
ifstream data("TCPhoneHome.sample");

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

bool do_test(int digits, vector<string> specialPrefixes, long long __expected) {
    time_t startClock = clock();
    TCPhoneHome *instance = new TCPhoneHome();
    long long __result = instance->validNumbers(digits, specialPrefixes);
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
        int digits;
        from_stream(digits);
        vector<string> specialPrefixes;
        from_stream(specialPrefixes);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(digits, specialPrefixes, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507806252;
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
        cout << "TCPhoneHome (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
