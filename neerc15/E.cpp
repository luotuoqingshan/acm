#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

queue<int> q[15];

int n,k;

int main(){
	
	while(cin >> n >> k){
		for(int i = 1;i <= n;i++){
			int num;
			scanf("%d",&num);
			for(int j = 1;j <= num;j++){
				int x;
				scanf("%d",&x);
				q[i].push(x);
			}
		}
		int num = 0;
		int tot = 0;
		for(int i = 1;;i = (i) % n + 1){
			if(num == k){
				break;	
			}	
			int tmp;
			if(!q[i].empty()){
				tmp = q[i].front();q[i].pop();
				if(tmp >= tot){
					tot += tmp;
					num++;
				}
			}else{
				tmp = 50;
				tot += tmp;
				num++;
			}
		}	
		cout << tot << endl;
	}	

	return 0;
}
