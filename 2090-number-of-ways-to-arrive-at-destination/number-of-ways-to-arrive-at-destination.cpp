class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        for (auto it : roads) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;
        q.push({0,0});
        long long count = 0;
         while (!q.empty()) {
            long long distance = q.top().first;
            int node = q.top().second;
            q.pop();
            if (distance > dist[node]) continue;
            for (auto it : graph[node]) {
                int nnode = it.first;
                int ndis = it.second;
                if (distance + ndis < dist[nnode]) {
                    dist[nnode] = distance + ndis;
                    ways[nnode] = ways[node];
                    q.push({distance + ndis, nnode});
                }
                else if(distance + ndis == dist[nnode]){
                   ways[nnode] = (ways[nnode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};