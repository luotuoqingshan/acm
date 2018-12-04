#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int main(){
	cin >> n;
	int last = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			printf("%d %d %d\n",i,i,last);
			last = i;
			printf("%d %d %d\n",j,j,last);
			last = j;
		}
	}
	printf("%d %d %d\n",0,1,last);
	return 0;
}
