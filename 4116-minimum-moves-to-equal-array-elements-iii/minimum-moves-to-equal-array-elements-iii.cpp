class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans += maxi - nums[i];
        }
        return (int)ans;
    }
};