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
void dfs(vector<int> G[],int i,vector<bool> &visit1,stack<int> &s){
    visit1[i]=true;
    re(j,G[i].size()){
        if(visit1[G[i][j]]==false){
             dfs(G,G[i][j],visit1,s);
        }
    }
    s.push(i);
   // cout<<s.top()<<endl;
}
void dfs1(vector<int> H[],int i,vector<bool> &visit2){
    visit2[i]=true;
    re(j,H[i].size()){
        if(visit2[H[i][j]]==false){
             dfs1(H,H[i][j],visit2);
        }
    }
    cout<<"->"<<i;
}
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    vector<int> G[nodes];
    vector<int> H[nodes];
    vector<bool> visit1(nodes,false);
    vector<bool> visit2(nodes,false);
    re(i,edges){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        H[y].push_back(x);
    }
    stack<int> s;
    re(i,nodes){
        if(visit1[i]==false)
        dfs(G,i,visit1,s);
    }
    while(!s.empty()){
        if(visit2[s.top()]==false)
        dfs1(H,s.top(),visit2);
        s.pop();
        cout<<endl;
    }
}