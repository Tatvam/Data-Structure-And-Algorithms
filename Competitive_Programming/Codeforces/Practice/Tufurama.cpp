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
#define re(i, n) for(ll i = 0; i < n; i++)
#define test int t; cin >> t; while(t--)
#define rep(i,a,b) for(ll i = (a); i <= (b); i++)
#define ren(i,a,b) for(ll i = (a); i >= (b); i--)
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
#define N 200005

ll bit[N] = {0};
ll a[N]={0};
vector<ll> v[N];

void add(ll idx){
    while(idx<N){
        bit[idx]++;
        idx+=(idx&-idx);
    }
}

ll get(ll idx){
    int res=0;
    while(idx>0){
        res+=bit[idx];
        idx-=(idx&-idx);
    }
    return res;
}
int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    rep(i,1,n){
        cin>>a[i];
        v[min(a[i],n)].push_back(i);
    }
    ren(i,n,1){
        re(j,v[i].size()){
            add(v[i][j]);
        }
        ans+=get(min(i-1,a[i]));
    }
    cout<<ans<<endl;

}