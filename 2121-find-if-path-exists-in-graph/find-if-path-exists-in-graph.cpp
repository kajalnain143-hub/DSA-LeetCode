class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>&visited,int source){
        if(visited[source]){
            return;
        }
        visited[source] = true;
        for(int neighbour : adj[source])
        {
            dfs(adj,  visited,neighbour);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       
        vector<vector<int>> adj(n);
         vector<bool>visited(n,false);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj,visited,source);
       
         
           
        return    visited[destination];
    }
};