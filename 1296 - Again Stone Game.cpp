#include<bits/stdc++.h>
using namespace std;
int getGrundy(int n)
{
    for(int i=1; ; i++){
        int now = (1<<i);
        int mod = (1<<(i-1))-1;
        if(n%now==mod) return n/now;
    }
}
int main()
{
    int tc,cs=1,n,a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        int xxx=0;
        while(n--){
            scanf("%d",&a);
            xxx^=getGrundy(a);
        }
        printf("Case %d: %s\n",cs++,(xxx)?"Alice":"Bob");
    }
    return 0;
}
