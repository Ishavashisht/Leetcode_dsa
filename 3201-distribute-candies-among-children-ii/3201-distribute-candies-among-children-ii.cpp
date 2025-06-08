class Solution {
public:
typedef long long ll;
ll comb(ll n) {
    if (n < 0) return 0;
    return n * (n - 1) / 2;
}
    long long distributeCandies(int n, int limit) {
          ll total = comb(n + 2);

    total -= 3 * comb(n - (limit + 1) + 2);
    total += 3 * comb(n - 2 * (limit + 1) + 2);
    total -= comb(n - 3 * (limit + 1) + 2);

    return total;
    }
};