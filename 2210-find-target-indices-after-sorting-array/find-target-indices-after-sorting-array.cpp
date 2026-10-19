class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int small = 0;
        int eql = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < target){
                small++;
            }
            if(nums[i]==target){
                eql++;
            }
        }
        vector<int>ans;
        while(eql != 0){
            ans.push_back(small);
            small++;
            eql--;
        }
        return ans;;
    }
};