#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,n,a,b,c;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        map<int,int> Map;
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            Map[a]++;
        }
        int count = 0;
        map<int, int>::iterator it = Map.begin();
        while(it!= Map.end()){
            a = it->first;
            b = it->second;
            c = b/(a+1);
            count+=(c*(a+1));
            if(b%(a+1) != 0)
                count+=(a+1);
            it++;
        }
        printf("Case %d: %d\n",t,count);
    }
    return 0;
}
