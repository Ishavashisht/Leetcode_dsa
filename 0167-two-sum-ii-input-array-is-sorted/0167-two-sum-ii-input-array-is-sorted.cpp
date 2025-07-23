class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n=numbers.size();
        int i=0,j=n-1;
        int currSum=0;
        while(i<j){
            currSum=numbers[i]+numbers[j];
                 if(currSum==target){   
        return {i+1,j+1};
    }
            else if(currSum>target){
              j--;
            }
            else{
                i++;
            }
        } 
       return {-1,-1};
        }
};