// Problem: Distribute Candies Among Children III (LeetCode 2927)
// Approach: Combinatorics + Principle of Inclusion-Exclusion (PIE)

class Solution {
 public:
  long long distributeCandies(int n, int limit) {
    const int limitPlusOne = limit + 1;

    // Count of ways where one, two or all three children exceed the limit
    long oneExceeds = ways(n - limitPlusOne);
    long twoExceed = ways(n - 2 * limitPlusOne);
    long threeExceed = ways(n - 3 * limitPlusOne);

    // Apply Inclusion-Exclusion Principle
    return ways(n) - 3 * oneExceeds + 3 * twoExceed - threeExceed;
  }

 private:
  // Returns the number of ways to distribute n candies among 3 children
  long ways(int n) {
    if (n < 0) return 0;

    // Using "stars and bars" method: C(n + k - 1, k - 1) for k=3
    return nCk(n + 2, 2);
  }

  // Computes n choose k (nCk) using a multiplicative formula
  long nCk(int n, int k) {
    long res = 1;
    for (int i = 1; i <= k; ++i) {
      res = res * (n - i + 1) / i;
    }
    return res;
  }
};
