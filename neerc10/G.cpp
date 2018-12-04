#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int d[4][4];

bool checkcol(int i,int &ret,int &p){
	int cnt = 0,sum = 0;
	p = 0;
	for(int j = 0;j < 4;j++){
		if(d[j][i] > 0) cnt++,sum += d[j][i];
		else p = j;
	}
	ret = 10 - sum;
	if(cnt != 3) return false;
	if(sum > 5 && sum < 10) return true;
}

bool checkrow(int i,int &ret,int &p){
	int cnt = 0,sum = 0;
	p = 0;
	for(int j = 0;j < 4;j++){
		if(d[i][j] > 0) cnt++,sum += d[i][j];
		else p = j;
	}
	ret = 10 - sum;
	if(cnt != 3) return false;
	if(sum > 5 && 10 > sum) return true;
}

int main(){
	memset(d,0,sizeof(d));
	while(true){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x--,y--;
		d[x][y] = z;
		int res = 0;
		int pos = 0;
		if(checkrow(x,res,pos)){
			printf("%d %d %d WIN\n",x + 1,pos + 1,res);
			fflush(stdout);break;
		}if(checkcol(y,res,pos)){
			printf("%d %d %d WIN\n",pos + 1,y + 1,res);
		}
		for(int j = 0;j < 4;j++) if(j != y){
			d[x][j] = 5 - z;
			bool flag = true;
			if(checkrow(x,res,pos)) flag = false;
			if(checkcol(j,res,pos)) flag = false;
			if(flag){
				printf("%d %d %d\n",x + 1,j + 1,5 - z);
				fflush(stdout);
				break;
			}
			d[x][j] = 0;
		}
	}
	return 0;
}
