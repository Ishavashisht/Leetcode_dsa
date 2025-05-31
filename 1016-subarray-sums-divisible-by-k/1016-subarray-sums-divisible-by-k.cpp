class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];

        }
        unordered_map<int,int>mp;
        int count=0;
        for(int j=0;j<nums.size();j++){
        if(prefix[j]%k==0){
            count++;
        }
        int val=prefix[j]%k;
        if(val<0)val+=k;
        if(mp.find(val)!=mp.end()){
            count+=mp[val];
        }
        mp[val]++;
        }
        return count;
    }
};