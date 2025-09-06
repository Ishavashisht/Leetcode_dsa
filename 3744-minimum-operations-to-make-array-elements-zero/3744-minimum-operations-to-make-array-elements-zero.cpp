class Solution {
public:
 long long prefixSteps(long long n) {
        if (n <= 0) return 0;
        long long res = 0;
        long long power = 1; // 4^0
        int step = 1;
        while (power <= n) {
            long long nextPower = power * 4; // 4^(k+1)
            long long right = min(n, nextPower - 1);
            long long len = right - power + 1;
            res += len * 1LL * step;
            power = nextPower;
            step++;
        }
        return res;
    }

    long long minOperations(vector<vector<int>>& queries) {
       long long ans = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long totalSteps = prefixSteps(r) - prefixSteps(l - 1);
            ans += (totalSteps + 1) / 2; // ceil division
        }
        return ans;
    }
};