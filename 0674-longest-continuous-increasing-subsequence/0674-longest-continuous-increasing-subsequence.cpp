class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int currLen=1,maxLen=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                currLen++;
            
            if(currLen>maxLen){
                maxLen=currLen;
            }
            }
           else{
            //reset
            currLen=1;
           }
            // if(currLen>maxLen){
            //     maxLen=currLen;
            //     start=i;
            // }

        }
        return maxLen;
    }


};