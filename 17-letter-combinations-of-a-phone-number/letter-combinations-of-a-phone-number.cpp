class Solution {
public:
    void func( unordered_map<char,string> &mp,string &digits,vector<string> &ans,string s,int idx){
        if(idx == digits.length()){
            ans.push_back(s);
            return;
        }
            char c = digits[idx];
            string sr = mp[c];
            for(int i=0;i<sr.length();i++){
                s.push_back(sr[i]);
                func(mp,digits,ans,s,idx+1);
                s.pop_back();
            }
        }
    vector<string> letterCombinations(string digits) {
         unordered_map<char,string> mp;
         mp['2'] = "abc";
         mp['3'] = "def";
         mp['4'] = "ghi";
         mp['5'] = "jkl";
         mp['6'] = "mno";
         mp['7'] = "pqrs";
         mp['8'] = "tuv";
         mp['9'] = "wxyz";

         vector<string> ans;
         string s;
         func(mp,digits,ans,s,0);
         return ans;
    }
};