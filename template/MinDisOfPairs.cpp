const double eps = 1e-8;

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

double Min(double x, double y) {
    return dcmp(x - y) <= 0 ? x : y;
}

double dis(Point a, Point b) {
    Vector u = a - b;
    return sqrt(u * u);
}

int arr[maxn];
Point p[maxn];

bool cmp(int a, int b) {
    return p[a].y < p[b].y;
}

double close_pair(int l, int r) {
    // 判断两个点和三个点的情况  
    if(r == l + 1)
        return dis(p[l], p[r]);  
    else if(r == l + 2)
        return Min(dis(p[l],p[r]), Min(dis(p[l],p[l + 1]), dis(p[l + 1],p[r])));  
  
    int mid = (l + r) >> 1;  
    double ans = Min(close_pair(l, mid), close_pair(mid + 1,r));  
  
    int cnt = 0;
    // 如果 当前p[i]点 横坐标位于 范围（中点横坐标-ans，中点横坐标+ans）位置内，则记录点的序号  
    for(int i = l; i <= r; i ++)
        if (dcmp(p[i].x - p[mid].x + ans) >= 0 && dcmp(p[i].x - p[mid].x - ans) <= 0) 
            arr[cnt ++] = i;
    // 按照纵坐标由小到大 对于arr数组内点进行排序  
    sort(arr, arr + cnt, cmp);
    for(int i = 0; i < cnt; i ++)
        for(int j = i + 1; j < cnt; j ++) {
            if(dcmp(p[arr[j]].y - p[arr[i]].y - ans) >= 0) break;
            ans = Min(ans, dis(p[arr[i]],p[arr[j]]));
        }
    return ans;  
}