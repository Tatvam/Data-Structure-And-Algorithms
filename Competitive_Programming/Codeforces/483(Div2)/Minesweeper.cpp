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
    int n,m;
    cin>>n>>m;
    char a[n][m];
    re(i,n){
        re(j,m){
            cin>>a[i][j];
        }
    }
    re(i,n){
        re(j,m){
             int cnt=0;
            if(a[i-1][j+1]=='*' && i-1>=0 && j+1>=0 && i-1<n && j+1<m){
                cnt++;
            }
             if(a[i+1][j]=='*' && i+1>=0 && j>=0 && i+1<n && j<m){
                cnt++;
            }
             if(a[i][j+1]=='*' && i>=0 && j+1>=0 && i<n && j+1<m){
                cnt++;
            }
             if(a[i+1][j+1]=='*' && i+1>=0 && j+1>=0 && i+1<n && j+1<m){
                cnt++;
            }
             if(a[i-1][j-1]=='*' && i-1>=0 && j-1>=0 && i-1<n && j-1<m){
                cnt++;
            }
             if(a[i-1][j]=='*' && i-1>=0 && j>=0 && i-1<n && j<m){
                cnt++;
            }
             if(a[i][j-1]=='*' && i>=0 && j-1>=0 && i<n && j-1<m){
                cnt++;
            }
             if(a[i+1][j-1]=='*' && i+1>=0 && j-1>=0 && i+1<n && j-1<m){
                cnt++;
            }
            //cout<<cnt<<endl;
            if(a[i][j]<='8' && a[i][j]>='1'){
                if((a[i][j]-'0')!=cnt){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            else if(a[i][j]=='.'){
                if(cnt!=0){
                    cout<<"NO"<<endl;
                    return 0;
                }

            }
        }
    }
    cout<<"YES"<<endl;
}