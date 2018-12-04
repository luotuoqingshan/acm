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
int road[55];
class AngelDemonGame {
    public:
    string winner(vector<string> G, int A, int D) {
	string ans1 = "Angel",ans2 = "Demon",ans3 = "Unknown";
	int n = G[0].length();
	if(D >= n - 1) return ans2;
	int need = 0;
	memset(road,0,sizeof(road));
	if(G[0][n - 1] == 'Y');
	else road[0]++;
	for(int i = 1;i < n - 1;i++){
		if(G[0][i] == 'N') road[i]++;
		if(G[i][n - 1] == 'N') road[i]++;
	}
	sort(road,road + n - 1);
	int can = 0;
	int sum = 0;
	for(int i = 0;i < n - 1;i++){
		sum += road[i];
		if(sum <= A) can++;
	}
	int maybe = 0;
	for(int i = 0;i < n - 1;i++){
		if(road[i] <= A) maybe++;
	}
	if(can >  D) return ans1;
	if(D >= maybe) return ans2;	
        return ans3;
    }
};

// CUT begin
ifstream data("AngelDemonGame.sample");

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

bool do_test(vector<string> G, int A, int D, string __expected) {
    time_t startClock = clock();
    AngelDemonGame *instance = new AngelDemonGame();
    string __result = instance->winner(G, A, D);
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
        vector<string> G;
        from_stream(G);
        int A;
        from_stream(A);
        int D;
        from_stream(D);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(G, A, D, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500740107;
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
        cout << "AngelDemonGame (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
