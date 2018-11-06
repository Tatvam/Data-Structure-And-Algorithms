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
bitset<MAX> dp;
bitset<MAX> ans;
vector<int> a[MAX];

void seg_tree(int i,int ss,int se,int l,int r,int x){
    if(se<l || ss>r){
        return ;
    }
   // cout<<ss<<" "<<se<<" "<<l<<" "<<r<<endl;
    if(ss>=l && se<=r){
        a[i].push_back(x);
    }else{
        int mid = (ss+se)/2;
        seg_tree(2*i,ss,mid,l,r,x);
        seg_tree(2*i+1,mid+1,se,l,r,x);
    }
}

void dfs(int i,int ss,int se,bitset<MAX> dp){
    
     re(j,a[i].size()){
           // cout<<a[i][j]<<endl;
            dp|=dp<<a[i][j];
        }

    if(ss==se){
        ans|=dp;
    }else{
    int mid = (ss+se)/2;
    dfs(2*i,ss,mid,dp);
    dfs(2*i+1,mid+1,se,dp);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    re(i,q){
        int l,r,x;
        cin>>l>>r>>x;
        seg_tree(1,1,n,l,r,x);
    }
   // cout<<a[6].size()<<endl;
    dp.set(0);
    dfs(1,1,n,dp);
    int an=0;
    rep(i,1,n){
        if(ans[i])
        an++;
    }
    cout<<an<<endl;
    rep(i,1,n){
        if(ans[i])
        cout<<i<<" ";
    }
    //cout<<ans<<endl;
}