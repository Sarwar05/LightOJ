#include<bits/stdc++.h>
using namespace std;
#define inf 20000000009
#define ll long long
struct Point
{
    ll x;
    ll y;
    Point(ll _x, ll _y)
    {
        x = _x;
        y = _y;
    }
    bool operator<(const Point& ob)const
    {
        return y<ob.y;
    }
};
vector<Point> arr;
ll lim;
ll sn, origin;
bool check(ll mid)
{
    vector<Point> interval;;
    for(ll i=0 ;i<arr.size(); i++){
        ll p = mid + (arr[i].y - origin);
        p*=p;
        if(p>lim) return false;
        p = sqrt(lim - p);
        interval.push_back(Point(arr[i].x - p, arr[i].x + p));
    }
    sort(interval.begin(), interval.end());
    ll cnt = 0;
    for(ll i=0; i<interval.size();){
        ll now = interval[i].y;
        ++i;
        while(i<interval.size() && interval[i].x<=now)
            i++;
        cnt++;
    }
    return cnt<=sn;
}
int main()
{
    int tc,cs=1,n,k,a,b,d;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d%d",&k,&n,&sn,&d);
        arr.clear();
        lim = d;
        lim*=lim;
        origin = k;
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a,&b);
            arr.push_back(Point(a,b));
        }
        printf("Case %d: ",cs++);
        ll lo=1, hi = d, mid, ans = -1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(check(mid)){
                ans = max(ans, mid);
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        if(ans<0) printf("impossible\n");
        else printf("%lld\n",ans);
    }
}
