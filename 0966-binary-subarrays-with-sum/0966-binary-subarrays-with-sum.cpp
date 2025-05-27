class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int n=nums.size();
       vector<int>prefixSum(n,0);
       prefixSum[0]=nums[0];
       for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
       } 
       unordered_map<int,int>mp;
       int count=0;
       for(int j=0;j<n;j++){
if(prefixSum[j]==goal){
    count++;
}

int val=prefixSum[j]-goal;
if(mp.find(val)!=mp.end()){
    count+=mp[val];
}
if(mp.find(prefixSum[j])==mp.end()){
    mp[prefixSum[j]]=0;
}
mp[prefixSum[j]]++;
       }
       return count;
    }
};