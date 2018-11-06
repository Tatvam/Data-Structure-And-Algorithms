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
vector<string> s;
bool Is_In_Dict(string ch){
    re(i,s.size()){
        if(s[i].compare(ch)==0){
            return true;
        }
    }
    return false;
}
void solve(string st,string ans,int n){

    for(int i=1;i<=n;i++){
        string pref = st.substr(0,i);

        if(Is_In_Dict(pref)){
            if(i == n){
                ans+=pref;
                cout<<ans<<endl;
                return;
            }
            solve(st.substr(i,n-i),ans+pref+" ",n-i);
        }
    }

}
void wordbreak(string st){
    int n = st.size();
    solve(st,"",n);
}
int main(){
    int n;
    cin>>n;
    re(i,n){
        string t;
        cin>>t;
        s.push_back(t);
    }
    int q;
    cin>>q;
    re(i,q){
        string st;
        cin>>st;
        wordbreak(st);
    }
}