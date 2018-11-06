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
#define si(x)\tscanf("%d",&x)
#define sl(x)\tscanf("%lld",&x)
#define ss(s)\tscanf("%s",s)
#define pi(x)\tprintf("%d\n",x)
#define pl(x)\tprintf("%lld\n",x)
#define ps(s)\tprintf("%s\n",s)
// DFS
/*
    vector<int> adj[100000];
    vector<bool> visited(100000);
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
/*
    void bfs(int s,vector<int> &level)
{
    queue<int> q;
    q.push(s);
    level[s]=1;
    visited[s]=true;
    while(!q.empty())
     {
       int p=q.front();
       q.pop();
       for(int i=0;i<adj[p].size();i++)
        {
          if(visited[adj[p][i]]==false)
         {

              q.push(adj[p][i]);
              level[adj[p][i]]=level[p]+1;
              visited[adj[p][i]]=true;
          }
        }
      }
}
*/
// Binary Search
/*
int Binarysearch(vector<int> a,int n,int key)
{
    int low,high,mid;
    low=0;
    high=n-1;
    
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
            return(mid);
        else
            if(key>a[mid])
                low=mid+1;
            else
                high=mid-1;
    }
    
    return -1;
}
*/
// DSU

struct Node{
    int parent;
    int rank;
};

Node DSU[1001][1001];

int root(int x,int c){
    while(DSU[c][x].parent != x){
        DSU[c][x].parent = DSU[c][DSU[c][x].parent].parent;
        x = DSU[c][x].parent;
    }
    return x;
}
void Union(){
    int a,b,c;
            cin>>a>>b>>c;
            int x = root(a,c);
            int y = root(b,c);
            if(x == y)return;
            else if(DSU[c][x].rank > DSU[c][y].rank){
                DSU[c][y].parent = x;
            }
            else if(DSU[c][x].rank < DSU[c][y].rank){
                DSU[c][x].parent = y;
            }
            else{
                DSU[c][x].parent = y;
                DSU[c][y].rank++;
            }
}
void makeset(int i,int j){
    DSU[j][i].parent = i;
    DSU[j][i].rank = 0;
}
bool issame(int x,int y,int c){
    if(root(x,c)==root(y,c)){return true;}
    return false;
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    re(j,101){
        re(i,101){
            makeset(i,j);
        }
    }
    re(i,edges){
        Union();
    }
    int q;
    cin>>q;
    re(i,q){
        int x,y;
        cin>>x>>y;
        int cnt = 0;
        re(j,101){
            if(issame(x,y,j))
            cnt++;
        }
        cout<<cnt<<endl;
    }
}