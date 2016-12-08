#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct trail{
	int s,e;
	int num;
	string str[50];
	bool operator  < (const trail & rhs) const{
		return s < rhs.s || (s == rhs.s && e < rhs.e);
	}
}t[10005];



int main(){
	int n,m;
	int cnt = 0;
	while(scanf("%d%d",&n,&m) != EOF){
		if(n == -1 && m == -1){
			sort(t + 1,t + 1 + cnt);
			for(int i = 1;i <= cnt;i++){
				sort(t[i].str + 1,t[i].str + t[i].num);
			}
			for(int i = 1;i <= cnt;i++){
				printf("%d %d",t[i].s,t[i].e);
				for(int j = 1;j <= t[i].num;j++){
					cout << " "<< t[i].str[j];
				}
				puts("");
			}
			cnt = 0;
		}else{
			t[++cnt].s = min(n,m);
			t[cnt].e = max(n,m);
			char c;
			int now = 0;
			int id = 0;
			while((c = getchar()) != '\n'){
				if(c != ' '){if(now == 0)id++,t[cnt].str[id] = "";t[cnt].str[id] += c,now++;}
				else{
					//t[cnt].str[id] = 0;
					now = 0;
				}
			}
			t[cnt].num = id;
		}
	}
	return 0;
}
