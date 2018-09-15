#include<bits/stdc++.h>
using namespace std;
char str[100005];
int  main()
{
    int tc, cs=1,n,m;
    string s,t;
    scanf("%d", &tc);
    while(tc--){
        map<string, int> mp;
        scanf("%d", &n);
        while(n--){
            scanf("%s", str);
            int sz = strlen(str);
            if(sz>2)
                sort(str+1, str+sz-1);
            s = string(str);
            mp[s]++;
        }
        scanf("%d", &m);
        printf("Case %d:\n", cs++);
        getchar();
        while(m--){
            gets(str);
            s = string(str);
            istringstream iss(s);
            int ans = 1;
            while(iss>>t){
                if(t.size()>3)
                    sort(t.begin()+1, t.end()-1);
                if(mp.find(t)==mp.end()){
                    ans = 0;
                    break;
                }
                ans *= mp[t];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}