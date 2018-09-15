#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vp;
vp target;
char grid[11][11];
int dirx[] = {1, 0, -1, 0};
int diry[] = {0, 1, 0, -1};
int n;
int bfs(pii a, pii b, pii c)
{
    vp s;
    pii aa,bb,cc;
    s.push_back(a);
    s.push_back(b);
    s.push_back(c);
    sort(s.begin(), s.end());
    map<vp,int> mp;
    mp[s] = 1;
    int ret = 0;
    queue<vp> q,q2;
    q.push(s);
    while(!q.empty()){
        ret++;
        while(!q.empty()){
            s = q.front();
            q.pop();
            //if(s==target) return ret;
            a = s[0];
            b = s[1];
            c = s[2];
            for(int i=0; i<4; i++){
                aa.ff = a.ff + dirx[i];
                aa.ss = a.ss + diry[i];
                bb.ff = b.ff + dirx[i];
                bb.ss = b.ss + diry[i];
                cc.ff = c.ff + dirx[i];
                cc.ss = c.ss + diry[i];
                if(aa.ff<0 || aa.ff>=n || aa.ss<0 || aa.ss>=n || grid[aa.ff][aa.ss]=='#'){
                    aa = a;
                }
                if(bb.ff<0 || bb.ff>=n || bb.ss<0 || bb.ss>=n || grid[bb.ff][bb.ss]=='#'){
                    bb = b;
                }
                if(cc.ff<0 || cc.ff>=n || cc.ss<0 || cc.ss>=n || grid[cc.ff][cc.ss]=='#'){
                    cc = c;
                }
                if(aa==bb){
                    aa=a;
                    bb = b;
                }
                if(bb==cc){
                    bb = b;
                    cc = c;
                }
                if(cc==aa){
                    cc = c;
                    aa = a;
                }
                s[0] = aa;
                s[1] = bb;
                s[2] = cc;
                sort(s.begin(), s.end());
                if(s==target) return ret;
                if(mp.find(s)== mp.end()){
                    mp[s] = 1;
                    q2.push(s);
                }
            }
        }
        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
    }
    return -1;
}
int main()
{
    int tc,cs=1;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        pii a,b,c;
        target.clear();
        for(int i=0; i<n; i++){
            scanf("%s", grid[i]);
            for(int j=0; j<n; j++){
                if(grid[i][j]=='A'){
                    a = make_pair(i,j);
                }
                if(grid[i][j]=='B'){
                    b = make_pair(i,j);
                }
                if(grid[i][j]=='C'){
                    c = make_pair(i,j);
                }
                if(grid[i][j]=='X'){
                    target.push_back(make_pair(i,j)) ;
                }
            }
        }
        sort(target.begin(), target.end());
        printf("Case %d: ", cs++);
        int ans = bfs(a,b,c);
        if(ans==-1)
            printf("trapped\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
