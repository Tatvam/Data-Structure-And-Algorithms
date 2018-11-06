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

//map<int>
 void dfs(ll i,vector<ll> a,vector<ll> &ans)
{
    vector<ll>::iterator it;
    it = find(a.begin(), a.end(),i);
    if(it!=a.end()){
        ans.push_back(i);
    }else{
        return ;
    }
      if(a.size() == ans.size())
    return ;
    if(i%3==0){
        dfs(i/3,a,ans);
    }
    dfs(i*2,a,ans);
}

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    re(i,n){
        cin>>a[i];
    }
    re(i,n){
        vector<ll> ans;
        dfs(a[i],a,ans);
     //   cout<<ans.size()<<endl;
        if(ans.size() == n){
            re(i,ans.size()){
                cout<<ans[i]<<" ";
            }
            return 0;
        }
    }
}