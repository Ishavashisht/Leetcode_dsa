class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int n=nums.size();
       vector<int>prefix(n);
       prefix[0]=nums[0];
       for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
       } 
       unordered_map<int,int>mp;
       int count=0;
       for(int j=0;j<n;j++)
{
if(prefix[j]==goal){
    count++;
}
int val=prefix[j]-goal;
if(mp.find(val)!=mp.end()){
    count+=mp[val];
}
mp[prefix[j]]++;
}    
return count;
}
};