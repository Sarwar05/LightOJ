#include<stdio.h>
int main()
{
    long long  t,i,bin,cou,p;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&bin);
        cou=0;
        while(bin!=0){
            p=bin%2;
            if(p==1)
                cou++;
            bin/=2;
        }
        if(cou%2==0)
            printf("Case %lld: even\n",i);
        else
            printf("Case %lld: odd\n",i);
    }
    return 0;
}