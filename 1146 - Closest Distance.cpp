#include<cstdio>
#include<cmath>
struct Point
{
    double x;
    double y;
};
void input(Point& p)
{
    scanf("%lf%lf",&p.x, &p.y);
}
double dist(Point a, Point b)
{
    return pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
}
Point a,b,c,d;
double getPoint( double t)
{
    Point now1, now2;

    now1.x = a.x + (b.x-a.x)*t;
    now1.y = a.y + (b.y-a.y)*t;

    now2.x = c.x + (d.x-c.x)*t;
    now2.y = c.y + (d.y-c.y)*t;

    return dist(now1, now2);
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        input(a);input(b);input(c);input(d);
        double lo = 0, hi = 1, mid1, mid2,ans=0;
        for(int i=1; i<=50; i++){
            mid1 = (2.0*lo + hi)/3.0;
            mid2 = (lo + 2.0*hi)/3.0;
            if(getPoint(mid1) < getPoint(mid2))
                hi = mid2;
            else lo = mid1;
        }
        printf("Case %d: %.8f\n",cs++, sqrt(getPoint(lo)));
    }
}
