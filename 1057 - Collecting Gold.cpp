#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define inf 10000007
char str[22][22];
int dist[22][22];
int mat[16][16];
int dp[16][(1<<16)+2];
int dirx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int diry[] = {-1,+1,+0,+0,+1,+1,-1,-1};
vector<pii> gold;
pii init;
map<pii, int> mp;
int m,n, val;
struct Node
{
    int x;
    int y;
    int cost;
    Node(int a, int b, int c)
    {
        x = a;
        y = b;
        cost = c;
    }
    bool operator<(const Node& ob)const
    {
        return cost>ob.cost;
    }
};
void dijkstra(int x, int y)
{
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dist[i][j] = inf;
        }
    }
    dist[x][y] = 0;
    priority_queue<Node> pq;
    pq.push(Node(x,y,0));
    while(!pq.empty()){
        x = pq.top().x;
        y = pq.top().y;
        int cost = pq.top().cost;
        pq.pop();
        for(int i=0; i<8; i++){
            int xx = x + dirx[i];
            int yy = y + diry[i];
            if(xx>=0 && xx<m && yy>=0 && yy<n){
                if(dist[xx][yy] > cost+1){
                    dist[xx][yy] = cost+1;
                    pq.push(Node(xx,yy,cost+1));
                }
            }
        }
    }
}
void process()
{
    map<pii, int> :: iterator it = mp.begin();
    while(it!=mp.end()){
        int id = it->second;
        pii now = it->first;
        dijkstra(now.first, now.second);
        map<pii, int> :: iterator it2 = mp.begin();
        while(it2!=mp.end()){
            int id2 = it2->second;
            now = it2->first;
            mat[id][id2] = dist[now.first][now.second];
            it2++;
        }
        it++;
    }
}
int setBit(int N, int pos)
{
    return (N|(1<<pos));
}
bool checkBit(int N, int pos)
{
    return (N&(1<<pos));
}
int fun(int pos, int mask)
{
    if(mask==((1<<val)-1)) return mat[pos][0];
    int &ret = dp[pos][mask];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i=1; i<val; i++){
        if(!checkBit(mask, i)){
            ret = min(ret, mat[pos][i] + fun(i, setBit(mask,i)));
        }
    }
    return ret;
}
int solve()
{
//    for(int i=0; i<val; i++){
//        for(int j=0; j<val; j++){
//            cout<<mat[i][j]<< " ";
//        }
//        cout<<endl;
//    }
    memset(dp, -1, sizeof dp);
    return fun(0,1);
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&m,&n);
        gold.clear();
        pii init;
        mp.clear();
        val = 1;
        for(int i=0; i<m; i++){
            scanf("%s",str[i]);
            for(int j=0; j<n; j++){
                if(str[i][j]=='x'){
                    init = {i,j};
                    mp[ {i,j} ] = 0;
                }
                else if(str[i][j]=='g'){
                    gold.push_back({i,j});
                    mp[ {i,j} ] = val++;
                }
            }
        }
        process();
        int ans = solve();
        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}
