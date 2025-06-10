class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

    // Count frequencies of each character
    for (char c : s) {
        freq[c]++;
    }

    int maxDiff = INT_MIN;
    bool found = false;

    // Try all combinations of odd freq character and even freq character
    for (auto& [char1, count1] : freq) {
        if (count1 % 2 == 1) { // a1 has odd frequency
            for (auto& [char2, count2] : freq) {
                if (count2 % 2 == 0) { // a2 has even frequency
                    maxDiff = max(maxDiff, count1 - count2);
                    found = true;
                }
            }
        }
    }

    return found ? maxDiff : 0; // Return 0 if no valid pair found

    }
};