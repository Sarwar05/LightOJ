#include<bits/stdc++.h>
using namespace std;
 
#define mx 10005
 
map<string, int> mp;
 
string a,b;
 
int ind[mx] = {0};
 
vector<int> adj[mx];
 
void topSort(int n)
{
    for(int i=1; i<=n; i++){
 
        if(ind[i]==0){
 
            int sz = adj[i].size();
            for(int j=0; j<sz; j++){
                ind[ adj[i][j] ]--;
            }
 
            ind[i] = -1;
            i = 0;
 
        }
 
    }
 
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc,n,x,y;
 
    scanf("%d",&tc);
 
    for(int t=1; t<=tc; t++){
 
        int cunt = 0;
        scanf("%d",&n);
 
        for(int i=1; i<=n; i++){
 
            cin>>a>>b;
 
            if(mp.find(a) != mp.end()){
                x = mp[a];
            }
            else{
                mp[a] = (++cunt);
                x = cunt;
            }
 
            if(mp.find(b) != mp.end()){
                y = mp[b];
            }
            else{
                mp[b] = (++cunt);
                y = cunt;
            }
 
            adj[x].push_back(y);
 
            ind[y]++;
        }
 
        topSort(cunt);
 
        bool ans = true;
 
        for(int i=1; i<=cunt; i++){
 
            if(ind[i]>0){
                ans = false;
                break;
            }
 
        }
 
        printf("Case %d: ",t);
        ans == true ? printf("Yes\n") : printf("No\n");
 
        if(t != tc){
 
            mp.clear();
 
            for(int i=1; i<=cunt; i++){
                ind[i] = 0;
                adj[i].clear();
            }
 
 
        }
 
    }
 
    return 0;
}
 