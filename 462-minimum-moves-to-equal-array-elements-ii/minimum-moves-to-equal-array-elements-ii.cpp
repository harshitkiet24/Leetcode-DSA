class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        sort(nums.begin(),nums.end());
        if(n%2 != 0){
            x = nums[n/2];
        }
        else{
            x = (nums[n/2]+(nums[n/2-1]))/2;
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] > x){
                ans += nums[i]-x;
            }
            else{
                ans += x - nums[i];
            }
        }
        return (int)ans;
    }
};