class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y,
             vector<vector<int>>& visited, int n, int m) {
        visited[x][y] = 1;
        queue<pair<int, int>> q;
        q.push({x, y});
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] &&
                    grid[nx][ny] == '1') {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
        int numIslands(vector<vector<char>> & grid) {
            int cnt = 0;
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> visited(n, vector<int>(m, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!visited[i][j]) {
                        if (grid[i][j] == '1') {
                            cnt++;
                            bfs(grid, i, j, visited, n, m);
                        }
                    }
                }
            }
            return cnt;
        }
    };