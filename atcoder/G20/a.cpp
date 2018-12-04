#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	if((b - a) & 1){
		printf("Bob\n");
	}else{
		printf("Alice\n");
	}
}
