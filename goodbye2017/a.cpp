#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
#define N 300010
typedef long long ll;
int n;
int a[N],c[N];
vector<int> g,r,b;
int main()
{
    scanf("%d",&n);
    int pos=0,G=0;
    for(int i=1;i<=n;++i)
    {
        char opt[3];
        scanf("%d%s",&a[i],opt);
        if(opt[0]=='G') c[i]=0,g.push_back(i);
        else if(opt[0]=='R') c[i]=-1,r.push_back(i);
        else c[i]=1,b.push_back(i);
    }
    ll ans=0;
    int sz=g.size();
    if(sz==0)
    {
        if(!r.empty()) ans+=a[r.back()]-a[r[0]];
        if(!b.empty()) ans+=a[b.back()]-a[b[0]];
        cout<<ans<<endl;
        return 0;
    }
    if(!r.empty() && a[r[0]]<a[g[0]]) ans+=a[g[0]]-a[r[0]];
    if(!b.empty() && a[b[0]]<a[g[0]]) ans+=a[g[0]]-a[b[0]];
    if(!r.empty() && a[r.back()]>a[g.back()]) ans+=a[r.back()]-a[g.back()];
    if(!b.empty() && a[b.back()]>a[g.back()]) ans+=a[b.back()]-a[g.back()];

	cout << ans << endl;
    for(int o=1;o<sz;++o)
    {
        int l=g[o-1],r=g[o];
        ll now=2LL*(a[r]-a[l]);
        ll x=3LL*(a[r]-a[l]);
        int Max=0;
        int pre=l;
        for(int i=l+1;i<=r;++i)
        if(c[i]<=0)
        {
            Max=max(Max,a[i]-a[pre]);
            pre=i;
        }
        x-=Max;
        Max=0;
        pre=l;
        for(int i=l+1;i<=r;++i)
        if(c[i]>=0)
        {
            Max=max(Max,a[i]-a[pre]);
            pre=i;
        }
        x-=Max;
        now=min(now,x);
        ans+=now;
		cout << ans << endl;
    }
    cout<<ans<<endl;
    return 0;
}
