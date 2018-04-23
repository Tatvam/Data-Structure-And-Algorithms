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
#define MAX 100001
#define INF (1<<20)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
vector<int> v[200001];
vector<int> dis(200001);
int nodes,edges;
int flag = 0;
void bellmanford()
{
	dis[0]=0;
	for(int i=1;i<nodes;i++)
	{
        for(int j = 0;j<edges;j++){
			if(dis[v[j][0]]+v[j][2]<dis[v[j][1]] && dis[v[j][0]]!=MOD)
			{
				dis[v[j][1]]=dis[v[j][0]]+v[j][2];
			}
		}
	}
	for (int i = 0; i < edges; i++)
    {
        if (dis[v[i][0]]+v[i][2]<dis[v[i][1]] && dis[v[i][0]]!=MOD){
            printf("Graph contains negative weight cycle");
            flag = 1;}
    }
}
int main()
{
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		int from,next,weight;
		cin>>from>>next>>weight;
		v[i].push_back(from);
		v[i].push_back(next);
		v[i].push_back(weight);
	}
	re(i,nodes)
	{
		dis[i]=MOD;
	}
    bellmanford();
    re(i,nodes)
    {
    	cout<<dis[i]<<" ";
	}
	cout<<endl;
}

