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
#define PI 3.1415926535897932384626433832795
#define MAX 100001
#define INF (1<<20)
#define si(x)\tscanf("%d",&x)
#define sl(x)\tscanf("%lld",&x)
#define ss(s)\tscanf("%s",s)
#define pi(x)\tprintf("%d\n",x)
#define pl(x)\tprintf("%lld\n",x)
#define ps(s)\tprintf("%s\n",s)
int constructSeg(vector<int> a,vector<int> &s,int ss,int se,int si){
    if(ss == se){
        s[si]=a[ss];
        return s[si];
    }

    int mid = (ss+se)/2;

    s[si]=min(constructSeg(a,s,ss,mid,2*si+1),constructSeg(a,s,mid+1,se,2*si+2));

    return s[si];
}
int RMQUtil(vector<int> s,int qs,int qe,int ss,int se,int index){
    if(qe>=se && qs<=ss){
        return s[index];
    }
    if(qe<ss || qs>se ){
        return INT_MAX;
    }
     int mid = (ss+se)/2;
    return min(RMQUtil(s, qs, qe,ss, mid,  2*index+1),
                  RMQUtil(s, qs, qe,mid+1, se, 2*index+2));
}
int RMQ(vector<int> s,int qs,int qe,int n){

    if(qs>qe || qs<0 || qe>n-1){
        return 0;
    }
   return  RMQUtil(s,qs,qe,0,n-1,0);
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    re(i,n){
        cin>>a[i];
    }
    int m = 2*pow(2,(int)ceil(log2(n)))-1;
    vector<int> s(m);
    constructSeg(a,s,0,n-1,0);
  //  re(i,m){
    //    cout<<s[i]<<" ";
   // }
    cout<<endl;
    int q;
    cin>>q;
    re(i,q){
        int qs,qe;
        cin>>qs>>qe;
       cout<< RMQ(s,qs,qe,n)<<endl;;
    }

}