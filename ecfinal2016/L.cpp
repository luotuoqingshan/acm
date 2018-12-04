#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int A,B,C,D;

int dfs(int n,int a,int b,int c,int d){
	if(n == 7){
//		cout << a << " " << b << " " << c << " " << d << endl;
		if(a == A && b == B && c == C && d == D) return 1;
		else return 0;
	}
	int ret = 0;
	if(n == 1){
		ret += dfs(2,a + 3,b,c,d);
		ret += dfs(2,a,b + 3,c,d);
		ret += dfs(2,a + 1,b + 1,c,d);
	}
	if(n == 2){
		ret += dfs(3,a + 3,b,c,d);
		ret += dfs(3,a,b,c + 3,d);
		ret += dfs(3,a + 1,b,c + 1,d);
	}
	if(n == 3){
		ret += dfs(4,a + 3,b,c,d);
		ret += dfs(4,a,b,c,d + 3);
		ret += dfs(4,a + 1,b,c,d + 1);
	}
	if(n == 4){
		ret += dfs(5,a,b + 3,c,d);
		ret += dfs(5,a,b,c + 3,d);
		ret += dfs(5,a,b + 1,c + 1,d);
	}
	if(n == 5){
		ret += dfs(6,a,b,c,d + 3);
		ret += dfs(6,a,b,c + 3,d);
		ret += dfs(6,a,b,c + 1,d + 1);
	}
	if(n == 6){
		ret += dfs(7,a,b + 3,c,d);
		ret += dfs(7,a,b,c,d + 3);
		ret += dfs(7,a,b + 1,c,d + 1);
	}
	return ret;
}

int main(){
	int T;
	cin >> T;
	for(int cas = 1;cas <= T;cas++){
		scanf("%d%d%d%d",&A,&B,&C,&D);
		int tmp = dfs(1,0,0,0,0);
		printf("Case #%d: ",cas);
		if(tmp > 1) printf("No\n");
		else if(tmp == 1) printf("Yes\n");
		else printf("Wrong Scoreboard\n");
	}	

	return 0;
}
