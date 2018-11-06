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
bool cmp(pii a,pii b){
    return a.second<b.second;
}
int main(){
    vector<int> a(8);
    vector<int> b(8);
    re(i,8){
        cin>>a[i];
    }
    re(i,8){
        cin>>b[i];
    }
    int k = 0;
    vector<pii> line(4);  
     vector<pii> line1(4);
        for(int j = 0 ;j<7;j=j+2){
            if(a[j]-a[(j+2)%8]!=0){
                line[k] = make_pair(a[j+1],0);
                k++;
            }
            else{
                line[k] = make_pair(a[j],1);
                k++;
            }
        }
        k = 0;
         for(int j = 0 ;j<7;j=j+2){
            if(((b[j]-b[(j+2)%8])>=0 && (b[j+1]-b[(j+3)%8])>=0) || ((b[j]-b[(j+2)%8])<=0 && (b[j+1]-b[(j+3)%8])<=0)) {
                line1[k] = make_pair(b[j+1]-b[j],0);
                k++;
            }
            else{
                line1[k] = make_pair(b[j+1]+b[j],1);
                k++;
            }
        }
        sort(line.begin(),line.end(),cmp);
        sort(line1.begin(),line1.end(),cmp);
        bool ans = false;
             for(int j = 0; j<7 ; j=j+2){
                 int y = 0;
                 int z = 0;
                 if(((b[j+1]-line[0].first)<=0 && (b[j+1]-line[1].first)>=0)|| ((b[j+1]-line[0].first)>=0 && (b[j+1]-line[1].first)<=0)){
                     y = 1;
                }
                if(((b[j]-line[2].first)<=0 && (b[j]-line[3].first)>=0 )|| ((b[j]-line[2].first)>=0 && (b[j]-line[3].first)<=0)){
                     z = 1;
                }
                if(y == 1 && z == 1){
                    ans = true;
                    break;
                }
        }
             for(int j = 0; j<7 ; j=j+2){
                 int y = 0;
                 int z = 0;
                 if(((a[j+1]-a[j]-line1[0].first)<=0 && (a[j+1]-a[j]-line1[1].first)>=0)|| ((a[j+1]-a[j]-line1[0].first)>=0 && (a[j+1]-a[j]-line1[1].first)<=0)){
                     y = 1;
                }
                if(((a[j]+a[j+1]-line1[2].first)<=0 && (a[j]+a[j+1]-line1[3].first)>=0 )|| ((a[j]+a[j+1]-line1[2].first)>=0 && (a[j]+a[j+1]-line1[3].first)<=0)){
                     z = 1;
                }
                if(y == 1 && z == 1){
                    ans = true;
                    break;
                }
        }
        if(ans)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

}