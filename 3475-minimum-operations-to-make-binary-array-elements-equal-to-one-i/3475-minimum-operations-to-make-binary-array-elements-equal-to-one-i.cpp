class Solution {
public:
    int minOperations(vector<int>& nums) {
        deque<int>dq;
        int count=0;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty()&& i>dq.front()+2){
                dq.pop_front();
            }
            if((nums[i]+dq.size())%2==0){
                if(i+2 >=nums.size()){
                    return -1;
                }
                count++;
                dq.push_back(i);
            }
        }
        return count;
    }
};