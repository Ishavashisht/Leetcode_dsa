class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Base case: sum 0 exists once
        int prefixSum = 0, count = 0;
        
        for (int num : nums) {
            prefixSum += num;

            // Compute mod k (adjust for negative remainders)
            int remainder = prefixSum % k;
            if (remainder < 0) remainder += k;

            // If this remainder has been seen before, add its count to the result
            if (prefixSumCount.find(remainder) != prefixSumCount.end()) {
                count += prefixSumCount[remainder];
            }

            // Update the frequency of this remainder
            prefixSumCount[remainder]++;
        }

        return count;
    }
};
