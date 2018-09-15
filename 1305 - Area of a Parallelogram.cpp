#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int tc;cin>>tc;
    int ax,ay,bx,by,cx,cy,dx,dy; double a,b,c,s,half;
    long long int area;
    for(int t=1; t<=tc; t++){
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        dx = cx - (bx - ax);
        dy = ay + (cy - by);
        a = sqrt(pow((ax-bx),2) + pow((ay-by),2));
        b = sqrt(pow((ax-cx),2) + pow((ay-cy),2));
        c = sqrt(pow((bx-cx),2) + pow((by-cy),2));
        s = (a+b+c)/2.0;
        half = sqrt(s*(s-a)*(s-b)*(s-c));
        area = round(half * 2.0);
        cout<<"Case "<<t<<": "<<dx<<" "<<dy<<" "<<area<<endl;
    }
 
    return 0;
}