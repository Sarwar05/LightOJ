#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc, cs=1, t;
    ll a;
    char s[205];
    scanf("%d", &tc);
    while(tc--){
        bool ans = false;
        scanf("%s%lld",s, &a);
        if(a<0) a*=(-1);
        int i = 0;
        int sz = strlen(s);;
        ll num = 0;
        if(!isdigit(s[0])) i++;
        for(i; i<sz; i++){
            t = s[i]-'0';
            num = num*10 + t;
            while(num>=a) num-=a;
        }
        if(num==0) ans = true;

        printf("Case %d: %s\n",cs++,  ans?"divisible" : "not divisible");
    }
    return 0;
}
