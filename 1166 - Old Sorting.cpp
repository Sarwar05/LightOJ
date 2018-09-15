#include<bits/stdc++.h>
using namespace std;
 
int Process(int ara[], int len)
{
    int count = 0;
    for(int i=1; i<=len; i++){
        if(ara[i]==i)
            continue;
        else{
            int a= ara[i];
            swap(ara[i],ara[a]);
            count++;
            i--;
        }
    }
    return count;
}
int main()
{
    int tc, n;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        int ara[n+2];
        for(int i=1; i<=n; i++) scanf("%d",&ara[i]);
        int counter = Process(ara,n);
        printf("Case %d: %d\n",t,counter);
    }
}