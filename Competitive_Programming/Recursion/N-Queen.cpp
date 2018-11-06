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

int board[100][100];

bool check(int i,int j,int n){
    re(k,n){
        if(board[i][k]==1 || board[k][j]==1){
            return false;
        }
    }
    re(k,n){
        re(l,n){
            if(((k+l) == (i+j)) || ((k-l)==(i-j))){
                if(board[k][l]==1){
                    return false;
                }
            }
        }
    }
    return true;
}

int NQueen(int n,int N){

    if(n==0){
        return 1;
    }
    re(i,N){
        re(j,N){
            if(check(i,j,N) && board[i][j]!=1){

                board[i][j]=1;
                if(NQueen(n-1,N)==1){
                    return 1;
                }
                board[i][j]=0;
            }

        }
    }
    return 0;

}

int main(){
    int n;
    cin>>n;
    re(i,n){
        re(j,n){
            board[i][j]=0;
        }
    }
    NQueen(n,n);
    re(i,n){
        re(j,n){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}