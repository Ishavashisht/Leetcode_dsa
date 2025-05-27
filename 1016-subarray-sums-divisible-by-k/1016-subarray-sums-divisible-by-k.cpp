class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];

    
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    unordered_map<int, int> mp;//map m remainder store kr rhe h 
 mp[0] = 1;
    int count = 0;

    for (int j = 0; j < n; j++) {
        int rem = prefixSum[j] % k;
        if (rem < 0) rem += k; 
        if (mp.find(rem) != mp.end()) {
            count += mp[rem];
        }

       
        mp[rem]++;
    }
    return count;

    }
    };