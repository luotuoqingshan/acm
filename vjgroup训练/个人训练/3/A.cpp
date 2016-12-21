#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int L;

const double pi = acos(-1);

int main(){
	while(cin >> L){
		if(L == 0) break;
		double r = 1.0 * L / pi;
		printf("%.2lf\n",pi * r * r / 2);
	}
	return 0;
}
