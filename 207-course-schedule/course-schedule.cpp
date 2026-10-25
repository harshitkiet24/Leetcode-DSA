class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis)){
                    return true;
                }
            }
            else if(pathvis[it] == 1){
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>>adj(n);
        for(auto it : preq){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)){
                    return false;
                }
            }
        }
        return true;
    }
};