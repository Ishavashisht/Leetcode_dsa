class Solution {
public:
     vector<int>prefix;
    int subarraySum(vector<int>& nums, int k) {
        prefix.resize(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
       
        int count=0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int sum = prefix[j] - (i > 0 ? prefix[i - 1] : 0);
                if(sum==k){
                    count++;
                }
            }
        }
return count;
    }

};