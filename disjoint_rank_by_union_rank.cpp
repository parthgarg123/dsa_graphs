#include<bits/stdc++.h>

class DisjointSet{
    private:
    vector<int> rank, parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int Up_u = findUParent(u);
        int Up_v = findUParent(v);
        if(Up_u == Up_v) return ;
        if(rank[Up_u]<rank[Up_v]){
            parent[Up_u] = Up_v;
        }
        else if(rank[Up_v]<rank[Up_u]){
            parent[Up_v] = Up_u;
        }
        else{
            parent[Up_u] = Up_v;
            rank[Up_v]++;
        }
    }
    void unionBySize(int u, int v){
        int Up_u = findUParent(u);
        int Up_v = findUParent(v);
        if(Up_u == Up_v) return ;
        if(size[Up_u]<size[Up_v]){
            parent[Up_u] = Up_v;
            size[Up_v]+=size[Up_u];
        }
        else{
            parent[Up_v] = Up_u;
            size[Up_u]+=size[Up_v];
        }
    }

};
int main(){

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    (ds.findUParent(3)==ds.findUParent(7))?
        cout<<"Same":cout<<"Not Same";
    cout<<endl;

    ds.unionBySize(3,7);

    (ds.findUParent(3)==ds.findUParent(7))?
        cout<<"Same":cout<<"Not Same";
    cout<<endl;
    return 0;
}