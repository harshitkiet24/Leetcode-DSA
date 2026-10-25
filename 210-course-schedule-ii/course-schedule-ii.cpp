class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>>adj(n);
        for(auto it : preq){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(n,0);
        for(int i = 0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        vector<int>topo;
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                topo.push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    topo.push_back(it);
                    q.push(it);
                }
            }
        }

        if(topo.size() != n){
            return {};
        }
        return topo;
    }
};