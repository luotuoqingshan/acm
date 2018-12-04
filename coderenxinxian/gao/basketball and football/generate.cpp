#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	freopen("test10.in","w",stdout);
	srand(time(0));
	int t = rand();
   	t %= 50000;
	t++;
	cout << t * 2 << endl;
	for(int i = 1;i <= 2 * t;i++){
		int a = rand() % 100000 + 1;
		int b = rand() % 100000 + 1;
		printf("%d %d\n",a,b);
	}	
	return 0;
}
