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
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
// DFS

    vector<int> adj[100000];
    vector<bool> visited(100000);
    int t = 0;
    vector<int> dep(100000,0);
 void dfs(int s)
{
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false){
        dfs(adj[s][i]);
    }

}
    dep[t++] = s;
}


int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    re(i,edges){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    re(i,nodes){
        if(!visited[i]){
            dfs(i);
        }
    }
    ren(i,nodes-1,0){
        cout<<dep[i]<<" ";
    }
    cout<<endl;
}