class Solution {
public:
    void dfs(int open,int close,string s,vector<string> &ans,int n){
        if(open == close && open + close == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            dfs(open+1,close,s + '(',ans,n);
        }
        if(open  > close){
            dfs(open,close+1,s + ')',ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0,0,"",ans,n);
        return ans;
    }
};