#include<stdio.h>
int main()
{
    int you,lift,test,i,tem,time;
    scanf("%d",&test);
    for(i=1; i<=test; i++){
        scanf("%d%d",&you,&lift);
        if(you<=lift)
            time = (lift*4) + 19;
        else
            time = ((you-lift)+you)*4 + 19;
        printf("Case %d: %d\n",i,time);
    }
    return 0;
}
 