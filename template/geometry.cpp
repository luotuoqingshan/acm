
bool inConvex(P a) {
  int n = qs.size();
  if ((qs[1] - qs[0]).det(a - qs[0]) < 0 || (qs[n - 1] - qs[0]).det(a - qs[0]) > 0 ) {
    return false;
  }
  int l = 1;
  int r = n;
  int m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if ((qs[m] - qs[0]).det(a - qs[0]) > 0) {
      l = m;
    } else {
      r = m;
    }
  }
  if ((qs[r] - qs[l]).det(a - qs[l]) >= 0) {
    return true;
  }
  return false;
}

typedef Point Vector;
Vector operator + (Vector A,Vector B){ return Vector(A.x + B.x,A.y + B.y);}
Vector operator - (Vector A,Vector B){ return Vector(A.x - B.x,A.y - B.y);}
Vector operator * (Vector A,double p){ return Vector(A.x * p,A.y * p);}
Vector operator / (Vector A,doubel p){ return Vector(A.x / p,A.y / p);}

const db eps = 1e-10;

int dcmp(double x){
	if(fabs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}
bool operator == (const Point &a,const Point &b){
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
db Dot(Vector A,Vector B){ return A.x * B.y - A.y * B.x;}
db Cross(Vector A,Vector B){ return A.x * B.y - A.y * B.x;}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
	Vector u = P - Q;
	db t = Cross(w,u) / Cross(v,w);
	return P + v * t;
}

struct Circle{
    Point c;
    double r;
    Circle(Point c = Point(0,0),double r = 0):c(c),r(r){}
    Point point(double a){
        return Point(c.x + cos(a) * r,c.y + sin(a) * r);
    }
};

int getCircleCircleIntersection(Circle C1,Circle C2, vector<Point> & sol){
    double d = Length(C1.c - C2.c);
    if(dcmp(d) == 0){
        if(dcmp(C1.r - C2.r) == 0) return -1;
        return 0;
    }
    if(dcmp(C1.r + C2.r - d) < 0) return 0;
    if(dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;
    double a = angle(C2.c - C1.c);
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
    Point p1 = C1.point(a - da),p2 = C1.point(a + da);
    sol.push_back(p1);
    if(p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

