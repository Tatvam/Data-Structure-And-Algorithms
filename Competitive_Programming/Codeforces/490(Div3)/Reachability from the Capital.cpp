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
bool cmp(pii a,pii b){
    return a.first>b.first;
}
    vector<int> adj[5005];
 void dfs(int s,vector<int> &visited)
{
    visited[s]=1;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==0)
        dfs(adj[s][i],visited);
    }
}
 void dfs1(int s,vector<int> &visited,int j,vector<pair<int,int> > &m)
{
    visited[s]=1;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==0){
            m[j].first++;
            dfs1(adj[s][i],visited,j,m);
        }
    }
}

int main(){
    turbo;
    int nodes,edges,r;
    cin>>nodes>>edges>>r;
    r--;
    re(i,edges){
        int x,y;
        cin>>x>>y;
        adj[--x].push_back(--y);
    }
    vector<int> visited(5005,0);
    dfs(r,visited);
    vector<pair<int,int> > m;
    vector<int> v;

     re(i,nodes){
        if(visited[i]==0) 
        v.push_back(i);
    }
    int j = -1;
    re(i,v.size()){
        j++;
         m.push_back(make_pair(0,v[i]));
            dfs1(v[i],visited,j,m);
        re(j,v.size())
        visited[v[j]]=0;
    }
    sort(m.begin(),m.end(),cmp);
    int ans = 0;
   // re(i,m.size()){
     //   cout<<m[i].first<<" "<<m[i].second<<endl;
   // }
    re(i,m.size()){
        if(visited[m[i].second]==0){
            ans++;
            dfs(m[i].second,visited);
        }
    }
    cout<<ans<<endl;

}