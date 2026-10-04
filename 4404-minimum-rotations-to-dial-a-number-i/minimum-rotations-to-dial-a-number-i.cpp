class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int a = 0;
        for(int i = 0;i<s.length();i++){
            char b = s[i] - '0';
            int clock = abs(a - b);
            int anticlock = 10 - clock;
            ans += min(clock,anticlock);
            a = b;
        }
        return ans;
    }
};