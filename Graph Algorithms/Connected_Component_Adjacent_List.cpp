/**************************************************
*    NAME:           TATVAM DADHEECH(td_1417)     *
*    INSTITUITION:   IIT BHUBANESWAR              *
**************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define vzero fill(v.begin(), v.end(), 0);
#define re(i, n) for(ll i = 0; i < n; i++)
#define test llt; cin >> t; while(t--)
#define rep(i,a,b) for(ll i = (a); i <= (b); i++)
#define ren(i,a,b) for(ll i = (a); i >= (b); i--)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
void dfs(ll s,ll &k,vector<bool> &visited,vector<ll> adj[])
{
	visited[s]=true;
				k++;
	re(i,adj[s].size())
	{
		if(visited[adj[s][i]]==false)
		{
			dfs(adj[s][i],k,visited,adj);
		}
	}
}
llmain()
{
	turbo;
	test
	{
	
		vector<ll> v;
	    ll connected=0;
		ll nodes;
		ll edges;
		cin>>nodes>>edges;
			vector<int> adj[nodes+1];
			vector<bool> visited(nodes+1);
		re(i,edges)
		{
			ll x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		fill(visited.begin(),visited.end(),false);
		ll k=0;
		ll j=0;
		if(edges==0){
			cout<<nodes<<endl;
			continue;
		}
		rep(i,1,nodes)
		{
			if(visited[i]==false)
		{
			dfs(i,k,visited,adj);
			v.push_back(k);
			k=0;
			j++;
			connected++;
		}
		}
		cout<<connected<<endl;
	}
}
