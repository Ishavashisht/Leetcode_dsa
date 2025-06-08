class Solution {
public:
    int longestPalindrome(vector<string>& words) {
         unordered_map<string, int> freq;
    for (string word : words) {
        freq[word]++;
    }

    int length = 0;
    bool centerUsed = false;

    for (auto& [word, count] : freq) {
        string rev = word;
        reverse(rev.begin(), rev.end());

        // Case 1: Palindromic word like "cc"
        if (word == rev) {
            // Use as many full pairs as possible
            int pairs = count / 2;
            length += pairs * 4;
            freq[word] -= pairs * 2;

            // If one left, it can be used in center
            if (!centerUsed && freq[word] > 0) {
                length += 2;
                centerUsed = true;
                freq[word]--; // optional, since it's used
            }
        }
        // Case 2: Non-palindromic word like "ab"
        else if (freq.find(rev) != freq.end()) {
            int pairs = min(freq[word], freq[rev]);
            length += pairs * 4;
            freq[word] -= pairs;
            freq[rev] -= pairs;
        }
    }

    return length;
    }
};