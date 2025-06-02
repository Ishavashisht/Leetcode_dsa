class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> num_set(nums.begin(), nums.end());

    // Variable to track the longest sequence
    int longest = 0;

    // Iterate through the numbers
    for (int num : num_set) {  // Iterate directly over the set
        // Only process if num is the start of a sequence
        if (num_set.find(num - 1) == num_set.end()) {
            int current_num = num;
            int current_length = 1;

            // Count the length of the current sequence
            while (num_set.find(current_num + 1) != num_set.end()) {
                current_num++;
                current_length++;
            }

            // Update the longest sequence length
            longest = max(longest, current_length);
        }
    }

    return longest;
    }
};