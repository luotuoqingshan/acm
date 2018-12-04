#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5+50;
#define MP(i,j) make_pair(i,j)

int dfn[maxn],low[maxn],st[maxn],top;
vector<pair<int,int>>keyE;
vector<int>keyV,E[maxn];
int n;
int id[maxn];
void tarjan(int now,int cnt){
    int part=(cnt>1);
    st[top++]=now;
    dfn[now]=low[now]=cnt;
    for (int ii=E[now].size()-1;ii>=0;--ii){
        int i=E[now][ii];
        if (!dfn[i]){
            tarjan(i,cnt+1);
            low[now]=min(low[now],low[i]);
            if (low[i]>=dfn[now]){
                keyE.push_back(MP(now,i));
            }
            if (low[i]>=dfn[now]){
                if (++part==2){
                    keyV.push_back(now);
                }
            }
            vector<int> A;
            A.push_back(now);
            for (st[top]=0;st[top]!=i;A.push_back(st[--top]));
			for(auto x : A){
				
			}
        }
        else if (dfn[i]!=dfn[now]-1){
            low[now]=min(low[now],dfn[i]);
        }
    }
}

void Work_key(){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    keyE.clear();
    keyV.clear();
    for (int i=top=0;i<n;i++){
        if (!dfn[i]) tarjan(i,1);
    }
}

int main(){
    


	return 0;
}
