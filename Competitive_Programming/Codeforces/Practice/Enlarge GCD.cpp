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

#define size 15000001
int pri[size] = {0};
int ma[size] = {0};
int main(){
    turbo;
    int n;cin>>n;
    vector<int> a(n);
    re(i,n){
        cin>>a[i];
    }
    int gcd= a[0];
    rep(i,1,n-1){
        gcd = __gcd(gcd,a[i]);
    }
    int flag = 0;
    int mmx = 0;
    re(i,n){
        a[i]/=gcd;
        if(a[i]>1){
            flag = 1;
        }
        mmx=max(mmx,a[i]);
    }
       for(int i = 2;i*i<=mmx;i++){
        if(pri[i]==0){
        for(int j = i;j<=mmx;j+=i){
            pri[j]=i;
        }
        }
    }
     for (int i = 1; i <=mmx; ++i){
        if (!pri[i])
            pri[i] = i;
     }
    int mx = 0;
    if(flag == 0){
        cout<<-1<<endl;
    }else{
        re(i,n){
            int ele =a[i];
            while(ele>1){
                int di = pri[ele];
                
                ma[di]++;
                trace2(ele,di);
                mx = max(mx,ma[di]);
                while(ele%di==0){
                    ele/=di;
                }
            }
        }
        cout<<n-mx<<endl;
    }

}