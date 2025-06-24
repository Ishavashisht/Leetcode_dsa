class Solution {
public:
   vector<int> singleNumber(vector<int>& nums) {
    long long xorAll = 0;
    for (int num : nums) {
        xorAll ^= num; // XOR of all numbers
    }

    // Find the rightmost set bit in xorAll
    int diffBit = xorAll & -xorAll;

    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & diffBit) {
            num1 ^= num; // XOR numbers with the diffBit set
        } else {
            num2 ^= num; // XOR numbers without the diffBit set
        }
    }

    return {num1, num2};
}
};