#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 505;

struct ath{
	double t[2];
	string name;
	bool operator < (const ath & rhs) const{
		return t[1] < rhs.t[1];
	}
	void read(){
		cin >> name >> t[0] >> t[1];
	}
}p[maxn],tmp[maxn];

int n;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		p[i].read();
	}	
	double ans = 100; int id = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			tmp[j] = p[j];
		swap(tmp[i],tmp[1]);
		sort(tmp + 2,tmp + 1 + n);
		double now = tmp[1].t[0] + tmp[2].t[1] + tmp[3].t[1] + tmp[4].t[1];
		if(now < ans){
			ans = now;
			id = i;
		}
	}
	printf("%.15lf\n",ans);
	for(int i = 1;i <= n;i++){
		tmp[i] = p[i];
	}
	swap(tmp[1],tmp[id]);
	sort(tmp + 2,tmp + 1 + n);
	for(int i = 1;i <= 4;i++){
		cout << tmp[i].name << endl;
	}
	return 0;
}
