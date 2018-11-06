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
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    re(i,n){
        cin>>a[i];
    }
    int ans =INF;
    rep(d1,-1,1){
        rep(d2,-1,1){
            int b1 = a[0]+d1;
            int b2 = a[1]+d2;
            int diff = b2-b1;
            int flag = 0;
            int cnt =abs(d1)+abs(d2);
            rep(i,2,n-1){
                int diff1 = a[i]-b2;
                if(abs(diff1-diff)<=1){
                    if(diff1-diff == 0){
                        b2 = a[i];
                    }
                    else if(diff1-diff == 1){
                        b2 = a[i]-1;
                        cnt++;
                    }
                    else{
                        b2 = a[i]+1;
                        cnt++;
                    }
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag!=1){
                ans = min(ans,cnt);
            }
        }
    }
    if(ans == INF){
        cout<<-1<<endl;
    }
    else cout<<ans<<endl;
}