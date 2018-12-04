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



class SquareCutout {
    public:
    int verify(vector<string> cutout) {
		int n = cutout.size(), m = cutout[0].length();
		int lx = 100,rx = -100,ly = 100,ry = -100;
		int num = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(cutout[i][j] == '#'){
					num++;
					lx = min(lx,i);
					rx = max(rx,i);
					ly = min(ly,j);
					ry = max(ry,j);
				}
			}
		}
		if(num == 0) return 1;
		for(int i = lx;i <= rx;i++){
			for(int j = ly;j <= ry;j++){
				if(cutout[i][j] != '#')
					return false;
			}
		}
		bool flag1 = false,flag2 = false;
		if(lx == 0 || rx == n - 1) flag1 = true;
		if(ly == 0 || ry == m - 1) flag2 = true;
		if(rx - lx > ry - ly){
			if(flag2 == false)
				return flag2;
		}
		if(ry - ly > rx - lx){
			if(flag1 == false){
				return flag1;
			}
		}
		return max(rx - lx + 1,ry - ly + 1);
    }
};

// CUT begin
ifstream data("SquareCutout.sample");

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

bool do_test(vector<string> cutout, int __expected) {
    time_t startClock = clock();
    SquareCutout *instance = new SquareCutout();
    int __result = instance->verify(cutout);
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
        vector<string> cutout;
        from_stream(cutout);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(cutout, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1532050023;
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
        cout << "SquareCutout (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
