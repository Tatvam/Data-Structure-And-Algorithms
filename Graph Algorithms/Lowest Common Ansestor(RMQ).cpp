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
#define n 9

int euler[n*2-1];
int level[n*2-1];
int firstocc[n+1];
int idx;





struct node{
    int key;
    node* left;
    node* right;
};

typedef struct node node;

node* newnode(int key){
        node* temp = new node;
        temp->key = key;
        temp->left = NULL;
        temp->right = NULL;
}

void eulerTour(node* root ,int l){

    if(root!=NULL){
        level[idx]=l;
        euler[idx++]=root->key;

        if(firstocc[root->key]==-1){
            firstocc[root->key]=idx-1;
        }

        if(root->left){
            eulerTour(root->left,l+1);
            level[idx]=l;
            euler[idx++]=root->key;
        }
        if(root->right){
            eulerTour(root->right,l+1);
            level[idx]=l;
            euler[idx++]=root->key;
        }
    }

}

int RMQ(int si,int ss,int se,int qs,int qe,vector<int> st){

    if (qs <= ss && qe >= se)
        return st[si];

    else if (se < qs || ss > qe)
        return -1;
 
    int mid = (ss + se)/2;
 
    int q1 = RMQ(2*si+1, ss, mid, qs, qe, st);
    int q2 = RMQ(2*si+2, mid+1, se, qs, qe, st);
 
    if (q1==-1) return q2;
 
    else if (q2==-1) return q1;
 
    return (level[q1] < level[q2]) ? q1 : q2;
}

void constructst(int si,int ss,int se,vector<int> &st){
    if(ss == se){
        st[si]=ss;
    }else{
        int mid = (ss+se)/2;
        constructst(2*si+1,ss,mid,st);
        constructst(2*si+2,mid+1,se,st);

        if (level[st[2*si+1]] < level[st[2*si+2]])
            st[si] = st[2*si+1];
        else
            st[si] = st[2*si+2];
    }
}

int LCA(node* root,int u,int v){

    memset(firstocc,-1,sizeof firstocc);
    idx = 0;

    eulerTour(root,0);

    int x = log2(n)+1;
    int m = 2*(1<<x)-1;

    vector<int> st(m);

    constructst(0,0,n-1,st);

    if(firstocc[u]>firstocc[v]){
        swap(u,v);
    }

    int qs = firstocc[u];
    int qe = firstocc[v];

    int ind =  RMQ(0,0,2*n-1,qs,qe,st);

    cout<<euler[ind]<<endl;

}



int main(){

    node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->left->right->left = newnode(8);
    root->left->right->right = newnode(9);

    int u,v;
    cin>>u>>v;
    LCA(root,u,v);
    re(i,2*n){
        cout<<euler[i]<<" ";
    }
    cout<<endl;
    re(i,2*n){
        cout<<level[i]<<" ";
    }


}