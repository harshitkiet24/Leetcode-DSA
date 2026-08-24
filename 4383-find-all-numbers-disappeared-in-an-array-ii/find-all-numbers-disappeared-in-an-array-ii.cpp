class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
       sort(nums.begin(), nums.end());

        vector<int> x;
        vector<vector<int>> ans;

        int y = lower;
        int j = 0;

        // Skip numbers smaller than lower
        while (j < nums.size() && nums[j] < lower) {
            j++;
        }

        for (int i = lower; i <= upper; i++) {

            // Move pointer if current number is smaller than i
            while (j < nums.size() && nums[j] < i) {
                j++;
            }

            // i is present
            if (j < nums.size() && nums[j] == i) {

                if (i > y) {
                    x.push_back(y);
                    x.push_back(i - 1);

                    ans.push_back(x);
                    x.clear();
                }

                y = i + 1;

                // Skip duplicates
                while (j < nums.size() && nums[j] == i) {
                    j++;
                }
            }
        }

        // Missing range after the last existing number
        if (y <= upper) {
            ans.push_back({y, upper});
        }

        return ans; 
    }
};