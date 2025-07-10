class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    void backtrack(string &s, int start, vector<string> &path) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1)); // choose
                backtrack(s, end + 1, path);                       // explore
                path.pop_back();                                  // unchoose
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, 0, path);
        return result;
    }
};
