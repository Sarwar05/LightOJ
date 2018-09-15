#include<stdio.h>
long long bin(long long a)
{
    long long i,b,r,p;
    i=0;p=1;
    while(a!=0){
        r=a%2;
        a/=2;
        i=i+ r*p;
        p*=10;
    }
    return i;
}
int main()
{
    long long i,t,a,b,c,d,w,x,y,z, bia,bib,bic,bid;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%lld",&a);
        getchar();
        scanf("%lld",&b);
        getchar();
        scanf("%lld",&c);
        getchar();
        scanf("%lld",&d);
        getchar();
        bia=bin(a);bib=bin(b);bic=bin(c);bid=bin(d);
        scanf("%lld",&w);
        getchar();
        scanf("%lld",&x);
        getchar();
        scanf("%lld",&y);
        getchar();
        scanf("%lld",&z);
        getchar();
        if(w==bia && x==bib && y== bic && z==bid)
            printf("Case %lld: Yes\n",i);
        else
            printf("Case %lld: No\n",i);
    }
    return 0;
}