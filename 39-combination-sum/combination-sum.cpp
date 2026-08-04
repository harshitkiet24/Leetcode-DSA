class Solution {
public:
    void func(vector<int> &ds,vector<int>& arr,int idx, int target,vector<vector<int>> &sum){
        if(target == 0){
            sum.push_back(ds);
            return;
        }
        if(idx == arr.size()){
            return;
        }
        if(target >= arr[idx]){
        ds.push_back(arr[idx]);
        func(ds,arr,idx,target-arr[idx],sum);
        ds.pop_back();
        }
        func(ds,arr,idx+1,target,sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>> sum;
        func(ds,candidates,0,target,sum);
        return sum;
    }
};