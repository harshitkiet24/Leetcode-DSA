class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        if (n == 1)
            return 1;

        vector<vector<int>> visit(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        visit[0][0] = 1;
        while (!q.empty()) {
            auto node = q.front();
            int dist = node.first;
            int row = node.second.first;
            int col = node.second.second;
            q.pop();
            if (row == n - 1 && col == m - 1) {
                return dist;
            }
            for (int i = row - 1; i <= row + 1; i++) {
                for (int j = col - 1; j <= col + 1; j++) {
                    if (i == row && j == col) {
                        continue;
                    } else {
                        if (i >= 0 && i < n && j >= 0 && j < m &&
                            !visit[i][j] && grid[i][j] == 0) {
                            visit[i][j] = 1;
                            q.push({dist + 1, {i, j}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};