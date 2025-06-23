class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int maxRadius = 0;

       
        for (int house : houses) {
            int minDist = findMinDist(house, heaters);
            maxRadius = max(maxRadius, minDist);
        }

        return maxRadius;
    }

private:
    int findMinDist(int house, const vector<int>& heaters) {
       
        auto it = lower_bound(heaters.begin(), heaters.end(), house);
        int dist1 = (it == heaters.end()) ? INT_MAX : abs(*it - house);
        int dist2 = (it == heaters.begin()) ? INT_MAX : abs(*(it - 1) - house);

        return min(dist1, dist2);
    }
};