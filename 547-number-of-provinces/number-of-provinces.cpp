class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>&visited){
        visited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<bool>visited(n,false);
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i = 0;i<visited.size();i++){
            if(!visited[i]){
                cnt++;
            dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};