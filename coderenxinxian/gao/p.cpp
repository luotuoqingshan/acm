#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
//	freopen("p1.in","r",stdin);
//	freopen("p1.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		double ans = 1.0;
		for(int i = 1;i <= n;i++){
			ans = ans * 2.0;
		}
		ans -= 1.0;
		printf("%.2lf\n",ans);
	}	
	return 0;
}
