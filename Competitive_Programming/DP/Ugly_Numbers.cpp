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
    vector<ll> ugly(501,0);
    ll mul_2 = 2;
    ll mul_3 = 3;
    ll mul_5 = 5;
    int i1 = 0,i2 = 0,i3 = 0;
    ugly[0]=1;
    rep(i,1,500){
        ll next_ugly = min(min(mul_2,mul_3),mul_5);
        ugly[i]=next_ugly;

        if(next_ugly == mul_2){
            i1 = i1+1;
            mul_2 = ugly[i1]*2;
        }
        if(next_ugly == mul_3){
            i2 = i2+1;
            mul_3 = ugly[i2]*3;
        }
        if(next_ugly == mul_5){
            i3 = i3+1;
            mul_5 = ugly[i3]*5;
        }

    }
    test{
        int n;
        cin>>n;
        cout<<ugly[n-1]<<endl;
    }
}