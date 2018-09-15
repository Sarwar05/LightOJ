#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;
    int id;
    Point(int _x, int _y, int _id)
    {
        x = _x;
        y = _y;
        id = _id;
    }
};
vector<Point> point;
int triArea(Point p1, Point p2, Point p3)
{
    int area = p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y);
    if(area==0) return area;
    return area/abs(area);
}
double dist(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
bool comp(Point p1, Point p2)
{
    int tri = triArea(point[0], p1, p2);
    if(tri<0) return false;
    if(tri==0 && (dist(point[0], p1) > dist(point[0], p2))) return false;
    return true;
}
int main()
{
    int tc,n,x,y, cs=1;
    scanf("%d",&tc);
    while(tc--){
        point.clear();
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d%d",&x,&y);
            point.push_back(Point(x,y,i));
        }
        printf("Case %d:\n",cs++);
        int ok = 0;
        for(int i=2; i<n; i++){
            if(triArea(point[0], point[1], point[i]) != 0){
                ok = 1;
                break;
            }
        }
        if(ok==0){
            printf("Impossible\n");
            continue;
        }
        int pos = 0;
        for(int i=1; i<n; i++){
            if(point[i].y < point[pos].y || ( point[i].y == point[pos].y && point[i].x < point[pos].x ))
                pos = i;
        }
        swap(point[pos], point[0]);
        sort(point.begin()+1, point.end(), comp);
        pos = n-1;
        for(int i=n-2; i>=0; i--){
            if(triArea(point[0], point[n-1], point[i])==0)
                pos--;
            else break;
        }
        printf("%d",point[0].id);
        for(int i=1; i<pos; i++)
            printf(" %d", point[i].id);
        for(int i=n-1; i>=pos; i--)
            printf(" %d", point[i].id);
        printf("\n");
    }
}
