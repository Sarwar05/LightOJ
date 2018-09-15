#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,cs=1,n,a,x;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        int non_one = 0,xxx=0;
        while(n--){
            scanf("%d",&x);
            xxx^=x;
            if(x-1)
                non_one++;
        }
        if(!non_one)xxx^=1;
        printf("Case %d: %s\n",cs++,(xxx)?"Alice":"Bob");
    }
    return 0;
}
