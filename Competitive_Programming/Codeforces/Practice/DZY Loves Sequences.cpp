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
    int n;
    cin>>n;
    vi a(n);
    vi l(n);
    vi r(n);
    re(i,n){
        cin>>a[i];
    }
    l[0]=1;
    r[n-1]=1;
    rep(i,1,n-1){
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }else{
            l[i]=1;
        }
    }
    ren(i,n-2,0){
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }else{
            r[i]=1;
        }
    }
    int dp[n-1]={0};
    if(a[0]>=a[1]){
        dp[0]=1+r[1];
    }else{
        dp[0]=r[0];
    }
    rep(i,1,n-1){
            if(i == n-1){
                dp[n-1]=l[i-1]+1;
            }
            else if(a[i+1]-a[i-1]>1){
                dp[i]=l[i-1]+r[i+1]+1;
        }
        else{
            dp[i]=max(l[i-1]+1,r[i+1]+1);
        }
         // trace3(dp[i],l[i],r[i]);
    }
 
    int ans = 0;
    re(i,n){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
}