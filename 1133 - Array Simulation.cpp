#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int tc,n,o,d,a,b;char c;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d %d",&n,&o);
        int ara[n];
        for(int i=0; i<n; i++)
            scanf("%d",&ara[i]);
        for(int j=1; j<=o; j++){
            cin>>c;
            if(c == 'S'){
                scanf("%d",&d);
                for(int i=0; i<n; i++)
                    ara[i]+=d;
            }
            else if(c == 'M'){
                scanf("%d",&d);
                for(int i=0; i<n; i++)
                    ara[i]*=d;
            }
            else if(c == 'D'){
                scanf("%d",&d);
                for(int i=0; i<n; i++)
                    ara[i]/=d;
            }
            else if(c == 'R'){
                reverse(ara,ara+n);
            }
 
            else if(c == 'P'){
                scanf("%d %d",&a,&b);
                swap(ara[a],ara[b]);
            }
        }
        printf("Case %d:\n",t);
        for(int i=0; i<n; i++){
            printf("%d",ara[i]);
            if(i == n-1)
                printf("\n");
            else
                printf(" ");
        }
 
    }
 
    return 0;
}