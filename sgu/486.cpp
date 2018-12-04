#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s1[5],s2[5];

int main(){
	scanf("%s%s",s1,s2);
	int a = 0,b = 0;
	for(char c = '0';c <= '9';c++){
		int p1 = -1,p2 = -2;
		for(int i = 0;i < 4;i++){
			if(s1[i] == c) p1 = i;
			if(s2[i] == c) p2 = i;
		}	
		if(p1 >= 0 && p2 >= 0 && p1 == p2){
			a++;
		}
		if(p1 >= 0 && p2 >= 0 && p1 != p2){
			b++;
		}
	}
	cout << a << " " << b << endl;
	return 0;
}
