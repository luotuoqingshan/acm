const int maxn = 555;
const int maxisn = 10;

const double eps = 1e-8;
const double pi = acos(-1.0);

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

inline double sqr(double x) {return x * x;}

struct Point {
    double x, y;
    Point () {}
    Point (double x, double y) : x(x), y(y) {}
    Point operator +(const Point& rhs) {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator -(const Point& rhs) {
        return Point(x - rhs.x, y - rhs.y);
    }
    double operator *(const Point& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    double operator ^(const Point& rhs) const {
        return x * rhs.y - y * rhs.x;
    }
};

typedef Point Vector;

Point LineCross(Point a, Point b, Point c, Point d) {
    double u = ((b - a) ^ (c - a)), v = ((a - b) ^ (d - b));
    return Point((c.x * v + d.x * u) / (u + v), (c.y * v + d.y * u) / (u + v));
}

double PolygonArea(Point p[], int n) {
    if (n < 3) return 0.0;
    double s = p[0].y * (p[n - 1].x - p[1].x);
    p[n] = p[0];
    for (int i = 1; i < n; i ++)
        s += p[i].y * (p[i - 1].x - p[i + 1].x);
    return fabs(s * 0.5);
}

double CPIA(Point a[], Point b[], int na, int nb) {
    Point p[maxisn], tmp[maxisn];
    int tn, sflag, eflag;
    a[na] = a[0], b[nb] = b[0];
    memcpy(p, b, sizeof(Point) * (nb + 1));
    for (int i = 0; i < na && nb > 2; ++ i) {
        sflag = dcmp((a[i + 1] - a[i]) ^ (p[0] - a[i]));
        for (int j = tn = 0; j < nb; ++ j, sflag = eflag) {
            if (sflag >= 0) tmp[tn ++] = p[j];
            eflag = dcmp((a[i + 1] - a[i]) ^ (p[j + 1] - a[i]));
            if ((sflag ^ eflag) == -2)
                tmp[tn ++] = LineCross(a[i], a[i + 1], p[j], p[j + 1]);
        }
        memcpy(p, tmp, sizeof(Point) * tn);
        nb = tn, p[nb] = p[0];
    }
    if (nb < 3) return 0.0;
    return PolygonArea(p, nb);
}

// a, b两个多边形 ，na a的点个数，nb 点个数 无论顺逆时针
//实际解法是两多边形面积和减去面积交，这个板子可以经过调整变成面积交
double SPIA(Point a[], Point b[], int na, int nb) {
    Point t1[4], t2[4];
    double res = 0, if_clock_t1, if_clock_t2;
    a[na] = t1[0] = a[0], b[nb] = t2[0] = b[0];
    for (int i = 2; i < na; i ++) {
        t1[1] = a[i - 1], t1[2] = a[i];
        if_clock_t1 = dcmp((t1[1] - t1[0]) ^ (t1[2] - t1[0]));
        if (if_clock_t1 < 0) swap(t1[1], t1[2]);
        for (int j = 2; j < nb; j ++) {
            t2[1] = b[j - 1], t2[2] = b[j];
            if_clock_t2 = dcmp((t2[1] - t2[0]) ^ (t2[2] - t2[0]));
            if (if_clock_t2 < 0) swap(t2[1], t2[2]);
            res += CPIA(t1, t2, 3, 3) * if_clock_t1 * if_clock_t2;
        }
    }
    //return res;   面积交
    return PolygonArea(a, na) + PolygonArea(b, nb) - res;
}