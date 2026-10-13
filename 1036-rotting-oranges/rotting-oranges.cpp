class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<pair<int,int>,int>>q;
        int cntfrs = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        for(int i = 0 ; i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 2 ){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                    }
                    else if(grid[i][j] == 1){
                        cntfrs++;
                    }
                }
            }

            int tm = 0;
            int cnt = 0;
            while(!q.empty()){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                tm = max(tm,t);
                q.pop();
                for(int i = 0;i<4;i++){
                    int nx = r + dx[i];
                    int ny = c + dy[i];
        if((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m) && (visited[nx][ny] != 2) && (grid[nx][ny] == 1)){
                        q.push({{nx,ny},t+1});
                        visited[nx][ny] = 2;
                        cnt++;
                    }
                }
            }
            if(cnt != cntfrs){
                return -1;
            }
            return tm;
        }
};