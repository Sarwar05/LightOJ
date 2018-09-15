#include<stdio.h>
int main()
{
    int n,t,i,l;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        int ara[n],sum;
        sum=0;
        for(l=0;l<n;l++){
            scanf("%d",&ara[l]);
            if(ara[l]>0)
                sum+=ara[l];
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
 