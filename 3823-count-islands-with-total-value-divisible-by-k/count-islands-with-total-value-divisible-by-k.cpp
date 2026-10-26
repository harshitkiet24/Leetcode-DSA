class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&grid,long long &sum,int dx[],int dy[],int n,int m){
        visited[row][col] = 1;
        sum += grid[row][col];
        for(int i = 0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] != 0){
            dfs(nrow,ncol,visited,grid,sum,dx,dy,n,m);
            }
        }
        return;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int ans = 0;
        long long sum = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j] && grid[i][j] != 0){
                   dfs(i,j,visited,grid,sum,dx,dy,n,m);
                   if(sum%k == 0){
                        ans++;
                   }
                   sum = 0;
                }
            }
        }
    return ans;
    }
};