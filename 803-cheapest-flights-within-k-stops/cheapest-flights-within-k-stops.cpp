class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto it : flights) {
            int s = it[0];
            int d = it[1];
            int di = it[2];

            graph[s].push_back({d, di});
        }
    vector<int> dist(n, 1e9);
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    dist[src] = 0;

    while (!q.empty()) {
        int stop = q.front().first;
        int node = q.front().second.first;
        int dis = q.front().second.second;
        q.pop();
        if (stop > k) {
            continue;
        }
        for (auto it : graph[node]) {
            int dest = it.first;
            int distance = it.second;

            if (dis + distance < dist[dest] && stop <= k) {
                dist[dest] = dis + distance;
                q.push({stop + 1, {dest, dis + distance}});
            }

            
        }
    }
    if (dist[dst] == 1e9) {
        return -1;
    }

    return dist[dst];
}
};