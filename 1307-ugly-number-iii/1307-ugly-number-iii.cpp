#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // Helper function to compute gcd
        auto gcd = [](long long x, long long y) {
            while (y != 0) {
                long long temp = y;
                y = x % y;
                x = temp;
            }
            return x;
        };
        
        // Helper function to compute lcm
        auto lcm = [&](long long x, long long y) {
            return (x / gcd(x, y)) * y;  // Avoid overflow
        };
        
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(a, bc);
        
        long long low = 1, high = 2e9;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            
            // Count numbers <= mid divisible by a, b, or c
            long long count = mid / a + mid / b + mid / c
                            - mid / ab - mid / bc - mid / ac
                            + mid / abc;
            
            if (count < n) {
                low = mid + 1; // Increase search space
            } else {
                high = mid; // Narrow down search space
            }
        }
        
        return (int)low;
    }
};
