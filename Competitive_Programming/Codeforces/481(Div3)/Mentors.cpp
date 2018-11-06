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
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > a(n);
    vector<int> b(n);
    vector<int> G[n+1];
    re(i,n){
        cin>>b[i];
        a[i]=(make_pair(b[i],i+1));
    }
    re(i,k){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> c(n,0);
    sort(a.begin(),a.end(),cmp);
    map<int,int> m;
    re(i,n){
        int x = i;
       // cout<<a[i].second<<endl;
        if(m.find(a[i].first)!=m.end()){
            x=x-m[a[i].first];
            m[a[i].first]++;
        }
        else{
            m[a[i].first]++;
        }
        re(j,G[a[i].second].size()){
            if(b[G[a[i].second][j]-1]<a[i].first){
                x--;
            }
        }
        c[a[i].second-1]=x;
    }
    re(i,n){
        cout<<c[i]<<" ";
    }
}
        