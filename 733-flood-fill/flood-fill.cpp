class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int original_color = image[sr][sc];

    if (original_color == color) {
        return image;
    }
         vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            image[x][y] = color;
            for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                !visited[nx][ny] &&
                image[nx][ny] == original_color) {

                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
        }
        return image;
    }
};