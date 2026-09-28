class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int x = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '('){
                x = x + 1;
                ans = max(ans,x);
            }
            if(s[i] == ')'){
                x = x - 1;
            }
        }
        return ans;
    }
};