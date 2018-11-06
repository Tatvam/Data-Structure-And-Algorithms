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

int DP[100][3000];
int Diff(int A[],int idx,int sum,int total){

    if(idx == -1) return max(sum,total - sum);
    if(DP[idx][sum] != -1) return DP[idx][sum];
    else return DP[idx][sum] = min(Diff(A,idx-1,sum+A[idx],total),Diff(A,idx-1,sum,total));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        memset(DP,-1,sizeof(DP));
        int n,sum = 0;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
            sum += A[i];
        }
        int set1 = Diff(A,n-1,0,sum);
        int set2 = sum - set1;
        cout<<abs(set1-set2)<<endl;
        
    }
}