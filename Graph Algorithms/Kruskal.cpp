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
#define re(i, n) for(int i = 0; i < n; i++)
#define test int t; cin >> t; while(t--)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define ren(i,a,b) for(int i = (a); i >= (b); i--)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1e9+7
#define PI 3.1415926535897932384626433832795
const int mx=1e4 + 5;
int id[mx];
int edges,nodes;
int root(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
void Union(int x,int y)
{
	int a=root(x);
	int b=root(y);
	id[a]=id[b];
}
ll kruskal(pair<long long,pair<int,int> > p[])
{
	int mn=0;
	re(i,edges)
	{
		int x=p[i].second.first;
		int y=p[i].second.second;
		if(root(x)!=root(y))
		{
			mn+=p[i].first;
			Union(x,y);
		}
		
	}
	return mn;
}
int main()
{
	
	cin>>nodes>>edges;
	pair<long long,pair<int,int> > p[edges+1];
	re(i,edges)
	{
		int x,y;\
		ll weight;
		cin>>x>>y>>weight;
		p[i]=make_pair(weight,make_pair(x,y));
	}
	sort(p,p+edges);
	re(i,nodes)
	{
		id[i]=i;
	}
	ll minimumcost=kruskal(p);
	cout<<minimumcost;
}
