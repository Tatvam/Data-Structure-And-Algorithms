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
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define MAX 100001
#define INF (1<<20)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
const int N = 5e5+5;
vector<bool> visit(N,false);
vector<int> depth(N,0);
vector<int> adj[N];
vector<int> b(N);
void dfs(int u){
    visit[u]=true;
    re(j,adj[u].size()){
        int v = adj[u][j];
        if(visit[v]==false){
        depth[v]=depth[u]+1;
        dfs(v);
        }
    }
}
int main(){
    //int t;
    test{
    int nodes;
    cin>>nodes;
    	for(int i = 0; i < nodes; ++i)
		adj[i].clear();


        depth[0]=0;
    for(int i=0;i<nodes-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    re(i,nodes){
        cin>>b[i];
    }
       fill(visit.begin(),visit.end(),false);
    dfs(0);
    ll c[2][2] = { };
    re(i,nodes){
        int a = __builtin_popcount(b[i]);
        int b = depth[i]%2;
        c[a%2][b%2]++;
    }
    ll ans = 0;
    ans+=c[0][1]*c[1][1];
    ans+=c[0][1]*c[0][0];
    ans+=c[1][0]*c[0][0];
    ans+=c[1][0]*c[1][1];
    cout<<ans<<endl;
    }
}