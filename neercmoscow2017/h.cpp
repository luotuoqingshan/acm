#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;
LL T,n,m;

const int maxn = 1e5 + 5;
LL a[maxn],b[maxn];
LL L[maxn],R[maxn];

LL calmin(LL x1,LL y1,LL x2,LL y2){
	LL mi = y1 - ((x2 - x1) - (y2 - y1)) / 2;
	mi = max(mi,0LL);
	LL ans1 = 0,ans2 = 0,ans3 = 0;
	int len1,len2;
	if(mi == y1){
		len1 = 1;
		ans1 = mi;
	}else{
		len1 = y1 - mi;
		ans1 = (mi + y1 - 1) * (y1 - mi) / 2;
	}	
	if(mi == y2){
		len2 = 1;
		ans3 = mi;
	}else{
		len2 = y2 - mi;
		ans3 = (mi + y2 - 1) * (y2 - mi) / 2;
	}
	ans2 = ((x2 - x1 - 1) - len1 - len2) * mi;
	return ans1 + ans2 + ans3;
}

LL calmax(LL x1,LL y1,LL x2,LL y2){
	LL mx = ((x2 - x1) - (y2 - y1)) / 2 + y2;
	LL ans1 = 0,ans2 = 0,ans3 = 0;
	int len1,len2;
	if(mx == y1){
		len1 = 1;
		ans1 = mx;
	}else{
		len1 = mx - y1;
		ans1 = (mx + y1 + 1) * (mx - y1) / 2;
	}	
	if(mx == y2){
		len2 = 1;
		ans3 = mx;
	}else{
		len2 = mx - y2;
		ans3 = (mx + y2 + 1) * (mx - y2) / 2;
	}
	ans2 = ((x2 - x1 - 1) - len1 - len2) * mx;
	return ans1 + ans2 + ans3;
}
LL Abs(LL x){
	return x > 0 ? x : -x;
}


int main(){
	cin >> T >> n >> m;
	for(int i = 1;i <= m;i++){
		scanf("%lld%lld",&a[i],&b[i]);	
	}
	a[0] = 0;
	a[m + 1] = n;
	bool flag = true;
	T -= b[1];10 3 1
1 1
	for(int i = 2;i <= m;i++){
		T -= b[i];
		if(a[i] == a[i - 1] + 1){
			L[i] = 0,R[i] = 0;
		}else{
			if(a[i] - a[i - 1] < Abs(b[i] - b[i - 1])){
				puts("No");
				return 0;
			}
			L[i] = calmin(a[i - 1],min(b[i],b[i - 1]),a[i],max(b[i],b[i - 1]));
			R[i] = calmax(a[i - 1],min(b[i],b[i - 1]),a[i],max(b[i],b[i - 1]));
		}
	}
	if(a[m] == n) L[m + 1] = R[m + 1] = 0;
	else{
		LL mi = b[m] - (n - a[m]);
		mi = max(0LL,mi);
		LL mx = b[m] + (n - a[m]);
		L[m + 1] = (mi + b[m] - 1) * (b[m] - mi) / 2;
		R[m + 1] = (mx + b[m] + 1) * (mx - b[m]) / 2;
		L[m + 1] += ((n - a[m]) - (b[m] - mi)	) * mi;
		R[m + 1] += ((n - a[m]) - (mx - b[m])) * mx;	
	}
	if(a[1] == 1){
		L[1] = R[1] = 0;
	}else{
		LL mi = b[1] - (a[1] - 1);
		mi = max(0LL,mi);
		LL mx = b[1] + (a[1] - 1);
		L[1] = (mi + b[1] - 1) * (b[1] - mi) / 2;
		R[1] = (mx + b[1] + 1) * (mx - b[1]) / 2;
		L[1] += (a[1] - 1 - (b[1] - mi)) * mi;
		R[1] += (a[1] - 1 - (mx - b[1])) * mx;
	}
	if(T < 0){
		puts("No");
		return 0;
	}
	LL ll = 0,rr = 0;
	for(int i = 1;i <= m + 1;i++){
		ll += L[i],rr += R[i];
	}
	if(T >= ll && T <= rr){
		puts("Yes");
	}else{
		puts("No");	
	}
	return 0;
}
