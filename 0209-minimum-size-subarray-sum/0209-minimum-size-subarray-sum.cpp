class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,minLen=INT_MAX;
        int currSum=0;
        int n=nums.size();
        while(r<n){
            currSum+=nums[r];
            while(currSum>=target && l<=r){
                minLen=min(minLen,r-l+1);
                currSum-=nums[l];
                l++;
            }
            r++;
        }
        return minLen==INT_MAX?0:minLen;
    }
};