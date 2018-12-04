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

class GraphAndPairs {
    public:
    vector<int> construct(int d, int k) {
		vector<pair<int,int> > edge;
        vector<int> ans;
		int now = 0;
		if(d == 2){
			while(k != 0){
				int x = 0;
				while((x + 1) * x / 2 <= k) x++;
				for(int i = now + 1;i <= now + x;i++){
					edge.push_back(make_pair(now,i));
				}
				now = now + x + 1;
				k -= x * (x - 1) / 2;
			}
		}
		else{
       		while(k != 0){
            	int x = (int) sqrt(k + 0.5);
            	int s = now,t = now + (d - 2);
            	for(int i = s;i < t;i++){
                	edge.push_back(make_pair(i,i + 1));
            	}
            	int l1 = t + 1,r1 = l1 + x - 1;
            	int l2 = l1 + x,r2 = l2 + x - 1;
            	for(int i = l1;i <= r1;i++){
                	edge.push_back(make_pair(i,s));
            	}
            	for(int i = l2;i <= r2;i++){
                	edge.push_back(make_pair(i,t));
            	}
            	now = r2 + 1;
            	k -= x * x;
        	}
		}
        ans.push_back(now);
		cout << now << endl;
        for(auto v:edge){
            ans.push_back(v.first);
            ans.push_back(v.second);
        }
        return ans;
    }
};

// CUT begin
ifstream data("GraphAndPairs.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int d, int k, vector<int> __expected) {
    time_t startClock = clock();
    GraphAndPairs *instance = new GraphAndPairs();
    vector<int> __result = instance->construct(d, k);
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
        int d;
        from_stream(d);
        int k;
        from_stream(k);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1506494226;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "GraphAndPairs (450 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
