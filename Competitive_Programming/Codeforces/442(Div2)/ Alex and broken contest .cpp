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

int main(){
    string s ;
    cin>>s;
    string a = "Nikita";
    string b = "Danil";
    string c = "Olya";
    string d = "Ann";
    string e = "Slava";
    int ans = 0;
    size_t nPos = s.find(a, 0); // first occurrence
    while(nPos != string::npos)
    {
        if(ans>1){
            cout<<"NO"<<endl;
            return 0;
        }
        ans++;
        nPos = s.find(a, nPos + 1);
    }
     nPos = s.find(e, 0); // first occurrence
    while(nPos != string::npos)
    {
        if(ans>1){
            cout<<"NO"<<endl;
            return 0;
        }
        ans++;
        nPos = s.find(e, nPos + 1);
    }
    nPos = s.find(d, 0); // first occurrence
    while(nPos != string::npos)
    {
        if(ans>1){
            cout<<"NO"<<endl;
            return 0;
        }
        ans++;
        nPos = s.find(d, nPos + 1);
    }
    nPos = s.find(c, 0); // first occurrence
    while(nPos != string::npos)
    {
        if(ans>1){
            cout<<"NO"<<endl;
            return 0;
        }
        ans++;
        nPos = s.find(c, nPos + 1);
    }
    nPos = s.find(b, 0); // first occurrence
    while(nPos != string::npos)
    {
        if(ans>1){
            cout<<"NO"<<endl;
            return 0;
        }
        ans++;
        nPos = s.find(b, nPos + 1);
    }
    if(ans == 1){
        cout<<"YES"<<endl;}
        else{
            cout<<"NO"<<endl;
        }
    }
