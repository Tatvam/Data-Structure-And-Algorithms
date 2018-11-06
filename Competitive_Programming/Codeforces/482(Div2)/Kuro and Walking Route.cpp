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
#define MOD 1e9+7
#define PI 3.1415926535897932384626433832795
#define MAX 100001
#define INF (1<<20)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
ll cnt = 0;
ll cnt1 = 0;
ll flag = 0;
void dfs(vector<ll> G[],ll x,ll y,vector<ll> &visit,ll i){
    visit[i]=1;
    if((visit[y]==0 || visit[y]==2) && i!=y){
        cnt++;
    }
    re(j,G[i].size()){
        if(visit[G[i][j]]==0){
            dfs(G,x,y,visit,G[i][j]);
        }
    }
    visit[i]=2;
}
  void dfs1(vector<ll> G[],ll x,ll y,vector<ll> &visit,ll i){
    visit[i]=1;
    if((visit[x]==0 || visit[x]==2) && i!=x){
        cnt1++;
    }
    re(j,G[i].size()){
        if(visit[G[i][j]]==0){
            dfs1(G,x,y,visit,G[i][j]);
        }
    }
    visit[i]=2;
}  
int main(){
    ll nodes,x,y;
    cin>>nodes>>x>>y;
    vector<ll> G[nodes+1];
    vector<ll> visit(nodes+1,0);
    re(i,nodes-1){
        int a,b;
        cin>>a>>b;;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(G,x,y,visit,x);
    fill(visit.begin(),visit.end(),0);
    dfs1(G,x,y,visit,y);
  //  cout<<cnt<<" "<<cnt1<<endl;
    cnt = nodes-cnt;
    cnt1 = nodes-cnt1;
    cout<<nodes*(nodes-1)-cnt*cnt1<<endl;
}