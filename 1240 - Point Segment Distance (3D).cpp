#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define vi vector<int>
#define PI acos(-1.0)
struct Point
{
    double x;
    double y;
    double z;
};
Point input()
{
    Point ret;
    scanf("%lf%lf%lf",&ret.x, &ret.y, &ret.z);
    return ret;
}
Point intersectionPointFromRatio(Point a, Point b, double m, double n)
{
    /// a to P = m, p to b = n;
    Point ret;
    ret.x = (m*b.x + n*a.x)/(m+n);
    ret.y = (m*b.y + n*a.y)/(m+n);
    ret.z = (m*b.z + n*a.z)/(m+n);
    return ret;
}
double Distance(Point a, Point b)
{
    double dist = sqrt( pow(a.x-b.x,2) + pow(a.y-b.y,2)+ pow(a.z-b.z,2) );
    return dist;
}
double solve(Point a, Point b, Point p)
{
    for(int i=1; i<=100; i++){
        Point mid1 = intersectionPointFromRatio(a,b,1,2);
        Point mid2 = intersectionPointFromRatio(a,b,2,1);
        double d1 = Distance(mid1,p);
        double d2 = Distance(mid2,p);
        if(d1<d2)
            b = mid2;
        else a = mid1;
    }
    return Distance(p,a);
}
int main()
{
    int tc,cs=1;
    Point a,b,c;
    scanf("%d",&tc);
    while(tc--){
        a = input();
        b = input();
        c = input();
        printf("Case %d: %.10f\n",cs++,solve(a,b,c));
    }
}
