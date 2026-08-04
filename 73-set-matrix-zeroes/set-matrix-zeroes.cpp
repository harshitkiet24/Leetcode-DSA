class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.empty() ? 0 : matrix[0].size();
        vector<int> arr1(n,0);
        vector<int> arr2(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                   arr1[i]=1;
                   arr2[j]=1; 
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr1[i]==1||arr2[j]==1){
                    matrix[i][j] = 0;
                }
            }
    }
}
};