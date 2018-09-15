#include<bits/stdc++.h>
using namespace std;
struct Point
{
    double x;
    double y;
};
Point in[102], out[102];
Point getPoint(Point a, Point b, double m, double n)
{
    Point ret;
    ret.x = (m*b.x + n*a.x)/(m+n);
    ret.y = (m*b.y + n*a.y)/(m+n);
    return ret;
}
double durotto(Point a, Point b)
{
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
double ternarySearch(Point a, Point b, Point p)
{
    Point mid1,mid2;
    for(int i=1; i<=50; i++){
        mid1 = getPoint(a,b,1,2);
        mid2 = getPoint(a,b,2,1);
        if(durotto(mid1,p) < durotto(mid2,p))
            b = mid2;
        else a = mid1;
    }
    return durotto(a,p);
}
int main()
{
    int n,m,tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%lf%lf",&in[i].x, &in[i].y);
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
            scanf("%lf%lf",&out[i].x, &out[i].y);
        out[m+1] = out[1];
        double dist = 1000000009;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dist = min(dist, ternarySearch(out[j], out[j+1], in[i]));
        printf("Case %d: %.10f\n",cs++,sqrt(dist)/2.0);
    }
}
