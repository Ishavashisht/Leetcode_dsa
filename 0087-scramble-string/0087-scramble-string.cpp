class Solution {
public:
    // bool isScramble(string s1, string s2) {
        
    // }
    unordered_map<string, bool> memo; // Memoization map

    // Helper function to check if s2 is a scramble of s1
    bool isScrambleHelper(string s1, string s2) {
     if (s1 == s2) return true;

        // If sorted characters don’t match, can't be a scramble
        string sorted1 = s1, sorted2 = s2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2) return false;

        // Create a unique key for memoization
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.length();
        // Try all possible split points
        for (int i = 1; i < n; ++i) {
            // Case 1: No swap
            if (isScrambleHelper(s1.substr(0, i), s2.substr(0, i)) &&
                isScrambleHelper(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swap
            if (isScrambleHelper(s1.substr(0, i), s2.substr(n - i)) &&
                isScrambleHelper(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false; // Store and return
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        return isScrambleHelper(s1, s2);
    }
};