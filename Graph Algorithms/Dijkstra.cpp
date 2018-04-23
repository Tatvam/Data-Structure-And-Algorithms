/**************************************************
*    NAME:           TATVAM DADHEECH(td_1417)     *
*    INSTITUITION:   IIT BHUBANESWAR              *
**************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define vzero fill(v.begin(), v.end(), 0);
#define re(i, n) for(int i = 0; i < n; i++)
#define test int t; cin >> t; while(t--)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define ren(i,a,b) for(int i = (a); i >= (b); i--)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1e9+7
#define PI 3.1415926535897932384626433832795
#define MAX 1000001
#define INF 1000000000
vector<pii> G[MAX];
int d[MAX];
void dijkstra(int s)
{
	 int u, v, i, c, w;
	 priority_queue< pii,vector<pii>,greater<pii> > q;
	 
	 q.push(make_pair(0,s));
	 d[s]=0;
	 while(!q.empty())
	 {
	 	c=q.top().first;
	 	u=q.top().second;
		 cout<<q.top().first<<" "<<q.top().second<<endl;
	 	q.pop();
	 	
	 	if(d[u]<c)
	 	{
		 continue;
	    }
	 	re(i,G[u].size())
	 	{
	 		v=G[u][i].first;
	 		w=G[u][i].second;
	 		if(d[u]+w<d[v])
	 		{
	 			d[v]=d[u]+w;
	 			q.push(make_pair(d[v],v));
		    }
		 }
	 }
	 
}
int main()
{
	int nodes,edges;
	cin>>nodes>>edges;
	re(i,edges)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	rep(i,0,nodes)
	{
		d[i]=INF;
	}
//	int s;
//	cin>>s;
	dijkstra(1);
	rep(i,2,nodes)
	{
		cout<<d[i]<<" ";
	}
}
