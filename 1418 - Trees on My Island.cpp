#include<bits/stdc++.h>
using namespace std;
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
};
vector<Point> point;
double getTotalArea(int n)
{
    double ret = 0;
    for(int i=0; i<n; i++){
        ret+=(point[i].x*point[i+1].y - point[i+1].x*point[i].y);
    }
    ret/=2.0;
    return (ret>=0) ? ret : -ret;
}
int getLatticePoint(Point p1, Point p2)/// minus 1
{
    ll x = llabs(p1.x - p2.x);
    ll y = llabs(p1.y - p2.y);
    return __gcd(x,y);
}
ll getBorder(int n)
{
    ll ret = 0;
    for(int i=0; i<n; i++){
        ret+=getLatticePoint(point[i], point[i+1]);
    }
    ret++;
    return ret;
}
/// A = i + (b/2) + 1;
int main()
{
    int tc,cs=1,n;
    scanf("%d",&tc);
    ll x,y;
    while(tc--){
        point.clear();
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%lld%lld",&x,&y);
            point.push_back(Point(x,y));
        }
        point.push_back(point[0]);
        double total = getTotalArea(n);
        double border = getBorder(n);
        ll ans = llround(total + 1.0 - (border/2.0) + 0.1);
        printf("Case %d: %lld\n",cs++,ans);
    }
}
