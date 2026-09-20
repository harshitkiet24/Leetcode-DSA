class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
              int  y = 'z' - s[i] + 1;
            sum += (i+1)*y;
        }
        return sum;
    }
};