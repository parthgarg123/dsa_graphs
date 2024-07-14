#include<bits/stdc++.h>

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u, int v, int w){
        pair<int,int>p = make_pair(v,w);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<'['<<j.first<<", "<<j.second<<"], ";
            }
            cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int,bool> &visited,stack<int> &s){
        visited[node] = true;

        for(auto i:adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,s);
            }
        }
        s.push(node);
    }

    void shortestPath(int src, stack<int>&s,vector<int>&dist){
        dist[src] =0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(dist[top]!=INT_MAX){
                for(auto i:adj[top]){
                    int sum = dist[top]+i.second;
                    if(sum<dist[i.first]){
                        dist[i.first] = sum;
                    }
                }
            }
        }
    }
};

int main(){

    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);


    g.printAdj();

    int n=5;
    unordered_map<int,bool> visited(false);
    stack<int> s;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i, visited,s);
        }
    }

    int src=1;
    vector<int> dist(n,INT_MAX);
    
    g.shortestPath(src,s,dist);

    for(auto i:dist){
        (i==INT_MAX)?cout<<"\u221E ":cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}