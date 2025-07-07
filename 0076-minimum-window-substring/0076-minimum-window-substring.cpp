class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        unordered_map<char, int> tFreq, windowFreq;

        for (char c : t) tFreq[c]++;

        int have = 0, need = tFreq.size();
        int left = 0, minLen = INT_MAX, startIdx = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            windowFreq[c]++;

            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
