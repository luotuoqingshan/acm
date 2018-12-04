#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int T;

long long cal(long long a,long long b,long long c){
	return a * a + b * b + c * c + 7 * min(a,min(b,c));
}

int main(){
	cin >> T;
	while(T--){
		long long a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a < b) swap(a,b);
		if(a < c) swap(a,c);
		if(b < c) swap(b,c);
		long long ans = 0;
		if(d <= 100){
			for(long long a1 = a;a1 <= a + 100;a1++){
				for(long long b1 = b;b1 <= b + 100;b1++){
					for(long long c1 = c;c1 <= c + 100;c1++){
						if(a + b + c + d == a1 + b1 + c1){
							ans = max(ans,cal(a1,b1,c1));
						}
					}
				}
			}	
		}else{
			ans = max(ans,cal(a + d,b,c));
		}
		cout << ans << endl;
	}
	return 0;
}
