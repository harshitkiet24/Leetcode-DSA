class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord))
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if(st.count(beginWord)){
            st.erase(beginWord);
        }
        while (!q.empty()) {
            string sr = q.front().first;
            int level = q.front().second;
            q.pop();
            if (sr == endWord) {
                return level;
            }
            for (int i = 0; i < sr.size(); i++) {
                char original = sr[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    sr[i] = ch;
                    if (st.count(sr)) {
                        q.push({sr, level + 1});
                        st.erase(sr);
                    }
                }
                sr[i] = original;
            }
        }
        return 0;
    }
};