class Solution {
public:
    void func( vector<int> &ds,vector<vector<int>> &ans,int idx){
        if(idx==ds.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<ds.size();i++){
           swap(ds[idx],ds[i]);
           func(ds,ans,idx+1);
           swap(ds[idx],ds[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds = nums;
        vector<vector<int>> ans;
        int idx = 0;
        func(ds,ans,idx);
        return ans;
    }
};