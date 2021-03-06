class Solution {
    public:
    void pattern(int n, int open, int close, string s, vector<string> &ans) {
        if(open == n && close == n) {
            return ans.push_back(s);
        }
        if(open < n) {
            pattern(n, open + 1, close, s + '(', ans);
        }
        if(open > close) {
            pattern(n, open, close + 1, s + ')', ans);
        }
    }

    vector<string> AllParenthesis(int n) {
        vector<string> ans;
        pattern(n, 0, 0, "", ans);
        return ans;
    }
};