#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,len,ans;string s;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&len);
        cin>>s;
        ans = 0;
        for(int i=0; i<len; ){
            while( i<len && s[i]=='#') i++;
            if(i<len){
                ans++;
                i+=3;
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
 