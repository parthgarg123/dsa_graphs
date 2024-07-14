//using set
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int,int>>>adj;
        for(int i=0;i<vec.size();i++){
            int u= vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist(vertices, INT_MAX);
        set<pair<int,int>> s;
        dist[source]=0;
        s.insert({0,source});
        while(!s.empty()){
            auto top = *(s.begin());
            s.erase(s.begin());
            for(auto i:adj[top.second]){
                int sum = i.second + top.first;
                if(sum<dist[i.first]){
                    auto rec = s.find({dist[i.first],i.first});
                    if(rec!=s.end())
                        s.erase(rec);
                    
                    dist[i.first] = sum;
                    s.insert({dist[i.first],i.first});
                }
            }
    }
    return dist;
}

