class Solution {
public:
    void func(vector<int>&arr,vector<int>&ds,int idx,vector<vector<int>> &subset){
        subset.push_back(ds);
        for(int i = idx;i < arr.size();i++){
            if(i > idx && arr[i] == arr[i-1]){
                continue;
            }
            ds.push_back(arr[i]);
            func(arr,ds,i+1,subset);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subset;
        vector<int> ds;
        func(nums,ds,0,subset);
        return subset;
    }
};