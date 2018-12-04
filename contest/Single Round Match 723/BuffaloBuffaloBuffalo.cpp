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

const int mod = 1e9 + 7;
void upd(int &a,int b){
	a += b;
	if(a >= mod) a -= mod;
}

int dp[2][16][16][16][16][16];

class BuffaloBuffaloBuffalo {
    public:
    int count(string pattern) {
		memset(dp,0,sizeof(dp));
		dp[0][0][0][0][0][0] = 1;
		int n = pattern.length();
		if(n % 7) return 0;
		for(int i =	0;i < n;i++){
				memset(dp[(i + 1) & 1],0,sizeof(dp[(i + 1) & 1]));
				if(pattern[i] == 'b' || pattern[i] == '?'){
					for(int j = 0;j <= 14;j++){
						for(int j1 = 0;j1 <= j;j1++){
							for(int j2 = 0;j2 <= j1;j2++){
								for(int j3 = 0;j3 <= j2;j3++){
									for(int j4 = 0;j4 <= j3;j4++){
									int j5 = i - j - j1 - j2 - j3 - j4;
									if(dp[i & 1][j][j1][j2][j3][j4] == 0) continue;
									if(j1 * 2 < j5) continue;
									if(j5 < j2 * 2) continue;
									upd(dp[(i + 1) & 1][j + 1][j1][j2][j3][j4],dp[i & 1][j][j1][j2][j3][j4]);	
									}
								}
							}
						}
					}
				}
				if(pattern[i] == 'u' || pattern[i] == '?'){
					for(int j = 0;j <= 14;j++){
						for(int j1 = 0;j1 < j;j1++){
							for(int j2 = 0;j2 <= j1;j2++){
								for(int j3 = 0;j3 <= j2;j3++){
									for(int j4 = 0;j4 <= j3;j4++){
									int j5 = i - j - j1 - j2 - j3 - j4;
									if(dp[i & 1][j][j1][j2][j3][j4] == 0) continue;
									if(j1 * 2 < j5) continue;
									if(j5 < j2 * 2) continue;
									upd(dp[(i + 1) & 1][j][j1 + 1][j2][j3][j4],dp[i & 1][j][j1][j2][j3][j4]);	
									}
								}
							}
						}
					}
				}
				if(pattern[i] == 'f' || pattern[i] == '?'){
					for(int j = 0;j <= 14;j++){
						for(int j1 = 0;j1 <= j;j1++){
							for(int j2 = 0;j2 <= j1;j2++){
								for(int j3 = 0;j3 <= j2;j3++){
									for(int j4 = 0;j4 <= j3;j4++){
									int j5 = i - j - j1 - j2 - j3 - j4;
									if(dp[i & 1][j][j1][j2][j3][j4] == 0) continue;
									if(j1 * 2 < j5 + 1) continue;
									if(j5 < j2 * 2) continue;
									upd(dp[(i + 1) & 1][j][j1][j2][j3][j4],dp[i & 1][j][j1][j2][j3][j4]);	
									}
								}
							}
						}
					}
				}
				if(pattern[i] == 'a' || pattern[i] == '?'){
					for(int j = 0;j <= 14;j++){
						for(int j1 = 0;j1 <= j;j1++){
							for(int j2 = 0;j2 <= j1;j2++){
								for(int j3 = 0;j3 <= j2;j3++){
									for(int j4 = 0;j4 <= j3;j4++){
									int j5 = i - j - j1 - j2 - j3 - j4;
									if(dp[i & 1][j][j1][j2][j3][j4] == 0) continue;
									if(j1 * 2 < j5) continue;
									if(j5 < (j2 + 1) * 2) continue;
									upd(dp[(i + 1) & 1][j][j1][j2 + 1][j3][j4],dp[i & 1][j][j1][j2][j3][j4]);	
									}
								}
							}
						}
					}
				}
				if(pattern[i] == 'l' || pattern[i] == '?'){
					for(int j = 0;j <= 14;j++){
						for(int j1 = 0;j1 <= j;j1++){
							for(int j2 = 0;j2 <= j1;j2++){
								for(int j3 = 0;j3 < j2;j3++){
									for(int j4 = 0;j4 <= j3;j4++){
									int j5 = i - j - j1 - j2 - j3 - j4;
									if(dp[i & 1][j][j1][j2][j3][j4] == 0) continue;
									if(j1 * 2 < j5) continue;
									if(j5 < j2 * 2) continue;
									upd(dp[(i + 1) & 1][j][j1][j2][j3 + 1][j4],dp[i & 1][j][j1][j2][j3][j4]);	
									}
								}
							}
						}
					}
				}
				if(pattern[i] == 'o' || pattern[i] == '?'){
					for(int j = 0;j <= 14;j++){
						for(int j1 = 0;j1 <= j;j1++){
							for(int j2 = 0;j2 <= j1;j2++){
								for(int j3 = 0;j3 <= j2;j3++){
									for(int j4 = 0;j4 < j3;j4++){
									int j5 = i - j - j1 - j2 - j3 - j4;
									if(dp[i & 1][j][j1][j2][j3][j4] == 0) continue;
									if(j1 * 2 < j5) continue;
									if(j5 < j2 * 2) continue;
									upd(dp[(i + 1) & 1][j][j1][j2][j3][j4 + 1],dp[i & 1][j][j1][j2][j3][j4]);	
									}
								}
							}
						}
					}
				}
		}	
        return dp[n & 1][n / 7][n / 7][n / 7][n / 7][n / 7];
    }
};

// CUT begin
ifstream data("BuffaloBuffaloBuffalo.sample");

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

bool do_test(string pattern, int __expected) {
    time_t startClock = clock();
    BuffaloBuffaloBuffalo *instance = new BuffaloBuffaloBuffalo();
    int __result = instance->count(pattern);
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
        string pattern;
        from_stream(pattern);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pattern, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1511025458;
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
        cout << "BuffaloBuffaloBuffalo (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
