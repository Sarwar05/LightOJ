#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, cs=1, n, a, neg, p, q, gc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        neg=p=0;
        q = n;
        while(n--){
            scanf("%d", &a);
            if(a<0){
                neg++;
                p-=a;
            }
            else{
                p+=a;
            }
        }
        q -=neg;
        printf("Case %d: ", cs++);
        if(q==0){
            printf("inf\n");
        }
        else{
            gc = __gcd(p,q);
            printf("%d/%d\n",p/gc, q/gc);
        }
    }
 
    return 0;
}
 