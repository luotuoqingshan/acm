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

class MulticoreProcessing {
    public:
    long long fastestTime(long long jobLength, int corePenalty, vector<int> speed, vector<int> cores) {
        long long ans[55];
        int n = speed.size();
        long long ret = jobLength;
        for(int i = 0;i < n;i++){
            ans[i] = jobLength;
            int l = 1,r = cores[i];
            while(r - l > 100000){
                int ll = l + (r - l) / 3;
                int rr = r - (r - l) / 3;
                long long tmp1 = max(0,ll - 1) * 1LL * corePenalty + (jobLength + ll * 1LL * speed[i] - 1) * 1LL / (ll * 1LL * speed[i]);
                long long tmp2 = max(0,rr - 1) * 1LL * corePenalty + (jobLength + rr * 1LL * speed[i] - 1) * 1LL / (rr * 1LL * speed[i]);
                if(tmp1 < tmp2) r = rr;
                else l = ll;
            }
			cout << l << " " << r << endl;
            for(int j = l;j <= r;j++){
                long long tmp1 = max(0,j - 1) * 1LL * corePenalty + (jobLength + j * 1LL * speed[i] - 1) * 1LL / (j * 1LL * speed[i]);
                ans[i] = min(ans[i],tmp1);
            }
            ret = min(ret,ans[i]);
        }
        
        return ret;
    }
};

// CUT begin
ifstream data("MulticoreProcessing.sample");

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

bool do_test(long long jobLength, int corePenalty, vector<int> speed, vector<int> cores, long long __expected) {
    time_t startClock = clock();
    MulticoreProcessing *instance = new MulticoreProcessing();
    long long __result = instance->fastestTime(jobLength, corePenalty, speed, cores);
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
        long long jobLength;
        from_stream(jobLength);
        int corePenalty;
        from_stream(corePenalty);
        vector<int> speed;
        from_stream(speed);
        vector<int> cores;
        from_stream(cores);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(jobLength, corePenalty, speed, cores, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507817043;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 350 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "MulticoreProcessing (350 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
