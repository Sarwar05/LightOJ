#include<bits/stdc++.h>
using namespace std;
#define mx 102
#define inf 1000000009
int price[mx];
struct Edge
{
	int v;
	int w;
	Edge(int _v, int _w)
	{
		v = _v;
		w = _w;
	}
};
struct Node
{
	int at;
	int curr;
	int cost;
	Node(int _at, int _curr, int _cost)
	{
		at = _at;
		curr = _curr;
		cost = _cost;
	}
	bool operator<(const Node& ob) const
	{
		return cost>ob.cost;
	}
};
vector<Edge> edge[mx];
int dist[mx][mx];
int solve(int s, int t, int cap)
{
	int ret = 0;
	if(s==t) return 0;
	priority_queue<Node> pq;
	pq.push(Node(s,0,0));
	while(!pq.empty()){
		int at = pq.top().at;
		int curr = pq.top().curr;
		int cost = pq.top().cost;
		pq.pop();
		if(at==t) return cost;
		for(int i=0; i<edge[at].size(); i++){
			int v = edge[at][i].v;
			int w = edge[at][i].w;
			if(curr>=w){
				if(dist[v][curr-w] > cost){
					dist[v][curr-w] = cost;
					pq.push(Node(v, curr-w, cost));
				}
			}
		}
		if(curr<cap){
			if(cost+price[at] < dist[at][curr+1]){
				pq.push(Node(at, curr+1, cost+price[at]));
				dist[at][curr+1] = cost+price[at];
			}
		}
	}
	return -1;
}
int main()
{
	int tc,cs=1,n,m,a,b,c,q,s,t;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++){
			scanf("%d",&price[i]);
			edge[i].clear();
		}
		while(m--){
			scanf("%d%d%d",&a,&b,&c);
			++a;++b;
			edge[a].push_back(Edge(b,c));
			edge[b].push_back(Edge(a,c));
		}
		printf("Case %d:\n",cs++);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d%d",&c,&s,&t);
			++s; ++t;
			for(int i=1; i<=n; i++)
				for(int j=0; j<=c; j++)
					dist[i][j] = inf;
			int ans = solve(s,t,c);
			if(ans<0) printf("impossible\n");
			else printf("%d\n",ans);
		}
	}
}
