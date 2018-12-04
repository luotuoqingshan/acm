#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF){
		if(a == b){
			if(a == 0){
				printf("Not a moose\n");
			}else{
				printf("Even %d\n",a * 2);
			}
		}
		else printf("Odd %d\n",max(a,b) * 2);
	}
	return 0;
}
