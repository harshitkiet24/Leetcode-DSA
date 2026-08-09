class Solution {
public:
    void func(vector<int> &nums,vector<int>&ds,vector<vector<int>> &ans, map<int,int> mp){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }


        for(auto &it : mp){
            int val = it.first;
            if(it.second > 0){
                it.second--;
                ds.push_back(val);
                func(nums,ds,ans,mp);
                it.second++;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        map <int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        func(nums,ds,ans,mp);
        return ans;
    }
};