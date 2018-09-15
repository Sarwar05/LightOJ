#include<bits/stdc++.h>
using namespace std;
double calculateArea(double a, double b, double c)
{
    double s = (a+b+c)/2;
    double area = s*(s-a)*(s-b)*(s-c);
    area = sqrt(area);
    return area;
}
int main()
{
    int tc, cs=1;
    double ab,ac,bc,ad,ae,de,rat,r,lo,hi,mid,area;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&rat);
        double totalArea = calculateArea(ab,ac,bc);
        lo = 0, hi = ab;
        for(int i=1; i<=100; i++){
            mid = (lo+hi)/2;
            ad = mid;
            ae = (ad*ac)/ab;
            de = (ad*bc)/ab;
            area = calculateArea(ad,ae,de);
            r = area/(totalArea-area);
            if(r>rat){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        printf("Case %d: %.10f\n", cs++, mid);
    }
    return 0;
}
