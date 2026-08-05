class Solution {
public:
    void func(vector<int> &arr,int idx,int target,vector<int> &ds,vector<vector<int>> &sum){
        if(target == 0){
            sum.push_back(ds);
            return;
        }
        if(idx == arr.size()){
            return;
        }

        for(int i=idx;i < arr.size();i++){
            if(i > idx && arr[i] == arr[i-1]){
                continue;
            }
            if(target < arr[i]){
                break;
            }
                ds.push_back(arr[i]);
                func(arr,i+1,target-arr[i],ds,sum);
                ds.pop_back();
            }
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> sum;
        func(candidates,0,target,ds,sum);
        return sum;
    }
};