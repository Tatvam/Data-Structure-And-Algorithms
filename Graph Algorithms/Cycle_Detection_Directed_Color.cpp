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
enum color {White,Grey,Black};
bool isCyclic(vector<int> G[],int nodes,int edges,vector<color> &col,int i){
    col[i]=Grey;
    re(j,G[i].size()){
        if(col[G[i][j]]==Grey){
            return true;
        }
        if(col[G[i][j]] == White && isCyclic(G,nodes,edges,col,G[i][j])){
            return true;
        }
    }
    col[i]=Black;
    return false;
}
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    vector<int> G[nodes];
    re(i,edges){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    vector<color> col(nodes);
    re(i,nodes){
        col[i]=White;
    }
    re(i,nodes){
        if(col[i]==White){
            bool cy = isCyclic(G,nodes,edges,col,i);
            if(cy == true){
                cout<<"cyclic"<<endl;
            }
            else{
                cout<<"Not cyclic"<<endl;
            }
        }
    }
}