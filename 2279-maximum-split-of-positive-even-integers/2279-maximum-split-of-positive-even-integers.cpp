class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
       if (finalSum % 2 != 0) return {};

    vector<long long> result;
    long long currentEven = 2; // Start with the smallest even number

    while (finalSum >= currentEven) {
        result.push_back(currentEven);
        finalSum -= currentEven;
        currentEven += 2; // Move to the next even number
    }

    // Add any remaining sum to the last element to balance
    if (!result.empty()) {
        result.back() += finalSum;
    }

    return result;
    }
};