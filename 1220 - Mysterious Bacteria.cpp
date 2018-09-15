#include<bits/stdc++.h>
using namespace std;
long long powl(int a, int p)
{
    long long  ret = 1;
    for(int i=1; i<=p; i++)
        ret*=a;
    return ret;
}
int main()
{
    int tc; long long x,b,p;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%lld",&x);
        if(x>0){
            for(int i=32; i>=0; i--){
                b = pow(x, 1.0/i) + 0.0000001;
                if(powl(b,i)==x){
                    printf("Case %d: %d\n", cs, i);
                    break;
                }
            }
        }
        else{
            x = -x;
            for(int i=31; i>0; i-=2){
                b = pow(x, 1.0/i) + 0.0000001;
                if(powl(b,i)==x){
                    printf("Case %d: %d\n", cs, i);
                    break;
                }
            }
        }
    }
    return 0;
}
