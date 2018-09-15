#include<bits/stdc++.h>
using namespace std;
const int N= 1000*2+5;
const int M= 10005*10+5;
const int INF=1000000009;
int u[M],v[M],cap[M],flow[M],first[N],Next[M],e;
int q[N],dist[N],work[N],source,sink;
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val = 1)
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
int main()
{
    int tc,cs=1,n,m,a,b;
    scanf("%d",&tc);
    source = 0, sink = N-2;
    while(tc--){
        init();
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d",&a,&b);
            insert(a,b+1000);
        }
        for(int i=1; i<=n; i++){
            insert(source,i);
            insert(i+1000,sink);
        }
        printf("Case %d: %d\n",cs++,n-dinic());
    }
    return 0;
}
