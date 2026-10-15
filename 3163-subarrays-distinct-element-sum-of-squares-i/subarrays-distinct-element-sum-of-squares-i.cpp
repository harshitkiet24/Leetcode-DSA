class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        int sq = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            unordered_set<int> st;
            for(int j = i;j<n;j++){
                st.insert(nums[j]);
                num = st.size();
                sq = num * num;
                sum += sq;
            }
        }
        return sum;
    }
};