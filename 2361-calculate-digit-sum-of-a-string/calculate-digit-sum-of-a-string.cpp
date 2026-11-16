class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string newr = "";
            for (int i = 0; i < s.size(); i+=k) {
                string next = s.substr(i, k);
                int sum = 0;
                for (int j = 0; j < next.size(); j++) {
                    sum += next[j] - '0';
                }
                  newr += to_string(sum);
            }
            s = newr;
        }
        return s;
    }
};