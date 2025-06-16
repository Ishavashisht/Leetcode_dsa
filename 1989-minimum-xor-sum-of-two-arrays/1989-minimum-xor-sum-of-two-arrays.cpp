class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int size=1<<n;
        vector<int>dp(size,INT_MAX);
        dp[0]=0;
        for(int mask=0;mask<size;mask++){
             int i = __builtin_popcount(mask);

             for(int j=0;j<n;j++){
                if((mask&(1<<j))==0){
                    int newMask=mask|(1<<j);
                    int xorSum=nums1[i]^nums2[j];
                    dp[newMask]=min(dp[newMask],dp[mask]+xorSum);
                }

             }

        }
        return dp[size-1];
    }
};