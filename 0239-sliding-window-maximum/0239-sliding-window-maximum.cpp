class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> result;
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < nums.size(); ++i) {
    
        maxHeap.push({nums[i], i});

       
        while (maxHeap.top().second <= i - k) {
            maxHeap.pop();
        }

        
        if (i >= k - 1) {
            result.push_back(maxHeap.top().first);
        }
    }

    return result;
}
};