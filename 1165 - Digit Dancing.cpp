#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
map<vi, int> mp;
bool check(vi& v)
{
    for(int i=0; i<8; i++)
        if(abs(v[i])!=(i+1)) return false;
    return true;
}
struct Node
{
    vi v;
    int cost;
};
int prime[20] = {0};
vi change1(vi v, int id1, int id2)
{
    for(int i=id2-1; i>id1; i--){
        swap(v[i],v[i+1]);
    }
    if(abs(v[id1])>abs(v[id1+1])) swap(v[id1],v[id1+1]);
    return v;
}
vi change2(vi v, int id1, int id2)
{
    for(int i=id1+1; i<id2; i++){
        swap(v[i],v[i-1]);
    }
    if(abs(v[id2-1])>abs(v[id2])) swap(v[id2],v[id2-1]);
    return v;
}
int bfs(vi v)
{
    mp.clear();
    if(check(v)) return 0;
    queue<Node> q;
    Node ob;
    ob.v = v;
    mp[v]++;
    ob.cost = 0;
    q.push(ob);
    while(!q.empty()){
        vi u = q.front().v;
        int cost = q.front().cost;
        q.pop();
        for(int i=0; i<8; i++){
            for(int j=i+1; j<8; j++){
                if(u[i]*u[j] < 0 && prime[ abs(u[i])+abs(u[j]) ]){
                    vi v = change1(u,i,j);
                    if(mp.find(v)==mp.end()){
                        if(check(v)) return (cost+1);
                        ob.v = v;
                        ob.cost = cost+1;
                        q.push(ob);
                        mp[v]++;
                    }
                    v = change2(u,i,j);
                    if(mp.find(v)==mp.end()){
                        if(check(v)) return (cost+1);
                        ob.v = v;
                        ob.cost = cost+1;
                        q.push(ob);
                        mp[v]++;
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    prime[2] = 1;
    prime[3] = 1;
    prime[5] = 1;
    prime[7] = 1;
    prime[11] = 1;
    prime[13] = 1;
    int tc,cs=1;
    vi v(8);
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<8; i++) scanf("%d",&v[i]);
        printf("Case %d: %d\n",cs++,bfs(v));
    }
    return 0;
}
/**
5
1 2 4 5 6 -7 -3 8
1 2 3 4 5 6 7 8
1 2 3 5 -4 6 7 8
1 2 3 5 4 6 7 8
2 -8 -4 5 6 7 3 -1
*/
