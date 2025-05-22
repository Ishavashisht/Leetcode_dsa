class Solution {
public:
// Helper function to check if `cuboid1` can be placed on `cuboid2`
bool canPlace(vector<int>& cuboid1, vector<int>& cuboid2) {
    return cuboid1[0] <= cuboid2[0] &&
           cuboid1[1] <= cuboid2[1] &&
           cuboid1[2] <= cuboid2[2];
}

// Recursive function to calculate maximum height
int solve(vector<vector<int>>& cuboids, int curr, int prev, int n,vector<vector<int>>&dp) {
    // Base case: If no more cuboids left
    if (curr == n) return 0;
if(dp[curr][prev+1]!=-1){
    return dp[curr][prev+1];
}
    // Option 1: Skip the current cuboid
    int skip = solve(cuboids, curr + 1, prev, n,dp);

    // Option 2: Include the current cuboid (if possible)
    int include = 0;
    if (prev == -1 || canPlace(cuboids[curr], cuboids[prev])) {
        include = cuboids[curr][2] + solve(cuboids, curr + 1, curr, n,dp);
    }

    // Return the maximum of both options
    return dp[curr][prev+1]=max(skip, include);
}

// Main function
int maxHeight(vector<vector<int>>& cuboids) {
    int n = cuboids.size();
vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    // Step 1: Sort dimensions of each cuboid
    for (auto& cuboid : cuboids) {
        sort(cuboid.begin(), cuboid.end());
    }

    sort(cuboids.begin(), cuboids.end(), [](vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] > b[0];
        if (a[1] != b[1]) return a[1] > b[1];
        return a[2] > b[2];
    });
    // Step 3: Call the recursive function
    return solve(cuboids, 0, -1, n,dp);
}
};