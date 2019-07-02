/// https://math.stackexchange.com/questions/1871065/euler-path-for-directed-graph

#include<bits/stdc++.h>
using namespace std;
int in[26], out[26], par[26];
int findPar(int r)
{
    return par[r] = (par[r]==r) ? r : findPar(par[r]);
}
char str[1002][22];
vector<int> input[26][26];
int idx[26][26];
int adj[26][26];

int main()
{
    int tc, cs=1,n,a,b;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<26; i++){
            in[i] = out[i] = 0;
            par[i] = i;
            for(int j=0; j<26; j++){
                input[i][j].clear();
                adj[i][j] = 0;
                idx[i][j] = 0;
            }
        }
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%s",str[i]);
            int len = strlen(str[i]);
            a = str[i][0] - 'a';
            b = str[i][len-1] - 'a';
            input[a][b].push_back(i);
            out[a]++;
            in[b]++;
            adj[a][b]++;
            a = findPar(a);
            b = findPar(b);
            if(a!=b) par[a] = b;
        }
        int compo = 0;
        set<int> st;
        for(int i=0; i<26; i++)
            if(in[i] || out[i])
                st.insert(findPar(i));
        if(st.size()==1) compo = 1;
        int xin=0, xout=0, other = 0;
        a=-1, b=-1;
        if(compo){
            for(int i=0; i<26; i++){
                if(in[i]==0 && out[i]==0) continue;
                if(in[i]-out[i]==1) {
                    xin++;
                    b = i;
                }
                else if(out[i]-in[i]==1){
                    xout++;
                    a = i;
                }
                else if(in[i]!=out[i]) other++;
            }
        }
        if(compo && ((xin==0&&xout==0)||(xin==1&&xout==1)) && other==0){
            printf("Case %d: Yes\n", cs++);
            int start;
            for(int i=0; i<26; i++){
                if(in[i]||out[i]){
                    start = i;
                    break;
                }
            }
            if(b!=-1){
                start = b;
                adj[b][a]++;
            }
            stack<int> stk;
            vector<int> path;
            stk.push(start);
            while(!stk.empty()){
                int u = stk.top();
                int got = 0;
                for(int i=0; i<26; i++){
                    if(adj[u][i]){
                        stk.push(i);
                        adj[u][i]--;
                        got = 1;
                        break;
                    }
                }
                if(got==0){
                    path.push_back(u);
                    stk.pop();
                }
            }
            reverse(path.begin(), path.end());
            vector<int> ans;
            if(b!=-1){
                int i = 0;
                while(path[i]!=b || path[i+1]!=a) i++;
                for(int id = i+1; id<path.size(); id++)
                    ans.push_back(path[id]);
                for(int id = 1; id<=i; id++)
                    ans.push_back(path[id]);
            }
            else ans = path;
            for(int id=1; id<ans.size(); id++){
                a = ans[id-1];
                b = ans[id];
                int index = idx[a][b]++;
                index = input[a][b][index];
                printf("%s",str[index]);
                if(id==ans.size()-1) printf("\n");
                else printf(" ");
            }
        }
        else printf("Case %d: No\n", cs++);
    }
}
