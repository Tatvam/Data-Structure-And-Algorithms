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

vector<int> dp(4004);

int cut_segment(int n,int a[]){
    if(n<0){
        return INT_MIN;
    }
    if(n == 0){return 0;}

    if(dp[n]==-1){
     //   cout<<n<<" " << dp[n]<<endl;
    for(int i = 0;i<3;i++){
        if(n-a[i]>=0)
        dp[n] = max(dp[n],1+cut_segment(n-a[i],a));
         if (dp[n] == -1) dp[n] = INT_MIN;
       // cout<<dp[n]<<endl;
    }
    
}
return dp[n];
}

int main(){
    test{
        int n;
        cin>>n;
        int x,y,z;
        cin>>x>>y>>z;
        fill(dp.begin(),dp.end(),-1);
        int a[3];
        a[0]=x;a[1]=y;a[2]=z;
       cout<< cut_segment(n,a) <<endl;

    }
}