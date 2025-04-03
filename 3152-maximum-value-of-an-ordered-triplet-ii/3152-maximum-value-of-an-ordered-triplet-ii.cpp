class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        long long maxDiff = 0;
        long long maxi = 0;

        for(int k = 0; k < n; k++) {
            res = max(res, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxi - nums[k]);
            maxi = max(maxi, (long long)nums[k]);
        }
        return res;
    }
    
};