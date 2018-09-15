#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Point
{
    ll x;
    ll y;
};
pair<int, int> input[100005];
Point point[100005];
Point st[1002];
ll triArea(Point p1, Point p2, Point p3)
{
    return p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y);
}
double dist(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
bool comp(Point p1, Point p2)
{
    ll tri = triArea(point[0], p1, p2);
    if(tri<0) return false;
    if(tri==0 && dist(point[0], p1) > dist(point[0], p2)) return false;
    return true;
}
double getAngle(Point p1, Point p2, Point p3)
{
    double a = dist(p2,p1);
    double c = dist(p2,p3);
    double b = dist(p1,p3);
    double ddd = (a*a + c*c - b*b)/(2.0*a*c);
    return acos(ddd);
}
int main()
{
    int tc,cs=1,n,x,y;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d%d",&input[i].first, &input[i].second);
        sort(input, input+n);
        int cnt = 0;
        point[cnt].x = input[0].first;
        point[cnt].y = input[0].second;
        cnt++;
        for(int i=1; i<n; i++){
            if(input[i]==input[i-1]) continue;
            point[cnt].x = input[i].first;
            point[cnt].y = input[i].second;
            cnt++;
        }
        n = cnt;
        int pos = 0;
        for(int i=1; i<n; i++){
            if(point[i].y < point[pos].y || (point[i].y == point[pos].y && point[i].x < point[pos].x))
                pos = i;
        }
        swap(point[0], point[pos]);
        sort(point+1, point+n, comp);
        int id = 0;
        for(int i=0;i<3 && i<n; i++)
            st[id++] = point[i];
        for(int i=3; i<n; i++){
            while(id>=2 && triArea(st[id-2], st[id-1], point[i]) < 0)
                id--;
            st[id++] = point[i];
        }
        double ans = 200;
        if(id<3) ans = 0;
        else{
            st[id++] = st[0];
            st[id++] = st[1];
            for(int i=1; i<=id-2; i++)
                ans = min(ans, getAngle(st[i-1], st[i], st[i+1]));
        }
        printf("Case %d: %.10f\n",cs++,(ans*180)/acos(-1.0));
    }
    return 0;
}
