#include<bits/stdc++.h>
using namespace std;
int fun(int n, int k)
{
    if(n==1) return 1;
    else return (fun(n-1, k)+k-1)%n + 1;
}
int main()
{
    int tc; int n,k,ans;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%d%d",&n,&k);
        ans = fun(n,k);
        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}
