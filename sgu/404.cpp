#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;


const int maxn = 105;
string s[maxn];

int n,m;


int main(){
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> s[i];
	}
	cout << s[(n - 1) % m ] << endl;
	return 0;
}
