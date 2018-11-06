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
    ll n;
    cin>>n;
    string a;
    string b;
    string c;
    cin>>a;
    cin>>b;
    cin>>c;
    if(n>=a.size()){
        cout<<"Draw"<<endl;
        return 0;
    }
    ll k = a.size();
    map<char,ll> m;
    map<char,ll> m1;
    map<char,ll> m2;
    re(i,a.size()){
        m[a[i]]++;
        m1[b[i]]++;
        m2[c[i]]++;
    }
    ll mx=0;
    for(map<char,ll>::iterator it=m.begin(); it!=m.end(); ++it){
             ll d = n+it->second;
            if(d>k){
                ll t = d-k;
                if(t==1 && it->second == k){
                    d = k-1;
                }
                else{
                    d=k;
                }
            }
        if(d>mx){
            mx=d;
        }
    }
    ll mx1=0;
    for(map<char,ll>::iterator it=m1.begin(); it!=m1.end(); ++it){
               ll d = n+it->second;
            if(d>k){
                ll t = d-k;
                if(t==1 && it->second == k){
                    d = k-1;
                }
                else{
                    d=k;
                }
            }
        if(d>mx1){
            mx1=d;
        }
    }
    ll mx2=0;
    for(map<char,ll>::iterator it=m2.begin(); it!=m2.end(); ++it){
            ll d = n+it->second;
            if(d>k ){
                ll t = d-k;
                if(t==1 && it->second == k){
                    d = k-1;
                }
                else{
                    d=k;
                }
            }
        if(d>mx2){
            mx2=d;
        }
        }
    ll mf = max(mx,max(mx1,mx2));
     if((mf==mx && mf==mx1 ) || (mf==mx2 && mf==mx1 ) || (mf==mx && mf==mx2 ) ){
        cout<<"Draw"<<endl;
    }
    else{
        if(mf==mx){
            cout<<"Kuro"<<endl;
        }
        else if(mf==mx1){
            cout<<"Shiro"<<endl;
        }
        else{
            cout<<"Katie"<<endl;
        }
    }
}
    


