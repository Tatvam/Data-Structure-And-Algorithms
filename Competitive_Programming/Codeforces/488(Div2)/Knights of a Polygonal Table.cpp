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
#define si(x)\tscanf("%d",&x)
#define sl(x)\tscanf("%lld",&x)
#define ss(s)\tscanf("%s",s)
#define pi(x)\tprintf("%d\n",x)
#define pl(x)\tprintf("%lld\n",x)
#define ps(s)\tprintf("%s\n",s)

bool cmp(pair<pll,ll> a,pair<pll,ll> b){
    return a.first.first<b.first.first;
}

struct compare
{
  bool operator()(const ll& l, const ll& r)
  {
      return l > r;
  }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<pair<ll,ll>,ll > > a(n);
    re(i,n){
        cin>>a[i].first.first;
        a[i].second = i;
    }
    re(i,n){
        cin>>a[i].first.second;
    }
      if(k == 0){
          re(i,n){
              cout<<a[i].first.second<<" ";
          }
          return 0;
    }
    sort(a.begin(),a.end(),cmp);
    vector<ll> ans(n);
  
    ans[a[0].second] = a[0].first.second;
    ll sum1 = a[0].first.second;
    rep(i,1,k){
        sum1+=a[i].first.second;
        ans[a[i].second] =sum1;
    }
    
    priority_queue<ll,vector<ll>, compare > p;
    ll sum = 0;
    re(i,k){
        p.push(a[i].first.second);
        sum+=a[i].first.second;
    }
    rep(i,k+1,n-1){
        if(a[i-1].first.second > p.top()){
            sum-=p.top();
            p.pop();
            p.push(a[i-1].first.second);
            sum+=a[i-1].first.second;
            ans[a[i].second] = sum+a[i].first.second;
        }
        else{
            ans[a[i].second] = sum+a[i].first.second;
        }
    }
    re(i,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}