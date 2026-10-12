class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32,0);
        long long MOD = 1e9 + 7;
        for(int &num : nums){
            for(int i=0;i<32;i++){
                if(num & (1LL << i)){
                    count[i]++;
                }
            }
        }
        long long result = 0;
        while(k--){
            long long curr =0;
        for(int i=0;i<32;i++){
            if(count[i] >= 1){
                count[i]--;
                curr = (curr | (1LL<<i));
            }
        }
        result = (result + (curr*curr)%MOD)%MOD;
    }
    return result;
    }
};