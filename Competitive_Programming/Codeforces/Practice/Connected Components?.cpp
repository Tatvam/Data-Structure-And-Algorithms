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


set<int> s1[200005];
set<int> s2;
vector<int> v;
int cnt = 0;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    s2.erase(s2.find(s));
    while(!q.empty())
     {
       int v=q.front();
       q.pop();
           cnt++;
         vector<int> ext;
       for(auto it = s2.begin();it!=s2.end();it++)
        {
            int u = *it;
          if(s1[v].find(u)==s1[v].end())
         {
              q.push(u);
              ext.push_back(u);
          }
        }
         re(i,ext.size()){
          s2.erase(s2.find(ext[i]));
      }
      }
     
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    re(i,edges){
        int x,y;
        cin>>x>>y;
        x--;y--;
        s1[x].insert(y);
        s1[y].insert(x);
    }
    re(i,nodes){
        s2.insert(i);
    }
    re(i,nodes){
        if(s2.find(i)!=s2.end()){

            cnt = 0;
            bfs(i);
            v.push_back(cnt);

        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    re(i,v.size()){
        cout<<v[i]<<" ";
    }
}