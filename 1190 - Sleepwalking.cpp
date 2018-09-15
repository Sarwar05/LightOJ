#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-10
struct Point
{
    int x;
    int y;
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
int orientation(Point a, Point b, Point c)
{
    int res = (b.y-a.y)*(c.x-b.x) - (c.y-b.y)*(b.x-a.x);
    if(res==0) return 0;
    return (res>0) ? 1 : 2;
}
bool onSegment(Point a, Point b, Point p)
{
    return (p.x>=min(a.x,b.x) && p.x<=max(a.x,b.x) && p.y>=min(a.y,b.y) && p.y<=max(a.y,b.y));
}
bool intersect(Point a, Point b, Point p, Point q)
{
    int o1 = orientation(a,b,p);
    int o2 = orientation(a,b,q);
    int o3 = orientation(p,q,a);
    int o4 = orientation(p,q,b);
    if(o1!=o2 && o3!=o4) return true;
    if(o1==0 && onSegment(a,b,p)) return true;
    if(o2==0 && onSegment(a,b,q)) return true;
    if(o3==0 && onSegment(p,q,a)) return true;
    if(o4==0 && onSegment(p,q,b)) return true;
    return false;
}
int main()
{
    int tc,cs=1,n,q,x,y;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        vector<Point> v;
        for(int i=0; i<n; i++){
            scanf("%d%d",&x,&y);
            v.push_back(Point(x,y));
        }
        v.push_back(v[0]);
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&x,&y);
            Point p(x,y);
            Point q(x+30000,y+30001);
            int cnt=0;
            for(int i=1; i<=n; i++){
                if(intersect(v[i-1], v[i], p,q)){
                    cnt++;
                    if(orientation(v[i-1], v[i], p)==0){
                        cnt=onSegment(v[i-1], v[i],p);
                        break;
                    }
                }
            }
            printf("%s\n",(cnt%2==1)? "Yes" : "No");
        }
    }
    return 0;
}
