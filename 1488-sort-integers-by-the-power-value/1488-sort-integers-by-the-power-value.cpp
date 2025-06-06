class Solution {
public:
unordered_map<int, int> powerMemo;

// Recursive function to compute power with memoization
int getPower(int x) {
    if (x == 1) return 0;
    if (powerMemo.count(x)) return powerMemo[x];

    int next;
    if (x % 2 == 0) {
        next = x / 2;
    } else {
        next = 3 * x + 1;
    }

    powerMemo[x] = 1 + getPower(next);
    return powerMemo[x];
}
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int>powerMemo;
        vector<pair<int,int>>powerList;
        for(int i=lo;i<=hi;i++){
            int powerVal=getPower(i);
            powerList.push_back({i, powerVal});
        }
                sort(powerList.begin(), powerList.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;

        });
         return powerList[k - 1].first;


    }
};