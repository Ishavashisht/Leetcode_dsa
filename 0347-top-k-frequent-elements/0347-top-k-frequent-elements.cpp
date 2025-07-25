class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;

        }
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
          for(auto&[num,f]:mp){
            minHeap.push({f,num});
            if(minHeap.size()>k){
                minHeap.pop();
            }
          }
          vector<int>res;
          while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
          }
          return res;
    }
};