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
typedef pair<int,pii> piii;
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
int le[4000001] ={0};
int ri[4000001] ={0};
int ans[4000001] ={0};

string s;
piii query(int qs,int qe,int ss,int se,int index){
    if(qe>=se && qs<=ss){
        return make_pair(ans[index],make_pair(le[index],ri[index]));
    }
    if(qe<ss || qs>se ){
        return make_pair(0,make_pair(0,0));
    }
    int mid = (ss+se)/2;
    piii p = query(qs,qe,ss,mid,2*index+1);
    piii o = query(qs,qe,mid+1,se,2*index+2);
    int x,y,z;
    int tmp = min(p.second.first,o.second.second);
    x = p.first+o.first+tmp;
    y=p.second.first+o.second.first-tmp;
    z = p.second.second+o.second.second-tmp;
    return make_pair(x,make_pair(y,z)); 
    
}
int build(int ss,int se,int si){

    if(ss == se){
        if(s[ss] =='('){
            le[si]=1;
        }
        else{
            ri[si]=1;
        }
        ans[si]=0;

    }
    else{
    int mid = (ss+se)/2;
    build(ss,mid,2*si+1);
    build(mid+1,se,2*si+2);
    int tmp = min(le[2*si+1],ri[2*si+2]);
    ans[si]=ans[2*si+1]+ans[2*si+2]+tmp;
    le[si]=le[2*si+1]+le[2*si+2]-tmp;
    ri[si]=ri[2*si+1]+ri[2*si+2]-tmp;
    }
    return ans[si];

}

int main(){
    cin>>s;
    int n = s.size();
    build(0,n-1,0);    
    int q;
    cin>>q;
    piii z;
    re(i,q){
        int l,r;
        cin>>l>>r;
       z = query(l-1,r-1,0,n-1,0);
       cout<<z.first*2<<endl;
    }
    

}