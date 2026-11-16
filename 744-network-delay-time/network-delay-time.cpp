class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        int ans = 0;
        for(auto it : times){
            graph[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            int dis = q.top().first;
            int node = q.top().second;
            q.pop();
            if(dis > dist[node]) continue;
            for(auto it : graph[node]){
                int nnode = it.first;
                int ndist = it.second;

                if(dis + ndist < dist[nnode]){
                    dist[nnode] = dis + ndist;
                    q.push({dis+ndist,nnode});
                }
            }
        }
        for(int i = 1;i<=n;i++){
            if(dist[i] == 1e9){
                return -1;
            }
            else{
                ans = max(ans,dist[i]);
            }
        }
        return ans;
    }
};