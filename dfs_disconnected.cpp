#include<bits/stdc++.h>

void dfs(vector<int> &comp,int i, unordered_map<int,list<int>> &adj,
vector<bool> &visited){
    comp.push_back(i);
    visited[i]=1;
    for(auto j:adj[i]){
        if(!visited[j]){
            dfs(comp, j, adj, visited);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u= edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<bool> visited(V, false);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> comp;
            dfs(comp,i,adj,visited);
            ans.push_back(comp);
        }
    }
    return ans;
}