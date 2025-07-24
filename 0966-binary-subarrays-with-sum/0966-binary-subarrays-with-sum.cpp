class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      
       int count=0;
      vector<int>prefixSum(nums.size());
      prefixSum[0]=nums[0];
      for(int i=1;i<nums.size();i++){
         prefixSum[i]=prefixSum[i-1]+nums[i];

      }
 unordered_map<int,int>mp;
 for(int j=0;j< nums.size();j++){
    if(prefixSum[j]==goal){
        count++;
    }
    int val=prefixSum[j]-goal;
    if(mp.find(val)!=mp.end()){
        count+=mp[val];
    }
    mp[prefixSum[j]]++;
 }
 return count;

    }
};