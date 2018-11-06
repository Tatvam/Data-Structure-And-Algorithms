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
#define INF (1<<20)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define MAX 500005
ll dd[MAX];
ll dp[MAX];


int main(){
    int n,k,d;
    cin>>n>>k>>d;
    vector<ll> a(n+1);
    rep(i,1,n){
        cin>>a[i];
        dd[i]=0;
        dp[i]=0;
    }
     sort(a.begin(),a.end());
    for(int i=k;i<=n;i++){
        ll x = dd[i-k];
        if(a[i]-a[x+1]<=d){
            dp[i]=1;
            dd[i]=i;
        }
        else{
            dd[i]=dd[i-1];
        }
    }
    if(dp[n]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}