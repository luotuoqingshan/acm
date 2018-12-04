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

int d[10000];
typedef long long ll;
const ll mod = 1e9 + 7;

ll c[1005][1005];
ll p10[105];

void upd(ll & a,ll b){
	a += b;
	if(a >= mod) a -= mod;
}
ll ways[12][12];
ll a[12];
ll f[12][1005];

class SumProduct {
    public:
    int findSum(vector<int> amount, int blank1, int blank2) {
    	c[0][0] = 1;
	for(int i = 1;i <= 1000;i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1;j < i;j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if(c[i][j] >= mod) c[i][j] -= mod;
		}
	}
	p10[0] = 1;
	for(int i = 1;i <= 100;i++)
		p10[i] = p10[i - 1] * 10 % mod;
	int sum = 0;
	for(int i = 0;i < 10;i++)
		sum += amount[i];
	ll ans = 0;
	memset(ways,0,sizeof(ways));
	for(int d1 = 0;d1 < 10;d1++){
		for(int d2 = 0;d2 < 10;d2++){
			if(amount[d1] == 0 || amount[d2] == 0)
			continue;
			if(d1 == d2 && amount[d1] < 2) continue;
			for(int j = 0;j < 10;j++) a[j] = amount[j];
			a[d1]--;a[d2]--;
			memset(f,0,sizeof(f));
			f[0][0] = 1;
			for(int i = 0;i < 10;i++){
				for(int j = 0;j <= a[i];j++){
					for(int k = j;k <= blank1 +
					blank2 - 2;k++){
						upd(f[i + 1][k],f[i][k
						- j] * c[blank1
						+blank2 - 2 - k +
						j][j] % mod);
					}
				}
			}
			ways[d1][d2] = f[10][blank1 + blank2 - 2];
		}
	}
	for(int i = 1;i <= blank1;i++){
		for(int j = 1;j <= blank2;j++){
			for(int d1 = 0;d1 < 10;d1++){
				for(int d2 = 0;d2 < 10;d2++){
					if(amount[d1] == 0 ||
					amount[d2] == 0) continue;
					if(d1 == d2 && amount[d1] < 2)
					continue;
					upd(ans,d1 * p10[i - 1] * d2 %
					mod * p10[j - 1] % mod *
					ways[d1][d2] % mod);
				}
			}
		}
	}

        return (int) ans;
    }
};

// CUT begin
ifstream data("SumProduct.sample");

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

bool do_test(vector<int> amount, int blank1, int blank2, int __expected) {
    time_t startClock = clock();
    SumProduct *instance = new SumProduct();
    int __result = instance->findSum(amount, blank1, blank2);
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
        vector<int> amount;
        from_stream(amount);
        int blank1;
        from_stream(blank1);
        int blank2;
        from_stream(blank2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(amount, blank1, blank2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503572461;
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
        cout << "SumProduct (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
