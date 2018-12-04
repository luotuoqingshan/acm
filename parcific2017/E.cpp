#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 105;
int n;
double X,V;
double l[maxn],r[maxn],v[maxn];

int main(){
	cin >> n >> X >> V;
	double T = X / V;
	for(int i = 1;i <= n;i++){
		scanf("%lf%lf%lf",&l[i],&r[i],&v[i]);
	}
	double sum = 0;
	for(int i = 1;i <= n;i++){
		sum += (r[i] - l[i]) * v[i];
	}
	double vh = - sum / X;
	if(vh * vh > V * V - 1e-8){
		printf("Too hard\n");
		return 0;
	}
	double vt = sqrt(V * V - vh * vh);
	double T1 = X / vt;
	if(T1 > T * 2 + 1e-8){
		printf("Too hard\n");
	}else {
		printf("%.3lf\n",T1);
	}
	return 0;
}
