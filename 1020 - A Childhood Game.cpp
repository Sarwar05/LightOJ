#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    char str[7];
    long long int n;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%lld",&n);
        scanf("%s",str);
        printf("Case %d: ",t);
        if(strcmp(str,"Alice")==0){
            if(n%3 == 1) printf("Bob");
            else  printf("Alice");
        }
        else{
            if(n%3  == 0) printf("Alice");
            else printf("Bob");
        }
        printf("\n");
    }
 
    return 0;
}