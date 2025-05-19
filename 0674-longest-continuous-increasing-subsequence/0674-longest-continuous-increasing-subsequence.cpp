class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxLength = 1, currLength = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currLength++; // Extend the current sequence
                maxLength = max(maxLength, currLength);
            } else {
                currLength = 1; // Reset for a new sequence
            }
        }

        return maxLength;
    }
};
