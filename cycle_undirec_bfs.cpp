//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
  bool cycle(int node, int visited[], vector<int> adj[]){
      
      visited[node] =1;
      queue<pair<int,int>> hist;
      hist.push({node,-1});
      
      while(!hist.empty()){
          pair<int,int> p = hist.front();
          hist.pop();
          for(auto i:adj[p.first]){
              if(!visited[i]){
                  visited[i]=1;
                  hist.push({i,p.first});
              }
              else if(i!=p.second){
                  return true;
              }
          }
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        int visited[V] = {0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycle(i,visited,adj)==true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends