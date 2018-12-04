#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n,a,b;

void pre(){
	freopen("crypto.in","r",stdin);
	freopen("crypto.out","w",stdout);
}

int main(){
	pre();
	cin >> n >> a >> b;
	int ans = -1;
	int x,y;
	int ansx = 0,ansy = 0;
	for(x = n;x >= 1;x--){
		for(y = x;y >= 1;y = (y - 1) & x){
			int A = a * x + b * y;
			int B = a * y + b * x;
			if((A ^ B) > ans){
				ans = max(ans,A ^ B);
				ansx = x,ansy = y;
			}
		}
	}
	cout << ansx << " " << ansy << endl;
	return 0;
}
