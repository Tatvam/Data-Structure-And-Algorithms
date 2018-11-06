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

int main(){
    test{
        string s;
        cin>>s;
        int n = s.size();
        int c1 = 0,c2 = 0,c3 = 0;
        re(i,n){
            if(s[i]>=65 && s[i]<=90){
                c1++;
            }
            else if(s[i]>=48 && s[i]<=57){
                c2++;
            }
            else{
                c3++;
            }
        }
        if(c1>0 && c2>0 && c3>0){
            
        }else if(c1>0 && c2>0 && c3==0){
           c1 = 0;c2 = 0;c3 = 0;
            re(i,n){
                 if(s[i]>=65 && s[i]<=90){
                c1++;
                if(c1>1){
                    s[i]='a';
                    break;
                }
            }
            else if(s[i]>=48 && s[i]<=57){
                c2++;
                if(c2>1){
                    s[i]='a';
                    break;
                }
            }
            }
        }
        else if(c1>0 && c2==0 && c3>0){
            c1 = 0;c2 = 0;c3 = 0;
            re(i,n){
                 if(s[i]>=65 && s[i]<=90){
                c1++;
                if(c1>1){
                    s[i]='1';
                    break;
                }
            }
            else if(s[i]>=97 && s[i]<=122){
                c3++;
                if(c3>1){
                    s[i]='1';
                    break;
                }
            }
            }
        }
        else if(c1==0 && c2>0 && c3>0){
           c1 = 0;c2 = 0;c3 = 0;
            re(i,n){
                 if(s[i]>=97 && s[i]<=122){
                c3++;
                if(c3>1){
                    s[i]='A';
                    break;
                }
            }
            else if(s[i]>=48 && s[i]<=57){
                c2++;
                if(c2>1){
                    s[i]='A';
                    break;
                }
            }
            }
        }
        else if(c1 ==0 && c2 == 0 && c3>0){
            s[0]='A';
            s[1]='1';
           }
           else if(c1 ==0 && c2>0 && c3==0){
               s[0]='A';
                s[1]='a';
           }
            else if(c1>0 && c2==0 && c3==0){
               s[0]='1';
                s[1]='a';
           }
        cout<<s<<endl;
    }
}