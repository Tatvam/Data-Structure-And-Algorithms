/**************************************************
*    NAME:           TATVAM DADHEECH(td_1417)     *
*    INSTITUITION:   IIT BHUBANESWAR              *
**************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi; 
typedef vector<long long> vl;
typedef vector<pair<int,int> > vii;
typedef vector<pair<ll,ll> > vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef priority_queue<pii,vii,greater<pii> > pq;
#define mp make_pair
#define re(i, n) for(ll i = 0; i < n; i++)
#define test int t; cin >> t; while(t--)
#define rep(i,a,b) for(ll i = (a); i <= (b); i++)
#define ren(i,a,b) for(ll i = (a); i >= (b); i--)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 0x3f3f3f3f
#define LLINF 1000111000111000111LL
#define endl "\n"
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

int main(){
    int n,k,d;
    cin>>n>>k>>d;
    int dp[n+1][2] = {{0}};
   // dp[1][0]=1;
    dp[0][0]=1;
    rep(i,1,n){
        rep(j,1,k){
            if(i-j<0){
                break;
            }
            if(j<d){
                dp[i][0]=(dp[i][0]+dp[i-j][0])%MOD;
                dp[i][1]=(dp[i][1]+dp[i-j][1])%MOD;
            }else{
                dp[i][1]=(dp[i][1]+dp[i-j][0])%MOD;
                dp[i][1]=(dp[i][1]+dp[i-j][1])%MOD;
            }
           // trace4(dp[i][0],dp[i][1],i,j);
        }
    }
    cout<<dp[n][1]<<endl;
    
}