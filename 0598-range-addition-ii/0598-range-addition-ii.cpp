class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_a=m;
        int min_b=n;
        for(auto &update:ops){
        min_a=min(min_a,update[0]);
        min_b=min(min_b,update[1]);

        }return min_a*min_b;
    }
};