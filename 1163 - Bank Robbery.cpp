#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;scanf("%d",&tc);
    ll a,b;
    long double rat = ((long double)10.0/(long double)9.0), x;
    for(int cs=1; cs<=tc; cs++){
        scanf("%lld",&a);
        printf("Case %d:", cs);
        x = a;
        a = rat*a;
        if(a%10==0)
            printf(" %lld", a-1);
        printf(" %lld",a);
        printf("\n");
    }

    return 0;
}
