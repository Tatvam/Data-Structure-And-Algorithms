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

int ans=0;

int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int left_height = diameter(root->left);
    int right_height = diameter(root->right);

    ans = max(ans,1+left_height+right_height);

    return 1 + max(left_height,right_height);
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
    diameter(root);
    cout<<ans<<endl;
}