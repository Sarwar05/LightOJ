#include<bits/stdc++.h>
using namespace std;
#define inf 1000000007
int main()
{
    int tc,cs=1,x1,x2,y1,y2,z1,z2,a,b,c,d,e,f,n;
    scanf("%d",&tc);
    while(tc--){
        a=b=c=-inf;
        d=e=f=inf;
        scanf("%d",&n);
        while(n--){
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
            a = max(a,x1);
            b = max(b,y1);
            c = max(c,z1);
            d = min(d,x2);
            e = min(e,y2);
            f = min(f,z2);
        }
        int area = (d-a)*(e-b)*(f-c);
        if(area<0) area = 0;
        printf("Case %d: %d\n",cs++,area);
    }
    return 0;
}
