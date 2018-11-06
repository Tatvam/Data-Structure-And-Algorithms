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
    int n;
    cin>>n;
    vector<int> v(n);
    vector<pair<int,int> > s(n);

    re(i,n){
        cin>>v[i];
        s[i]=make_pair(v[i],i);
    }
    sort(s.begin(),s.end());
    map<int,int> m;
    re(i,n){
        m[v[i]]++;
    }
    int cnt = 0;
    int ct=0;
    for(map<int,int> :: iterator it =m.begin();it!=m.end();it++){
        if((it->second)>2){
            cnt++;
        }
        if(it->second==1){
            ct++;
        }
    } 
    int flag = 0;
    vector<char> ans(n); 
    int j = 0;
    if(ct%2!=0 && cnt==0){
        cout<<"NO"<<endl;
        return 0;
    }else if(ct==0){
        int flag3 = 0;
        re(i,n-1){
            if(s[i].first==s[i+1].first){
                if(flag3 == 0){
                    ans[s[i].second]='B';
                    ans[s[i+1].second]='B';
                }
                 else{
                    ans[s[i].second]='A';
                    ans[s[i+1].second]='A';
                }
            }else{
                if(flag3 ==0){
                     ans[s[i+1].second]='A';
                     flag3 = 1;
                }else{
                    ans[s[i+1].second]='B';
                     flag3 = 0;
                }
               
            }
        }
    }
    else if(ct%2==0){
        re(i,n){
            if(m[v[i]]==1 && flag == 0){
                ans[i]='B';
                flag = 1;
            }else if(m[v[i]]==1 && flag == 1){
                ans[i]='A';
                flag = 0;
            }else{
            ans[i]='B';
            }
        }
    }else if(ct%2!=0 && cnt>0){
        int flag2 = 0;
        flag = 0;
        re(i,n){
            if(m[v[i]]>2 && flag2 == 0){
                ans[i]='B';
                j = i;
                break;
            }
        }
        re(i,n){
            if(j!=i){
              if(m[v[i]]==1 && flag == 0){
                ans[i]='A';
                flag = 1;
            }else if(m[v[i]]==1 && flag == 1){
                ans[i]='B';
                flag = 0;
            }else{
            ans[i]='A';
            }
        }

    }
    }
    cout<<"YES"<<endl;
    re(i,ans.size()){
        cout<<ans[i];
    }
    cout<<endl;

}