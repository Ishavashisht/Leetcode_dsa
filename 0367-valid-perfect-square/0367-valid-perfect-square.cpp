class Solution {
public:
    bool isPerfectSquare(int num) {
         double sqrtNum = sqrt(num);
    return sqrtNum == floor(sqrtNum);
    }
};