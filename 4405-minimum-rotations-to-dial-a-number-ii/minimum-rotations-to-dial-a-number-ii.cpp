class Solution {
public:
    int cost(char x ,char y){
        int a = x - '0';
        int b = y - '0';
        int clock = abs(a - b);
        int anticlock = 10 - clock;
        return min(clock,anticlock);
    }
    int find(string temp){
        int ans = 0;
        char a = '0';
        for(int i = 0;i<temp.length();i++){
            ans += cost(a,temp[i]);
            a = temp[i];
        }
        return ans;
    }

    int minRotations(int n, string s) {
        int ans = INT_MAX;
       int original_steps = find(s);
        for(int i = 1;i<n;i++){
            int x = original_steps - cost(s[i-1], s[i]) + cost(s[i-1], s[n-1]);
            ans = min(ans,x);
        }
        string temp = s;
        reverse(temp.begin(),temp.end());
        ans = min(ans,find(temp));
        return ans;
    }
};