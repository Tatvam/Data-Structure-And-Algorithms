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
#define MAX 1000001
#define INF (1<<20)

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
int n,m,k,x3,x2,y3,y2;
int visited[1005][1005]={{false}};
int dist[1005][1005];
char adj[1005][1005];

    
void bfs()
{
    queue< pair<int,int> > q;
    q.push(make_pair(x3,y3));
    dist[x3][y3]=0;
    visited[x3][y3]=true;
    while(!q.empty())
     {
       int x=q.front().first;
       int y =q.front().second;
       visited[x][y]=true; 
       q.pop();
       int br = 0;
       for(int i=x+1; i<n && br<k && dist[i][y]>=dist[x][y]+1 && adj[i][y]=='.';i++){
           if(!visited[i][y]){
               dist[i][y]=dist[x][y]+1;
               q.push(make_pair(i,y));
               visited[i][y]=true;
               
           }
           br++;
       }
       br = 0;
        for(int i=x-1; i>=0 && br<k && dist[i][y]>=dist[x][y]+1  && adj[i][y]=='.';i--){
           if(!visited[i][y]){
               dist[i][y]=dist[x][y]+1;
               q.push(make_pair(i,y));
                 visited[i][y]=true;
               
           }
           br++;
       }
       br = 0;
        for(int i=y+1; i<m && br<k && dist[x][i]>=dist[x][y]+1 && adj[x][i]=='.';i++){
           if(!visited[x][i]){
               dist[x][i]=dist[x][y]+1;
               q.push(make_pair(x,i));
               visited[x][i]=true;
               
           }
           br++;
       }
       br = 0;
        for(int i=y-1; i>=0 && br<k && dist[x][i]>=dist[x][y]+1 &&adj[x][i]=='.' ;i--){
           if(!visited[x][i]){
               dist[x][i]=dist[x][y]+1;
               q.push(make_pair(x,i));
               visited[x][i]=true;
               
           }
           br++;
       }
       br = 0;
      }
}

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
/*
struct Node{
    int parent;
    int rank;
};

Node DSU[1001];
void union(){
    int a,b;
            cin>>a>>b;
            int x = root(a);
            int y = root(b);
            if(x == y)continue;
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

int root(int x){
    while(DSU[x].parent != x){
        DSU[x].parent = DSU[DSU[x].parent].parent;
        x = DSU[x].parent;
    }
    return x;
}
bool issame(int x,int y){
    if(root(x)==root(y)){return true;}
    return false;
}
*/
int main(){
    cin>>n>>m>>k;
    re(i,n){
        re(j,m){
            cin>>adj[i][j];
        }
    }
    cin>>x3>>y3>>x2>>y2;
    --x3;--y3;--x2;--y2;
     memset(dist,MAX,sizeof dist);
    bfs();
    if(dist[x2][y2]<MAX){
        cout<<dist[x2][y2];
    }
    else{
        cout<<-1;
    }
}