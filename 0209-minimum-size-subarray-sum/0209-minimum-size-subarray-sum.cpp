class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,minLen=INT_MAX;
        int currSum=0;
        int n=nums.size();
        while(j<n){
            currSum+=nums[j];
            while(currSum>=target && i<=j){
                minLen=min(minLen,j-i+1);
                currSum-=nums[i];
                i++;
            }

            j++;
        }
        return minLen==INT_MAX?0:minLen;
    }
};