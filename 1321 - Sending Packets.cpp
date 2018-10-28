#include<bits/stdc++.h>
using namespace std;
#define mx 102
double dist[mx];
vector< pair<int, double> >adj[mx];
double bfs(int n)
{
	dist[1] = 1;
	priority_queue< pair<double, int> >pq;
	pq.push(make_pair(1,1));
	while(!pq.empty()){
		int u = pq.top().second;
		double pre = pq.top().first;
		pq.pop();
		if(u==n) return dist[n];
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i].first;
			if(dist[v] < adj[u][i].second*pre){
				dist[v] = adj[u][i].second*pre;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}
int main()
{
	int tc,n,m,s,p,a,b,k;
	scanf("%d",&tc);
	for(int cs=1; cs<=tc; cs++){
		scanf("%d%d%d%d",&n,&m,&s,&k);
		for(int i=1; i<=n; i++){
            adj[i].clear();
            dist[i] = 0;
		}
		while(m--){
			scanf("%d%d%d",&a,&b,&p);
			++a;++b;
			adj[a].push_back(make_pair(b,p/100.0));
			adj[b].push_back(make_pair(a,p/100.0));
		}
		double success = bfs(n);
		/// E = fail*(2k + E) + ok*(2k) for each KB data
		double fail = 1-success;
		double ans = ((success*2.0 + fail*2.0)/success)*k*s;
		printf("Case %d: %.5f\n", cs, ans);
	}
}
