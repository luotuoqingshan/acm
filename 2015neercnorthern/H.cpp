#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int maxn = 2005;
struct P{
	ll x,y,z;
	P(){}
	P(ll _x, ll _y, ll _z):x(_x),y(_y),z(_z){}
	bool operator < (const P & rhs) const{
		if(x != rhs.x) return x < rhs.x;
		if(y != rhs.y) return y < rhs.y;
		return z < rhs.z;
	}
	P operator - (P rhs){
		return P(x - rhs.x,y - rhs.y,z - rhs.z);
	}
	P operator + (P rhs){
		return P(x + rhs.x,y + rhs.y,z + rhs.z);
	}
	ll det(P rhs){
		return x * rhs.y - y * rhs.x;
	}
	void read(){
		cin >> x >> y >> z;
	}
}s,t,p[maxn * 3];
map<P,int> mp;
int tot;
struct Triangle{
	vector<P> v;
	Triangle(){
		v.clear();
	}
	Triangle(vector<P> rhs){
		v = rhs;
	}
	void add(P p){
		v.push_back(p);
	}
	bool inside(P p){
		long long area1 = abs((v[1] - v[0]).det(v[2] - v[0]));
		long long area2 = abs((v[1] - v[0]).det(p - v[0])) + abs((v[2] - v[1]).det(p - v[1])) + abs((v[0] - v[2]).det(p - v[2]));
		return area1 == area2;
	}
}tri[maxn];


int n;

struct edge{
	int to;long long cost;
	edge(){}
	edge(int _to,ll _cost):to(_to),cost(_cost){}
};

vector<edge> G[maxn * 3];

void addedge(int a,int b,ll c){
	G[a].push_back(edge(b,c));
	G[b].push_back(edge(a,c));
}
int S,T;
ll dis[maxn * 3],pre[maxn * 3];
bool inq[maxn * 3];
void spfa(){
	queue<int> Q;
	for(int i = 1;i <= tot;i++)
		dis[i] = 1e18;
	memset(inq,false,sizeof(inq));
	dis[S] = p[S].z;
	pre[S] = S;
	inq[S] = true;	
	Q.push(S);
	while(!Q.empty()){
		int now = Q.front();Q.pop();
		inq[now] = false;
		for(int i = 0;i < G[now].size();i++){
			edge tmp = G[now][i];
			int to = tmp.to;
			long long cost = tmp.cost;
			if(dis[to] > max(dis[now],cost)){
				dis[to] = max(dis[now],cost);
				pre[to] = now;
				if(!inq[to]){
					Q.push(to);
					inq[to] = true;
				}
			}
		}	
	}
}

int main(){
	tot = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		P a,b,c;
		a.read(),b.read(),c.read();
		if(!mp.count(a)) mp[a] = ++tot,p[tot] = a;
		if(!mp.count(b)) mp[b] = ++tot,p[tot] = b;
		if(!mp.count(c)) mp[c] = ++tot,p[tot] = c;
		int A = mp[a],B = mp[b],C = mp[c];
		addedge(A,B,max(p[A].z,p[B].z));
		addedge(B,C,max(p[B].z,p[C].z));
		addedge(A,C,max(p[A].z,p[C].z));
		tri[i].v.clear();
		tri[i].add(a);
		tri[i].add(b);
		tri[i].add(c);
	}	
	s.read(),t.read();
	if(!mp.count(s)) mp[s] = ++tot,p[tot] = s;
	if(!mp.count(t)) mp[t] = ++tot,p[tot] = t;
	S = mp[s],T = mp[t];
	for(int i = 1;i <= n;i++){
		if(tri[i].inside(s)){
			int A = mp[tri[i].v[0]];
			int B = mp[tri[i].v[1]];
			int C = mp[tri[i].v[2]];
			addedge(A,S,max(p[A].z,s.z));
			addedge(B,S,max(p[B].z,s.z));
			addedge(C,S,max(p[C].z,s.z));
		}
		if(tri[i].inside(t)){
			int A = mp[tri[i].v[0]];
			int B = mp[tri[i].v[1]];
			int C = mp[tri[i].v[2]];
			addedge(A,T,max(p[A].z,t.z));
			addedge(B,T,max(p[B].z,t.z));
			addedge(C,T,max(p[C].z,t.z));
		}
	}	
	spfa();
	vector<int> ans;
	int now = T;
	while(now != S){
		ans.push_back(now);
		now = pre[now];
	}
	ans.push_back(S);
	cout << ans.size() << endl;
	for(int i = ans.size() - 1;i >= 0;i--){
		cout << p[ans[i]].x << " " << p[ans[i]].y << " " << p[ans[i]].z << endl;
	}
	return 0;
}
