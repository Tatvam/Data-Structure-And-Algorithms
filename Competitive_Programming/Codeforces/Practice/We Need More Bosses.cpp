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
#define N 300005
vector<int> adj[N];
vector<int> disc(N);
vector<int> low(N);
vector<bool> visited(N,false);
vector<int> parent(N,-1);
vector<int> bt[N];
vector<pii> bridges;
int rt = 0;
int tim = 0;

struct Node{
    int parent;
    int rank;
};

Node DSU[N];

int root(int x){
    while(DSU[x].parent != x){
        DSU[x].parent = DSU[DSU[x].parent].parent;
        x = DSU[x].parent;
    }
    return x;
}

void Union(int a,int b){
            int x = root(a);
            int y = root(b);
            if(x == y)
            return ;
            else if(DSU[x].rank > DSU[y].rank){
                DSU[y].parent = x;
            }
            else if(DSU[x].rank < DSU[y].rank){
                DSU[x].parent = y;
            }
            else{
                DSU[x].parent = y;
                DSU[y].rank++;
            }
}
void makeset(int i){
    DSU[i].parent = i;
    DSU[i].rank = 0;
}



void bridge(int u)
{
    disc[u]=low[u]=tim++;
    visited[u]=true;

    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(visited[v]==false){
            parent[v]=u;

            bridge(v);

            low[u]=min(low[u],low[v]);

            if(low[v]>disc[u]){
                bridges.push_back(make_pair(u,v));
            }
            else{
                Union(u,v);
            }
        }else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }

        
    }
}
void build(){
  //  cout<<bridges.size()<<endl;
    re(i,bridges.size()){
        int x = root(bridges[i].first);
        int y = root(bridges[i].second);
        rt = x;
     //   cout<<endl;
       // cout<<x<<" "<<y<<endl;
        bt[x].push_back(y);
        bt[y].push_back(x);
    }
}

// BFS
int le = 0;
int li = 0;
pii bfs(int s,vector<bool> visit,vector<int> level)
{
    queue<int> q;
    q.push(s);
    level[s]=0;
    visit[s]=true;
    while(!q.empty())
     {
       int p=q.front();
       q.pop();
       for(int i=0;i<bt[p].size();i++)
        {
          if(visit[bt[p][i]]==false)
         {

              q.push(bt[p][i]);
              level[bt[p][i]]=level[p]+1;
              if(level[bt[p][i]]>=le){
                  le = level[bt[p][i]];
                  li = bt[p][i];
              }
              visit[bt[p][i]]=true;
          }
        }
      }
      return make_pair(li,le);
}





int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    re(i,edges){
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    re(i,nodes){
        makeset(i);
    }

    bridge(0);
    build();
    vector<bool> visit(nodes,false);
    vector<int> level(nodes,0);
    pii ft = bfs(rt,visit,level);
  //  cout<<ft.first<<" "<<ft.second<<endl;
    pii sd = bfs(ft.first,visit,level);

    cout<<sd.second<<endl;





}