class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        int score=0;
        int maxscore=0;
        unordered_set<int>seen;
        while(j<nums.size()){
            if(seen.find(nums[j])==seen.end()){
              //unique ele
              seen.insert(nums[j]);
              score+=nums[j];
              maxscore=max(maxscore,score);
              j++;
            }
            else{
                //duplicate found --bhar niklao
                seen.erase(nums[i]);
                score-=nums[i];
                i++;
            }
        }
        return maxscore;
    }
};