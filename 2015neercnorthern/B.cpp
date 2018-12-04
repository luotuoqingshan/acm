#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 50005;


struct val{
	int a,id;
	val(int _a = 0,int _id = 0):a(_a),id(_id){}
	bool operator < (const val & rhs) const{
		return a > rhs.a;
	}
}d[maxn],p[maxn];

int B,K,P,D;

long long ans;

long long pre1[maxn],pre2[maxn];

int main(){
	cin >> B >> K >> P >> D;
	for(int i = 1;i <= P;i++){
		scanf("%d",&p[i].a);
		p[i].id = i;
	}
	sort(p + 1,p + 1 + P);
	for(int i = 1;i <= D;i++){
		scanf("%d",&d[i].a);
		d[i].id = i;
	}
	sort(d + 1,d + 1 + D);
	ans = 0;
	for(int i = 1;i <= P;i++){
		pre1[i] = pre1[i - 1] + p[i].a;
	}

	for(int i = 1;i <= D;i++){
		pre2[i] = pre2[i - 1] + d[i].a;
	}

	int j = min(K,D);
	int ansi = 0, ansj = j;
	ans = 1LL * B * (100 + pre2[j]);
	for(int i = 1;i <= min(P,K);i++){
		while(i + j > K) j--;
		if(1LL * (B + pre1[i]) * (100 + pre2[j]) > ans){
			ans = 1LL * (B + pre1[i]) * (100 + pre2[j]);
			ansi = i;ansj = j;
		}
	}
	cout << ansi << " " << ansj << endl;
	for(int i = 1;i <= ansi;i++){
		printf("%d%c",p[i].id,i == ansi ? '\n' :  ' ');
	}
	for(int i = 1;i <= ansj;i++){
		printf("%d%c",d[i].id,i == ansj ? '\n' : ' ');
	}
	return 0;
}
