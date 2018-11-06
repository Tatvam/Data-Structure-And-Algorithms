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
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
int check (unsigned int x)
{
 return (
   x == 1 || x == 3 || x == 7 || x == 15 || x == 31 ||
   x == 63 || x == 127 || x == 255 || x == 511 || x == 1023 ||
   x == 2047 || x == 4095 || x == 8191 || x == 16383 ||
   x == 32767 || x == 65535 || x == 131071 || x == 262143 ||
   x == 524287 || x == 1048575 || x == 2097151 ||
   x == 4194303 || x == 8388607 || x == 16777215 ||
   x == 33554431 || x == 67108863 || x == 134217727 ||
   x == 268435455 || x == 536870911 || x == 1073741823 ||
   x == 2147483647);
}
int main(){
    test{
    int n,k;
    cin>>k>>n;
    vector<int> c(k);
    int cnt = 0;
    int f =n;
    while(f!=0){
        f = f >> 1;
        cnt ++;
    }
    if(n==1){
        re(i,k){
            cout<<1<<" ";

        }
        cout<<endl;
        continue;
    }
    //c[0]=n;
    int j =1;
    ll a = pow(2,cnt)-1;
    //cout<<a<<endl;
    int h = k;
    if(k==1){
        cout<<n<<endl;
        continue;
    }
    else if(k%2==0){
        if(n == a){
            c[0]=n-1;
            ll b = a^(n-1);
            c[j]=b;
            j++;
             rep(o,2,h-1){
            c[j++]=1;
        }
        }
        else{
            c[0]=n;
        ll b = a^n;
        c[j]=b;
        j++;
        rep(o,2,h-1){
            c[j++]=1;
        }
    }
    }
    else{
        if(n == a){
                re(p,k){
                    c[p]=a;
                }
            }
            else{
                c[0]=n;
                 ll b=a^n;
                 if(check(b)){
                     
                      if(b == 1 && n==2){
                         c[1]=1;
                         c[2]=1;
                     }
                     else if(b == 1){
                         c[1]=2;
                         c[2]=3;
                     }
                     else{
                         c[1] = b-1;
                         c[2] = (b-1)^b;
                     }
                     rep(o,3,h-1){
                         c[o]=1;
                     }
                 }
                 else{
                     cnt =0;
                      int q =b;
                     while(q!=0){
                     q = q >> 1;
                     cnt ++;
                        }
                        c[1]=pow(2,cnt)-1;
                        c[2]=b^c[1];
                        rep(o,3,h-1){
                     c[o]=1;
                        }
                 }
                 }
             
            }
    re(i,k){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    }
}