#include<bits/stdc++.h>

template <typename T>

class graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T a, T b, bool direc){

        adj[a].push_back(b);
        if(direc == 0){
            adj[b].push_back(a);
        }
    }

    void printEdge(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main(){
    
    int n,m,a,b;
    cin>>n>>m;
    graph <int> g;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g.addEdge(a,b,0);
    }
    g.printEdge();

    return 0;
}