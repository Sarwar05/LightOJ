#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc;
    int n, p,q;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d%d",&n,&p,&q);
        int ara[n];
        for(int i=0; i<n; i++) scanf("%d",&ara[i]);
        int count = 0;
        for(int i=0; i<n; i++){
            if(count == p)
                break;
            if(q-ara[i]>=0){
                count++;
                q-=ara[i];
            }
            else break;
        }
        printf("Case %d: %d\n",t,count);
    }
    return 0;
}
