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
#define MOD 1e9+7
#define PI 3.1415926535897932384626433832795
#define MAX 100001
#define INF (1<<20)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
struct Compare {
    constexpr bool operator()(pair<int, int> const & a,
                              pair<int, int> const & b) const noexcept
    { return a.first < b.first ; }
};
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > a(n);
    re(i,n){
        int t;
        cin>>t;
        a[i]=make_pair(t,i);
    }
    string s;
    cin>>s;
    sort(a.begin(),a.end(),cmp);
    vector<int> c(2*n);
    priority_queue<pair<int,int>,std::vector<pair<int,int> >,Compare> p;
    int j=0;
    re(i,2*n){
        if(s[i]=='0'){
            c[i]=a[j].second+1;
            p.push(make_pair(a[j].first,a[j].second));
            j++;     
        }
        else{
            c[i]=p.top().second+1;
            p.pop();
        }
    }
    re(i,2*n){
        cout<<c[i]<<" ";
    }
    cout<<endl;
}