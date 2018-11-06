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
/* 1.Take care of long long. 
   2.DP Approach - First start with the initaial case n == 1 or n == 2 
               find possible answer and with the help of them calculate 
               for further value of n. 
   3.Think of changing number into bits.
*/
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    re(i,n){
        cin>>a[i];
    }
    re(i,m){
        cin>>b[i];
    }
    ll x;
    cin>>x;
    ll mn[n+1];
    re(i,n+1){
        mn[i]=INF;
    }
    re(i,n){
        ll sum = 0;
        rep(j,i,n-1){
            sum+=a[j];
            mn[j-i+1]=min(mn[j-i+1],sum);
           // trace2(mn[j-i+1],j-i+1);
        }
    }
    int ans = 0;
    rep(i,1,n){
        int k = 0;
        ll sum = 0;
        re(j,m){
            while(k<m && (sum+b[k])*mn[i]<=x){
                sum+=b[k];
                k++;
            }
          //  trace4(i,j,k,mn[i]);
            ans = max(ans,(k-j)*(i));
            sum-=b[j];

        }
    }
    cout<<ans<<endl;

}