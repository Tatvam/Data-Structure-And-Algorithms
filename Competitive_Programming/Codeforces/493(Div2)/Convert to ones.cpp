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

int main(){
    string s;
       ll n,x,y;
       cin>>n>>x>>y;
    cin>>s;
    ll cnt = 0;
    ll seg =0;
    ll tot = 0;
    ll flag = 0;
    re(i,s.size()){
        if(s[i]=='0'){
            flag = 1;
            cnt++;
            tot++;
        }
        else if(flag == 1 && s[i]=='1'){
            seg++;
            flag = 0;
        }
    }
    if(flag == 1){
        seg++;
    }
    ll ans;
    ll j = 1;
    ans = seg*y;
    seg--;
   while(seg>0){
        ans = min(ans,j*x+(seg)*y);
        j++;
        seg--;
    }
    cout<<ans<<endl;
}