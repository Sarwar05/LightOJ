#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int main()
{
    long int tc,n,a,q;char c;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        deque<int> dq;
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            dq.push_back(a);
        }
        printf("Case %d:\n",t);
        for(int i=1; i<=q; i++){getchar();
            scanf("%c%d",&c,&a);
            if(c == 'a'){
                dq.push_back(a);
                n++;
            }
            else if(c == 'c'){
                if(a <= n){
                    n--;
                    printf("%d\n",dq.at(a-1));
                    deque<int>::iterator it;
                    it = dq.begin()+a-1;
                    dq.erase(it);
                }
                else
                    printf("none\n");
 
            }
        }
 
    }
    return 0;
}
 
