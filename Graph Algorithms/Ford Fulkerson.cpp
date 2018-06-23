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

    int adj[10000][10000] = {{0}};
    int graph[10000][10000] = {{0}};
    int v;
/*
 dfs(int s,vector<bool> &visited)
{
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        dfs(adj[s][i],visited);
    }
}
*/

// BFS
bool bfs(int s,int t,int parent[])
{
      bool visited[v];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty())
     {
       int p=q.front();
       q.pop();
       for(int i=0;i<v;i++)
        {
          if(visited[v]==false && graph[p][i]>0)
         {

              q.push(adj[p][i]);
              parent[i]=p;
              visited[v]=true;
          }
        }
      }
      
      if(visited[t]) return true;
}



int fordfulkerson(int s,int t){

    int parent[v];
    int max_flow = 0;

    re(i,v){
        re(j,v){
            graph[i][j]=adj[i][j];
        }
    }
    
    while(bfs(s,t,parent)){

        int flow = MAX;

        for(int i = t;i!=s;i = parent[i]){
            flow = min(flow,graph[parent[i]][i]);
        }
         for (int i=t; i!= s; i=parent[i]){
            graph[parent[i]][v] -= flow;
            graph[v][parent[i]] += flow;
        }

        max_flow+=flow;
    }
    return max_flow;
}

int main(){
    int nodes,edges,weight;
    cin>>nodes>>edges>>weight;
    re(i,edges){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x][y]=w;
    }
    v = nodes;
    int s,t;
    cin>>s>>t;
    cout<<fordfulkerson(s,t);

}