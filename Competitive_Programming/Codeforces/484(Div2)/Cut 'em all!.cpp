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
int ans = 0;
int dfs(vector<int> G[], int u, vector<int> &visit, int &ans)
{
    visit[u] = true;
    int cur = 0;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!visit[v])
        {
            int s = dfs(G, v, visit, ans);
              // cout<<s<<endl;
            if (s % 2 == 0 && G[u].size()!=1)
                ans++;
            else{
            //    cout<<cur<<endl;
                cur += s;
            }
        }
    }
    return (cur + 1);
}
int main(){
    int nodes;
    cin>>nodes;
    vector<int> G[nodes];
    vector<int> visit(nodes,false);
    re(i,nodes-1){
        int x,y;
        cin>>x>>y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    dfs(G,0,visit,ans);
    if(nodes%2!=0){
        cout<<-1<<endl;
    }
    else 
    cout<<ans<<endl;

}