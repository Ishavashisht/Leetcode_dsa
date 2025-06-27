class Solution {
public:
 unordered_map<int, bool> dp;
    
    bool solve(int usedMask, int currSum, int target, int k, vector<int>& nums) {
        int n = nums.size();
        if (k == 1) return true; // Only one group left, it's valid
        if (dp.count(usedMask)) return dp[usedMask];
        
        for (int i = 0; i < n; i++) {
            if (((usedMask >> i) & 1) == 0) { // Check if the i-th element is not used
                if (currSum + nums[i] > target) continue; // Skip if exceeding the target
                
                int newMask = usedMask | (1 << i); // Mark i-th element as used
                if (currSum + nums[i] == target) {
                    if (solve(newMask, 0, target, k - 1, nums)) {
                        return dp[usedMask] = true;
                    }
                } else {
                    if (solve(newMask, currSum + nums[i], target, k, nums)) {
                        return dp[usedMask] = true;
                    }
                }
            }
        }
        return dp[usedMask] = false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (k <= 0 || totalSum % k != 0) return false;
        int target = totalSum / k;
        
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false; // Largest number exceeds target
        
        int n = nums.size();
        int usedMask = 0;
        
        return solve(usedMask, 0, target, k, nums);
    }
};