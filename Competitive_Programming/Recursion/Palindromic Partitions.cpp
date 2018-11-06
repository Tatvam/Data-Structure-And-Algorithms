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
bool ispalindrome(string s,int st,int en){
    while(st<en){
        if(s[st]!=s[en]){
            return false;
        }
        st++;
        en--;
    }
    return true;
}
void totalper(string s,vector<vector<string> > &totper,vector<string> &currper,int st,int en){
    if(st>=en){
        totper.push_back(currper);
        return;
    }
    for(int i = st;i<s.size();i++){
        if(ispalindrome(s,st,i)){
            currper.push_back(s.substr(st,i-st+1));
            totalper(s,totper,currper,i+1,s.size());
            currper.pop_back();
        }
    }
}

int main(){
    string s;
    cin>>s;
    int n = s.length();

    vector<vector<string> > totper;
    vector<string> currper;

    totalper(s,totper,currper,0,n);

    re(i,totper.size()){
        re(j,totper[i].size()){
            cout<<totper[i][j]<<" ";
        }
        cout<<endl;
    }

}