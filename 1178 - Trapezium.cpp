#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define vi vector<int>
#define PI acos(-1.0)
double TriAreaSides(double a, double b, double c)
{
    double s = (a+b+c)/2.0;
    double ret = s*(s-a)*(s-b)*(s-c);
    return sqrt(ret);
}
int main()
{
    double a,b,c,d,ans;
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        double diff = fabs(a-c);
        double triArea = TriAreaSides(diff,b,d);
        double height = (triArea*2)/diff;
        ans = 0.5*height*(a+c);
        printf("Case %d: %.10f\n",cs++,ans);
    }
    return 0;
}
