#include<cstdio>
using namespace std;
int main()
{
    int tc,n,x;scanf("%d",&tc);
    long int height,k;
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);long int ara[n];
        scanf("%ld",&ara[0]);
        height = k  = ara[0];int ck=1;
        for(int i=1; i<n; i++,ck++){
            scanf("%ld",&ara[i]);
            x = ara[i]-ara[i-1];
            if(x == height){
                height++;
                k = height;
            }
 
            else if(x>height){
                height = x;
                k = x;
            }
 
            else if(ck==1 && x == height-1){
                height++;
                k = height;
            }
            else if( k !=0 && x == k-1)
                k--;
 
        }
        if(k==1)
            height++;
        printf("Case %d: %ld\n",t,height);
    }
    return 0;
}