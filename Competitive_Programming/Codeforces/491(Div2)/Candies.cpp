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
bool check(ll n,ll mid,ll m){
    ll num = 0;
    ll j = 0;
    while(n>0){
        if(j%2==0){
            if(n-mid<=0){
                num+=n;
                n=0;
            }else{
          n=n-mid;
          num+=mid;
            }
        } 
        else {
            if(n<=9){
                num+=n;
                n=0;
            }else{
                n=n-n/10;
            }
        }
        j++;
    }
    if(num>=m) 
    return true;
    else 
    return false;
}

ll Binarysearch(ll n,ll m)
{
    ll low,high,mid;
    low=1;
    high=n;
    ll ans = 1000000000000000000; 
    while(low<=high)
    {
        mid=(low+high)/2;
        //cout<<mid<<endl;
        if(check(n,mid,m) == true){
            ans = min(ans,mid);
            high = mid-1;
        }   
        else{
               low = mid+1;
        }
         
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    ll m = n/2;
    if(n%2!=0){
        m++;
    }
    cout<<Binarysearch(n,m)<<endl;

}