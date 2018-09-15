#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926536
struct Point
{
    ll x;
    ll y;
};
inline double dist(Point a, Point b)
{
    return sqrt( pow(a.x - b.x , 2) + pow(a.y - b.y, 2) );
}
Point point[50004];
Point st[42];
void getExtremePoint(int n)///at index 0
{
    int pos = 0;
    for(int i=1; i<n; i++){
        if(point[i].y < point[pos].y || (point[i].y == point[pos].y && point[i].x < point[pos].x))
            pos = i;
    }
    swap(point[0], point[pos]);
}
inline int triArea(Point p1, Point p2, Point p3)
{
    ll area = p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y);
    if(area==0) return area;
    else return area/llabs(area);
}
inline bool comp(Point p1, Point p2)
{
    int tri = triArea(point[0],p1,p2);
    if(tri<0) return false;
    if(tri==0 && dist(point[0], p1) > dist(point[0], p2)) return false;
    return true;
}
int id;
void genConvexPoints(int n)
{
    getExtremePoint(n);
    sort(point+1, point+n, comp);
    id = 0;
    for(int i=0; i<3 && i<n; i++)
        st[id++] = point[i];
    for(int i = 3; i<n; i++){
        while(triArea(st[id-2], st[id-1], point[i]) < 0)
            id--;
        st[id++] = point[i];
    }
}
int main()
{
    int tc,cs=1,n,d;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&d);
        for(int i=0; i<n; i++)
            scanf("%lld%lld",&point[i].x,&point[i].y);
        genConvexPoints(n);
        double ans = 0;
        st[id++] = st[0];
        for(int i=0; i<id-1; i++)
            ans+=dist(st[i], st[i+1]);
        ans+=(2.0*PI*d);
        printf("Case %d: %.5f\n",cs++,ans);
    }
}
