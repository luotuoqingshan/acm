#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int x[3],y[3],r[3];


int sqr(int x){
	return x * x;
}

int check(int x1,int x2,int y1,int y2,int r1,int r2){
	if((sqr(x1 - x2) + sqr(y1 - y2) >= sqr(r1 + r2)) ||  
			(sqr(x1 - x2) + sqr(y1 - y2) <= sqr(r1 - r2)) ) return 0;
	else return 1;
}
typedef double db;

const db EPS = 1e-8;

inline int sign(db a) {
	return a < -EPS ? -1 : a > EPS;
}

inline int cmp(db a, db b){//精度比较函数
	return sign(a-b);
}

struct P {//点
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return P(x + p.x, y + p.y); }
	P operator-(P p) { return P(x - p.x, y - p.y); }
	P operator*(db d) { return P(x * d, y * d); }
	P operator/(db d) { return P(x / d, y / d); }
	bool operator<(P p) const {
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}
	bool operator==(P p) const{
		return cmp(x,p.x) == 0 && cmp(y,p.y) == 0;
	}
	db dot(P p) { return x * p.x + y * p.y; }//点积
	db det(P p) { return x * p.y - y * p.x; }//叉积
	db distTo(P p) { return (*this-p).abs(); }//距离
	db alpha() { return atan2(y, x); }//求极角
	void read() { cin>>x>>y; }
	db abs() { return sqrt(abs2());}//长度
	db abs2() { return x * x + y * y; }//长度的平方
	P rot90() { return P(-y,x);}//逆时针旋转90度
	P unit() { return *this/abs(); }//单位化
    int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }//极角是否在[0,180)之间
};


vector<P> isCC(P o1, db r1, P o2, db r2) { //need to check whether two circles are the same
	db d = o1.distTo(o2);
	if (cmp(d, r1 + r2) == 1) return {};
	d = min(d, r1 + r2);
	db y = (r1 * r1 + d * d - r2 * r2) / (2 * d), x = sqrt(r1 * r1 - y * y);
	P dr = (o2 - o1).unit();
	P q1 = o1 + dr * y, q2 = dr.rot90() * x;
	return {q1-q2,q1+q2};//along circle 1
}



int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	if(n == 1){
		cout << 2 << endl;
	}else if(n == 2){
		cout << 3 + check(x[0],x[1],y[0],y[1],r[0],r[1]);
	}else{
		int flag = 0;
		for(int i = 0;i < 3;i++){
			for(int j = i + 1;j < 3;j++){
				if(check(x[i],x[j],y[i],y[j],r[i],r[j])){
					flag++;
				}
			}
		}	
		if(flag == 0) cout << 4 << endl;
		else if(flag == 1) cout << 5 << endl;
		else if(flag == 2){
			cout << 6 << endl;	
		}else{
			vector<P> v;
			for(int i = 0;i < 3;i++){
				for(int j = i + 1;j < 3;j++){
					vector<P> temp = isCC(P(x[i],y[i]),r[i],P(x[j],y[j]),r[j]);
					v.push_back(temp[0]);
					v.push_back(temp[1]);	
				}
			}	
			sort(v.begin(),v.end());
			int ans = 6;
			for(int i = 0;i < v.size() - 1;i++){
				if(v[i] == v[i + 1]) ans--;
			}
			cout << ans + 2 << endl;
		}
	}
	return 0;
}
