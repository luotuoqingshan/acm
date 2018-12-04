#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	freopen("1.in","w",stdout);
	srand(time(NULL));
	cout << 100000 << endl;
	for(int i = 1;i <= 100000;i++){
		int r = rand() % 10000 + 10000;
		int a = rand() % 10000 + 10000;
		int b = rand() % (a - 1);	
		b++;
		double r1 = 1.0 * b / a * r;
		double r2 = r - r1;
		printf("%.10lf %.10lf %.10lf %.10lf\n",0.0,0.0,0.0,r1);
		printf("%.10lf %.10lf %.10lf\n",0.0,0.0,r1);
		printf("%.10lf %.10lf %.10lf %.10lf\n",1.0 * r,0.0,0.0,r2);
		printf("%.10lf %.10lf %.10lf\n",1.0 * r,0.0,r2);
	}
	return 0;
}
