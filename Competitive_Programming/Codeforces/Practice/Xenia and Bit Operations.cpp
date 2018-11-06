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
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define ps(s) printf("%s",s)
int s[300005]= {0};
int a[300005]= {0};
 int n,q;
void build(int ss,int se,int index,int l){
    if(ss == se){
        s[index]=a[ss];
    }
    else{
    int mid = (ss+se)/2;
    build(ss,mid,2*index+1,l-1);
    build(mid+1,se,2*index+2,l-1);

    if(l%2==0){
        s[index]=s[2*index+1]^s[2*index+2];
    }else{
        s[index]=s[2*index+1]|s[2*index+2];
    }
    }

}
void query(int i,int ss,int se,int index,int l){
    if(ss == se){
        s[index]=a[ss];
    }
    else{
    int mid = (ss+se)/2;
    if(i<=mid)
    build(ss,mid,2*index+1,l-1);
    else
    build(mid+1,se,2*index+2,l-1);

    if(l%2==0){
        s[index]=s[2*index+1]^s[2*index+2];
    }else{
        s[index]=s[2*index+1]|s[2*index+2];
    }
    }

}
int main(){
   // turbo;
  scanf ("%d %d", &n, &q);
    int m = n;
    n = 1<<n;
    re(i,n){
       scanf ("%d", &a[i]);
    }
    build(0,n-1,0,m);
     int p,b;
    re(i,q){
        scanf ("%d %d", &p ,&b);
        a[p-1]=b;
        query(p-1,0,n-1,0,m);
        printf ("%d\n", s[0]);
    }
    

}