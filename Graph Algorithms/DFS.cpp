#include <iostream>
#include<vector>
using namespace std;

vector<int> adj[100000];
vector<bool> visited(100000);
 dfs(int s,vector<bool> &visited)
{
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        dfs(adj[s][i],visited);
    }
}
int main()
{
    int t;
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=nodes;i++)
    {

        visited[i]=false;
    }
    int x;
    cin>>x;
    dfs(x,visited);
    for(int i=1;i<=nodes;i++)
    {
        if(visited[i]==false)
        {
            t++;
        }
    }
    cout<<t<<endl;
    return 0;
}


