#include<bits/stdc++.h>
using namespace std;
map<string, int> mp, vis;
int dir[6][3] = { {0,0,-1},{0,0,1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} };
int bfs(string s, string t)
{
    if(mp.find(s)!= mp.end() || mp.find(t)!= mp.end()) return -1;
    else if(s == t) return 0;

    int level = 0;
    queue<string> Q;
    Q.push(s);
    vis[s]++;
    while(!Q.empty()){
        level++;
        queue<string> q;
        while(!Q.empty()){
            string x = Q.front();
            Q.pop();
            for(int i=0; i<6; i++){
                string temp="xxx";
                for(int j=0; j<3; j++){
                    temp[j] = x[j] + dir[i][j];
                    if(temp[j]<'a') temp[j] = 'z';
                    else if(temp[j]>'z') temp[j] = 'a';
                }
                if(temp == t) return level;
                if(mp.find(temp)==mp.end() && vis.find(temp) == vis.end()){
                    vis[temp]++;
                    q.push(temp);
                }
            }
        }
        Q = q;
    }
    return -1;
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    string a,b,s="zzz";
    char x[30],y[30],z[30];
    int l1,l2,l3;
    int tc, n;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        cin>>a>>b;
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%s%s%s",x,y,z);
            l1=  strlen(x);
            l2 = strlen(y);
            l3 = strlen(z);
            for(int p=0; p<l1; p++){
                for(int q=0; q<l2; q++){
                    for(int r=0; r<l3; r++){
                        s[0]=x[p];
                        s[1]=y[q];
                        s[2]=z[r];
                        mp[s]++;
                    }
                }
            }
        }

        printf("Case %d: %d\n",t,bfs(a,b));
        vis.clear();
        mp.clear();
    }
}
