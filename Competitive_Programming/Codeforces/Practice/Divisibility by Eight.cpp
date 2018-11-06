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
string ans = "";
bool check(string t){
    int m = t.size();
    if(m==0){
        return 0;
    }else if(m == 1){
        int s = (int)(t[0]-'0');
        if(s%8 == 0){
            return 1;
        }
    }else if(m == 2){
          int s = (int)(t[0]-'0')*10 + int(t[1]-'0');
        if(s%8 == 0){
            return 1;
        }
    }else{
         int s = (int)(t[m-3]-'0')*100 + int(t[m-2]-'0')*10 + int(t[m-1]-'0');
        if(s%8 == 0){
            return 1;
        }
    }
    return 0;
}
void func(string s,int n,int i,string t){
  //  trace1(t);
     if(check(t)){
        ans = t;
        cout<<"YES"<<endl;
        cout<<ans<<endl;
        exit(0);
    }
    if(i>=n){
        return ;
    }
      func(s,n,i+1,t);
     func(s,n,i+1,t+=s[i]);

     return ;
}
int main(){
    string s;
    cin>>s;
    int n = s.size();
    string t = "";
    int i = 0;
    func(s,n,i,t);
    if(ans.size()==0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
}