#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	srand(time(NULL));
	freopen("a2.in","w",stdout);	
	cout << 5000 << endl;
	for(int i = 1;i < 5000;i++){
		printf("%d",rand() % i + 1);
		if(i == 4999){
			printf("\n");
		}else{
			printf(" ");
		}
	}
	cout << 5000 << endl;
	for(int i = 1;i <= 5000;i++){
		printf("%d %d\n",rand() % 5000 + 1,rand() % 5000 + 1);
	}
	return 0;
}
