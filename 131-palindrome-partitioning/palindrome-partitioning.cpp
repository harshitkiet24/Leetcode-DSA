class Solution {
public:
    void str(string s,vector<vector<string>> &ans,int idx,vector<string>&path){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                str(s,ans,i+1,path);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int start,int end){
        while(start <= end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        str(s,ans,0,path);
        return ans;
    }
};