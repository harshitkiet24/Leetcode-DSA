class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int original_color = image[sr][sc];

    if (original_color == color) {
        return image;
    }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    image[sr][sc] = color;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                image[nx][ny] == original_color) {
                image[nx][ny] = color;
                q.push({nx, ny});
            }
        }
        }
        return image;
    }
};