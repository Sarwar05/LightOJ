#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    int tc;scanf("%d",&tc);
    long long int digit,mod,res,n,num;
    for(int t=1; t<=tc; t++){
        scanf("%lld%lld",&n,&digit);
        num = digit%n;
        mod = digit%n;
        digit = mod;
        res = 1;
        while(mod!=0){
            digit = digit*10 + num;
            //cout<<"dig:  "<<digit<<endl;
            mod = digit%n;
            digit = mod;
            res++;
        }
        printf("Case %d: %lld\n",t,res);
    }
}
 