class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467
        return n>=1 && (1162261467 % n==0);
    }
};