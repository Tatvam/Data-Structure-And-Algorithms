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
#define MOD 998244353
#define PI 3.1415926535897932384626433832795
#define MAX 100001
#define INF (1<<20)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define N 1009

ll dp[N]={0};
ll C[N][N];

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    re(i,n){
        cin>>a[i];
    }
    re(i,n){
        C[i][i]=1;C[i][0]=1;
        rep(j,1,i-1){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
    dp[n]=1;
    ren(i,n-1,0){
        if(a[i]<=0)continue;
        rep(j,i+a[i]+1,n){
            dp[i]+=(dp[j]*C[j-i-1][a[i]])%MOD;
            dp[i]%=MOD;
        }
    }
    ll ans = 0;
    re(i,n){
        ans+=dp[i]%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}