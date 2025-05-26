class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
 unordered_map<int, int> prefixSumCount; 
        prefixSumCount[0]=1;
        int prefixSum=0,count=0;
        for(int num:nums){
         prefixSum+=num;
            //check 
            if(prefixSumCount.find(prefixSum-k)!=prefixSumCount.end()){
                count+=prefixSumCount[prefixSum-k];
            }
       // Update the frequency of the current prefix sum in the map.
        prefixSumCount[prefixSum]++;
        }
        return count;
    }
};