

class Solution {
public:
    vector<int> prefixSums;
    vector<vector<int>> rects;

    Solution(vector<vector<int>>& rects) : rects(rects) {
        srand(time(0));
        int sum = 0;
        prefixSums.reserve(rects.size());
        for (const auto& rect : rects) {
            int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
            int points = (x - a + 1) * (y - b + 1);
            sum += points;
            prefixSums.push_back(sum);
        }
    }
    
    int findRectIndex(int k) { 
        return lower_bound(prefixSums.begin(), prefixSums.end(), k) - prefixSums.begin(); 
    }
    
    vector<int> pick() {  
        int totalPoints = prefixSums.back();
        int k = (rand() % totalPoints) + 1;
        int rectIdx = findRectIndex(k);
        const auto& rect = rects[rectIdx];
        int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
        int width = x - a + 1;
        int prevSum = rectIdx == 0 ? 0 : prefixSums[rectIdx - 1];
        int offset = k - prevSum - 1;
        int dx = offset % width;
        int dy = offset / width;
        return {a + dx, b + dy};
    }
};