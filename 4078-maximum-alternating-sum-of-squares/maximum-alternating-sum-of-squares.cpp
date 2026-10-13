class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            int a = abs(nums[i]);
            ans.push_back(a);
        }
        sort(ans.begin(),ans.end());
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i=0;i<ans.size();i++){
            if(i< ans.size()/2){
                sum1=sum1+ans[i]*ans[i];
            }
            else
            sum2=sum2+ans[i]*ans[i];
        }
        return sum2-sum1;
    }
};