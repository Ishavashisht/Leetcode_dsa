class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<long long,long long>freq;
        long long prefix=0,res=0;
    freq[0]=1;
        for(int num:nums){
            prefix^=num;
            if(freq.count(prefix)){
                res+=freq[prefix];
            }
            freq[prefix]++;
        }
        return res;
    }
};