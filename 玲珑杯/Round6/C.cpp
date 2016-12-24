#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n % 3 == 0){
			cout << n / 3 << endl;
		}else{
			cout << n << endl;
		}
	}
	return 0;
}
