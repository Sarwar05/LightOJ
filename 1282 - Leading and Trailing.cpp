#include<bits/stdc++.h>
using namespace std;
int bigmod(long long a, long long b)
{
    if(b==0) return 1;
    long long x = bigmod(a, b/2);
    x = (x*x)%1000;
    if(b%2==1)
        x = (x*a)%1000;
    return x;
}
int main()
{
    int tc,a,b;
    double n,k,x;
    long long y;
    scanf("%d",&tc);
    for(int t=1; t<=tc ;t++){
        scanf("%lf%lf",&n,&k);
        x  = k*log10(n);
        //a = pow(10, x-floor(x))*100;
        y = x;
        x = x-(y*1.0);
        x = pow(10,x);
        a = x*100;
        b = bigmod(n,k);
        printf("Case %d: %03d %03d\n",t,a,b);
    }
    return 0;
}
