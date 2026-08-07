class Solution {
public:
    void func( vector<int> &ds,vector<vector<int>> &ans,vector<int> &nums,int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                ds.push_back(nums[i]);
                freq[i] = 1;
                func(ds,ans,nums,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i] = 0;
        }
        func(ds,ans,nums,freq);
        return ans;
    }
};