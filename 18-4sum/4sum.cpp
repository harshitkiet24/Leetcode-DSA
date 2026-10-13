class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
         vector<vector<int>> ans;
         int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && arr[i] == arr[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && arr[j] == arr[j-1]){
                    continue;
                }
                int left = j+1;
                int right = n-1;
                while(left<right){
                long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];
                if(sum == target){
                    vector<int> temp = {arr[i],arr[j],arr[left],arr[right]};
                    ans.push_back(temp);
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            }
            else if(sum>target){
                right--;
            }
            else{
                left++;
            }
                }
            }
        }
            return ans;
    }
};