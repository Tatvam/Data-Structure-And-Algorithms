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
ll po(int l){
    int p = 1;
    while(l!=0){
        p=p*2;
        l--;
    }
    return p;
}
int main(){
    ll n;
    cin>>n;
    n++;
    ll cnt = 0;
    ll l = 0;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    while(n%2==0){
        cnt=po(l);
        l++;
        n=n/2;
    }

    if(cnt>0){
        cout<<cnt+(n-1)*cnt<<endl;
    }
    else{
        cout<<n<<endl;
    }
}