#include<bits/stdc++.h>
using namespace std;
const int N=15010;
const int M=15010;
const int INF=100000009;
int u[M],v[M],cap[M],flow[M],first[N],Next[M],e;
int q[N],dist[N],work[N],source,sink;
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void addEdge(int f,int t,int val)
{
    u[e]=f; v[e]=t; cap[e]=val; flow[e]=0;
    Next[e]=first[u[e]]; first[u[e]]=e++;
    u[e]=t; v[e]=f; cap[e]=0; flow[e]=0;
    Next[e]=first[u[e]]; first[u[e]]=e++;
}
bool bfs()
{
    memset(dist,-1,sizeof(dist));
    dist[source]=0;
    int l=0,r=0;
    q[r++]=source;
    while(l<r){
        int x=q[l++];
        for(int i=first[x];i+1;i=Next[i]){
            if(flow[i]<cap[i]&&dist[v[i]]==-1){
                dist[v[i]]=dist[x]+1;
                q[r++]=v[i];
            }
        }
    }
    return dist[sink]!=-1;
}
int dfs(int x,int val)
{
    if(x==sink) return val;
    for(int &i=work[x];i+1;i=Next[i]){
        int y=v[i],tmp;
        if(flow[i]<cap[i]&&dist[y]==dist[x]+1&&(tmp=dfs(y,min(val,cap[i]-flow[i])))>0){
            flow[i]+=tmp;
            flow[i^1]-=tmp;
            return tmp;
        }
    }
    return 0;
}
int dinic()
{
    int ans=0;
    while(bfs()){
        for(int i=0;i<N;i++) work[i]=first[i];
        while(1){
            int tmp=dfs(source,INF);
            if(tmp==0) break;
            ans+=tmp;
        }
    }
    return ans;
}
///
struct Input
{
    int a;
    int b;
    int c;
    Input(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
        if(a>b) swap(a,b);
    }
};
vector<Input>input;
bool check(int val,int k, int n)
{
    init();
    for(int i=1; i<=n; i++){
        addEdge(i,i+200,1);
    }
    int inf = INF;
    addEdge(0,0+200,inf);
    addEdge(n+1,n+1+200,inf);
    for(int i=0; i<input.size(); i++){
        if(input[i].c<=val){
            addEdge(input[i].a+200,input[i].b,1);
        }
    }
    int ans = dinic();
    if(ans>=k) return true;
    else return false;
}
int main()
{
    int n,t,p,q,d,k,cs=1,tc;
    int inf = INF;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        input.clear();
        scanf("%d",&t);
        for(int i=1; i<=t; i++){
            scanf("%d%d%d",&p,&q,&d);
            if(p>q) swap(p,q);
            input.push_back(Input(p,q,d));
        }
        source = 0,sink = n+1+200;
        scanf("%d",&k);
        int lo = 0,hi = inf-10;
        int ans = inf;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid,k,n)){
                ans = min(ans,mid);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        if(ans==inf) printf("Case %d: no solution\n",cs++);
        else printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
