#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20002;
const int M=20002*4*2;
const int INF=0x3f3f3f3f;
int u[M],v[M],cap[M],flow[M],first[N],Next[M],e;
int q[N],dist[N],work[N],source,sink;
int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val)
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
int dinic(int n)
{
    int ans=0;
    while(bfs()){
        for(int i=0;i<=n;i++) work[i]=first[i];
        while(1){
            int tmp=dfs(source,INF);
            if(tmp==0) break;
            ans+=tmp;
        }
    }
    return ans;
}
char grid[102][102];
int main()
{
    int tc,m,n,cs=1,total;
    scanf("%d",&tc);
    while(tc--){
        total = 0;
        scanf("%d%d",&m,&n);
        init();
        source = 0, sink = 2*n*m + 1;
        for(int i=1; i<=m; i++) scanf("%s",grid[i]);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                /// split thar node
                int id = (i-1)*n + j;
                int to = (m*n)+id;
                insert(id,to,1);;
                ///connect to adjacent cell
                for(int k=0; k<4; k++){
                    int xx = i+dirx[k];
                    int yy = j+diry[k];
                    if(xx>=1 && xx<=m && yy>=1 && yy<=n && grid[xx][yy-1]!='*'){
                        int nid = (xx-1)*n + yy;
                        insert(to,nid,1);
                    }
                }
                if(j==1||j==n||i==1||i==m){/// if boundary cell
                    insert(to,sink,1);
                }
                if(grid[i][j-1]=='*'){/// if a worker
                    total++;
                    insert(0,id,1);
                }
            }
        }
        printf("Case %d: %s\n",cs++,dinic(sink)==total ? "yes" : "no");
    }
    return 0;
}
