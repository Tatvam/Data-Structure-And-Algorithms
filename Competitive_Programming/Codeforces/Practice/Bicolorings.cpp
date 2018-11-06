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
#define re(i, n) for(int i = 0; i < n; i++)
#define test int t; cin >> t; while(t--)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define ren(i,a,b) for(int i = (a); i >= (b); i--)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD  998244353
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
/* 1.Take care of long long. 
   2.DP Approach - First start with the initial case n == 1 or n == 2 
               find possible answer and with the help of them calculate 
               for further value of n. 
   3.Think of changing number into bits.
*/
ll dp[1001][2001][4];
int main(){
    int n,k;
    cin>>n>>k;
    
    re(i,1001){
        re(j,2002){
            re(l,4){
                dp[i][j][l]=0;
            }
        }
    }
    dp[0][1][0]=1;
    dp[0][2][1]=1;
    dp[0][2][2]=1;
    dp[0][1][3]=1;

    for(int i = 1;i<n;i++){
        for(int j = 1;j<=k;j++){
            dp[i][j][0] = (dp[i-1][j][0]+dp[i-1][j-1][3]+dp[i-1][j][1]+dp[i-1][j][2])%MOD;
            dp[i][j][1] = (dp[i-1][j-1][0]+dp[i-1][j-1][3]+dp[i-1][j][1]+((j-2)>0?dp[i-1][j-2][2]:0))%MOD;
            dp[i][j][2] = (dp[i-1][j-1][0]+dp[i-1][j-1][3]+((j-2)>0?dp[i-1][j-2][1] : 0)+dp[i-1][j][2])%MOD;
            dp[i][j][3] = (dp[i-1][j-1][0]+dp[i-1][j][3]+dp[i-1][j][1]+dp[i-1][j][2])%MOD;
        }
    }
    int ans = 0;
    re(i,4){
        ans+=(dp[n-1][k][i])%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;

}