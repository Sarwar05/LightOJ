#include<bits/stdc++.h>
using namespace std;
int cnt[22],mat[22][22],now[22];
int main()
{
    int tc,cs=1,n,m,a,b,c;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        int ans = 0,ride = 0;
        memset(cnt,0,sizeof cnt);
        memset(mat,0,sizeof mat);
        memset(now,0,sizeof now);
        deque<int>prog,ferri;
        for(int i=1; i<=n; i++){
            prog.push_back(i);
        }
        for(int i=1; i<=m; i++){
            ferri.push_back(i);
        }
        while(ride!=(n*m)){
            b = ferri.front();
            ferri.pop_front();
            ans+=5;
            if(now[b]!=0){
                c = now[b];
                cnt[c]++;
                ride++;
                now[b] = 0;
                if(cnt[c]!=m)prog.push_back(c);
            }
            if(!prog.empty()){
                a = prog.front();
                prog.pop_front();
            }
            else{
                ferri.push_back(b);
                continue;
            }
            vector<int> tem;
            while(mat[a][b] !=0 && !prog.empty()){
                tem.push_back(a);
                a = prog.front();
                prog.pop_front();
            }
            ferri.push_back(b);
            if(mat[a][b]!=0){
                tem.push_back(a);
                for(int i=tem.size()-1; i>=0; i--) prog.push_front(tem[i]);
                continue;
            }
            else for(int i=tem.size()-1; i>=0; i--) prog.push_front(tem[i]);
            now[b] = a;
            mat[a][b] = 1;
        }
        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}