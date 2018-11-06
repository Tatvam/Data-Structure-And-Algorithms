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
#define si(x)tscanf("%d",&x)
#define sl(x)tscanf("%lld",&x)
#define ss(s)tscanf("%s",s)
#define pi(x)tprintf("%d\n",x)
#define pl(x)tprintf("%lld\n",x)
#define ps(s)tprintf("%s\n",s)
int a[1000005];
const ll INF =1e18;
bool pos[1000005];
int prefR[1000005];
int n,m,k;    ll ans = INF;ll y =INF;

ll cnt (int l){
    int r = 0; int i = -1; int ans = 0;
    while(r<n){
        if(prefR[r]<=i)
        return INF;
        i = prefR[r];
        r = prefR[r]+l;
        ans++;
    }
        return ans;
    }

int main(){
    turbo;
    cin>>n>>m>>k;
    re(i,n){
        pos[i]=false;
    }
    re(i,m){
        int t;cin>>t;
        pos[t]=true;
    }
    re(i,k){
        cin>>a[i];
    }
    re(i,n){
        if(!pos[i]){
            prefR[i]=i;
        }
        else if(i>0){
            prefR[i] = prefR[i-1];
        }
        else{
            prefR[i]=-1;
        }
    }
    re(i,k){
         y = cnt(i+1);
        if(y!=INF){
            ans = min(ans,a[i]*y);
        }
    }
    if(ans == INF){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}