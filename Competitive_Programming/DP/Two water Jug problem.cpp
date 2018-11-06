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
int twojug(int i,int j,int n,int m,int k){
    if(i<0 || j<0 || i>n || j>m){
        return INT_MAX;
    }
    //cout<<"hi"<<endl;
    if(i+j>k){
        return INT_MAX;
    }
    if(i+j==k){
        cout<<k<<endl;
        return 0;
    }
    if(i == n && j == m){
        return INT_MAX;
    }
    if(i == 0 && j == 0){
        return 1+ min(twojug(i,m,n,m,k),twojug(n,j,n,m,k));
    }else{
        if(i == 0){
            return 1 + min(twojug(j<n ? j:n,j<n ? 0:n-j,n,m,k),twojug(n,j,n,m,k));
        }
        if(j == 0){
              return 1 + min(twojug(0,i,n,m,k),twojug(i,m,n,m,k));
        }
        if(i!=0 && j!=0){
            return 1+min(min(twojug(0,j,n,m,k),twojug(j<n-i?i+j:n,j<n-i?0:i+j-n,n,m,k)),min(twojug(i,0,n,m,k),twojug(i<m-j ? 0:i+j-m,i<m-j?j+i:m,n,m,k)));
        }
    }
    return 0;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
   cout<<twojug(0,0,n,m,k)<<endl;
    }