class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=nums.size()-1;
        int pos=nums.size()-1;
        vector<int>res(n);
        while(left<=right){
            int leftSq=nums[left]*nums[left];
            int rightSq=nums[right]*nums[right];
            if(leftSq>rightSq){
           res[pos]=leftSq;
           left++;
            }
            else{
                res[pos]=rightSq;
                right--;
            }
            pos--;
        }
        return res;
    }
};