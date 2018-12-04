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

pair<long long,long long> cal(int d,int w){
    if(w < 1LL * d * (d - 1) / 2){
        int r = 0;
        while(1LL * (r + 2) * (r + 1) / 2 <= w) r++;
        return make_pair(0,r);
    }
    long long l = (w - 1LL * d * (d - 1) / 2 + (d - 1)) / d;
    long long r = (w + 1LL * d * (d - 1) / 2) / d;
    return make_pair(l,r);
}

class RememberWords {
    public:
    string isPossible(int d1, int d2, int w1, int w2) {
        pair<long long,long long> f = cal(d1,w1);
        pair<long long,long long> s = cal(d2,w2);
        cout << f.first << " " << f.second << endl;
        cout << s.first << " " << s.second << endl;
        if(f.first <= s.second + 1 && f.second >= s.first - 1) return "Possible";
        return "Impossible";
    }
};

// CUT begin
ifstream data("RememberWords.sample");

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

bool do_test(int d1, int d2, int w1, int w2, string __expected) {
    time_t startClock = clock();
    RememberWords *instance = new RememberWords();
    string __result = instance->isPossible(d1, d2, w1, w2);
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
        int d1;
        from_stream(d1);
        int d2;
        from_stream(d2);
        int w1;
        from_stream(w1);
        int w2;
        from_stream(w2);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d1, d2, w1, w2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1506439299;
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
        cout << "RememberWords (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
