#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Point
{
    ll x;
    ll y;
};
double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
ll triArea(Point p1, Point p2, Point p3)
{
    return (p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y));
}
Point point[100002];
bool check(Point p, int n)
{
    for(int i=1; i<n ; i++){
        if(triArea(point[0], point[i], p)==0){
            if(dist(point[0], p) + dist(p, point[i]) == dist(point[0], point[i])){
                return true;
            }
        }
    }
    return false;
}
bool solve(Point p, int n)
{
    int lo = 1, hi = n-1;
    while((hi-lo)>1){
        int mid = (lo+hi)/2;
        if(triArea(point[0], point[mid], p)<0)
            hi = mid;
        else
            lo = mid;
    }
    ll part1 = llabs(triArea(point[lo], point[hi], p));
    ll part2 = llabs(triArea(point[0], point[lo], p));
    ll part3 = llabs(triArea(point[hi], point[0],p ));
    return ((part1+part2+part3) == llabs(triArea(point[0], point[lo], point[hi])));
}
int main()
{
    int n,q,tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%lld%lld",&point[i].x, &point[i].y);
        scanf("%d",&q);
        printf("Case %d:\n", cs++);
        Point p;
        while(q--){
            scanf("%lld%lld",&p.x, &p.y);
            if(solve(p, n)) printf("y\n");
            else if(check(p,n))printf("y\n");
            else printf("n\n");
        }
    }
}
