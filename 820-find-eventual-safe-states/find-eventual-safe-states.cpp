class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            indegree[i] = graph[i].size();
        }
        vector<vector<int>> revgraph(n);
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                revgraph[it].push_back(i);
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for (auto it : revgraph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(safe[i] == true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};