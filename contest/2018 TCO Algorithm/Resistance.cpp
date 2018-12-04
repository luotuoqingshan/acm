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
#include <map>
using namespace std;


map<vector<int>,bool> vis;

int a[15];

class Resistance {
    public:
    vector<double> spyProbability(int P, int S, vector<string> missions) {
		vis.clear();
		for(int i = 0;i < P;i++)
			a[i] = i;
		vector<vector<int> > ans;
		int cnt[15];
		bool is[15];
		do{
			memset(is,0,sizeof(is));
			vector<int> temp;
			for(int i = 0;i < S;i++){
				temp.push_back(a[i]);
				is[a[i]] = 1;
			}
			sort(temp.begin(),temp.end());
			if(vis.count(temp)) continue;
			else vis[temp] = true;
			bool flag = true;
			for(int i = 0;i < missions.size();i++){
				if(missions[i][0] == 'F'){
					bool f = false;
					for(int j = 1;j < P + 1;j++){
						if(missions[i][j] == '1' && is[j - 1])
							f = true;
					}
					if(!f) flag = false;
				}	
			}
			if(flag)
				ans.push_back(temp);
		}while(next_permutation(a,a + P));	
		memset(cnt,0,sizeof(cnt));
		if(ans.empty()){
			return vector<double>();
		}
		for(int i = 0;i < ans.size();i++){
			for(int j = 0;j < S;j++){
				cnt[ans[i][j]]++;
			}
		}
		vector<double> ret(P);
		for(int i = 0;i < P;i++){
			ret[i] = cnt[i] * 1.0/ ans.size(); 
		}
		return ret;
    }
};

// CUT begin
ifstream data("Resistance.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool double_vector_equal (const vector<double> &expected, const vector<double> &received) {
    if (expected.size() != received.size()) return false;
    int n = expected.size();
    for (int i = 0; i < n; ++i)
        if (!double_equal(expected[i], received[i])) return false;
    return true;
}

bool do_test(int P, int S, vector<string> missions, vector<double> __expected) {
    time_t startClock = clock();
    Resistance *instance = new Resistance();
    vector<double> __result = instance->spyProbability(P, S, missions);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_vector_equal(__expected, __result)) {
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
        int P;
        from_stream(P);
        int S;
        from_stream(S);
        vector<string> missions;
        from_stream(missions);
        next_line();
        vector<double> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(P, S, missions, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1524326957;
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
        cout << "Resistance (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
