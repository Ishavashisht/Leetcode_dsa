class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long long count2 = 6; // 2-color (ABA)
        long long count3 = 6; // 3-color (ABC)

        for (int i = 2; i <= n; i++) {
            long long newCount2 = (count2 * 3 + count3 * 2) % MOD;
            long long newCount3 = (count2 * 2 + count3 * 2) % MOD;
            count2 = newCount2;
            count3 = newCount3;
        }

        return (count2 + count3) % MOD;
    }
};
