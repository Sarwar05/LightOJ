#include<stdio.h>
int main()
{
    int n,t,i,a,b;
    scanf("%d",&n);
    if(n<=25){
        for(i=1;i<=n;i++){
            scanf("%d",&t);
            if(t>10){
               b=t-10;
               a=t-b;
            }
            else{
                b=t;
                a=0;
            }
            printf("%d %d\n",a,b);
        }
    }

    return 0;
}
