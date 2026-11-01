class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = INT_MAX;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] < min){
                min = nums[i];
            }
        }

        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans += nums[i]-min;
        }
        return (int)ans;
    }
};